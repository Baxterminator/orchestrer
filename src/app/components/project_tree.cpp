/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  14/03/2023
 * @description    :  UI Project Tree
 *========================================================================**/
#include <app/components/project_tree.hpp>
#include <memory>
#include <qtreewidget.h>

namespace img_orchestrer::app::components {

ProjectTree::ProjectTree(const std::shared_ptr<Ui::ImageOrchestrer> UI)
    : ui(UI) {
  header_item = new QTreeWidgetItem(QTreeWidgetItem::Type);
  header_item->setText(0, "No Project");
  UI->project_tree->setHeaderItem(header_item);
  scenes_items.resize(0);
}

ProjectTree::~ProjectTree() {}

/// @brief Reload the tree view according to the project description
/// @param force_clear whether to force a complete clear rather than which item
/// to clear
void ProjectTree::reload_tree(std::shared_ptr<project::ProjectData> project,
                              [[maybe_unused]] bool force_clear) {
  //* Getting UI
  if (ui.expired())
    return;
  auto ui_shared = ui.lock();

  //* Clearing previous tree
  ui_shared->project_tree->clear();
  scenes_items.resize(0);

  //* Updating UI
  header_item->setText(0, project->name.c_str());
  for (auto &[scene_id, scene_desc] : project->scenes) {
    auto sc_item =
        new QTreeWidgetItem(ui_shared->project_tree, QTreeWidgetItem::Type);
    sc_item->setText(0, scene_id.c_str());
    scenes_items.push_back(sc_item);
  }
}

} // namespace img_orchestrer::app::components