/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :
 * @createdOn      :  13/03/2023
 * @description    :  Main Window wrapper
 *========================================================================**/

#ifndef IMG_ORCH_MAIN_WINDOW
#define IMG_ORCH_MAIN_WINDOW

#include <qmainwindow.h>
#include <ui/base_gui.hpp>
#include <ui_main_window.h>

namespace img_orchestrer::ui {

class OrchestrerWindow
    : public base::BaseGUI<Ui::ImageOrchestrer, QMainWindow> {
public:
  void setup_internal_callbacks() override{};
};

} // namespace img_orchestrer::ui

#endif