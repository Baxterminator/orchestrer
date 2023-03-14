/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  14/03/2023
 * @description    :  UI Project Tree
 *========================================================================**/
#ifndef IMG_ORCH_PROJECT_TREE
#define IMG_ORCH_PROJECT_TREE

#include "project/project_data.hpp"
#include "ui_main_window.h"
#include <memory>
#include <qtreewidget.h>
#include <vector>

namespace img_orchestrer::app::components {

struct SceneItem {
  QTreeWidgetItem *item;
  std::vector<QTreeWidgetItem *> comp_items;
};

class ProjectTree {
private:
  std::weak_ptr<Ui::ImageOrchestrer> ui;
  QTreeWidgetItem *header_item;
  std::vector<SceneItem> scenes_items;

public:
  ProjectTree(const std::shared_ptr<Ui::ImageOrchestrer>);
  ~ProjectTree();
  void reload_tree(std::shared_ptr<project::ProjectData>, bool = false);
};

} // namespace img_orchestrer::app::components

#endif