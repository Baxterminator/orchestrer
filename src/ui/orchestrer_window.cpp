/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Main Window wrapper
 *========================================================================**/
#include <ui/orchestrer_window.hpp>
#include <ui_main_window.h>

namespace img_orchestrer::ui {

OrchestrerWindow::OrchestrerWindow()
    : base::BaseGUI<Ui::ImageOrchestrer, QMainWindow>() {
  setup_ui();
  statusBar()->showMessage("Load a project file (File > Load project )");
}

} // namespace img_orchestrer::ui