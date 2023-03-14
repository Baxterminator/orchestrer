// UI
#include <app/orchestrer_window.hpp>
#include <memory>
#include <qapplication.h>

using img_orchestrer::app::OrchestrerWindow;
std::shared_ptr<QApplication> app;

int main(int argc, char **argv) {
  app = std::make_shared<QApplication>(argc, argv);

  // Run the main window
  {
    OrchestrerWindow win;
    win.show();

    app->exec();
  }

  app.reset();
}