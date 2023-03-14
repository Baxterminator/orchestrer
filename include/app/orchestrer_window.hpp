/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Main Window wrapper
 *========================================================================**/

#ifndef IMG_ORCH_MAIN_WINDOW
#define IMG_ORCH_MAIN_WINDOW

#include <app/base_gui.hpp>
#include <app/project_manager.hpp>
#include <memory>
#include <project/project_data.hpp>
#include <qmainwindow.h>
#include <ui_main_window.h>

namespace img_orchestrer::app {

class OrchestrerWindow : public base::BaseGUI<Ui::ImageOrchestrer, QMainWindow>,
                         public ProjectManager {

public:
  OrchestrerWindow();
  void setup_internal_callbacks() override;
};

} // namespace img_orchestrer::app

#endif