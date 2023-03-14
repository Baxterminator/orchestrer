/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Main Window wrapper
 *========================================================================**/
#include "app/project_manager.hpp"
#include <app/orchestrer_window.hpp>
#include <qaction.h>
#include <ui_main_window.h>

namespace img_orchestrer::app {

OrchestrerWindow::OrchestrerWindow()
    : base::BaseGUI<Ui::ImageOrchestrer, QMainWindow>(), ProjectManager() {
  setup_ui();
  statusBar()->showMessage("Load a project file (File > Load project )");
}

/*================================ GUI ==============================*/

void OrchestrerWindow::setup_internal_callbacks() {
  connect(get_ui()->new_project, &QAction::triggered,
          [&]() { this->make_void_project(); });
  connect(get_ui()->load_project, &QAction::triggered,
          [&]() { this->save_project(); });
  connect(get_ui()->save_project, &QAction::triggered,
          [&]() { this->save_project(); });
}

} // namespace img_orchestrer::app