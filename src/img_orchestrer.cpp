// UI
#include <memory>
#include <qapplication.h>
#include <ui/orchestrer_window.hpp>

using img_orchestrer::ui::OrchestrerWindow;
std::shared_ptr<QApplication> app;

int main(int argc, char **argv) {
  app = std::make_shared<QApplication>(argc, argv);

  OrchestrerWindow win;
  win.setup_ui();
  win.show();

  app->exec();
  app.reset();
}