/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project managing part of the main window
 *========================================================================**/
#include "app/action_result.hpp"
#include <app/project_manager.hpp>

namespace img_orchestrer::app {

/// @brief Save the project to the corresponding file
results::Save ProjectManager::save_project() {
  if (std::empty(project->file_path)) {
    project->file_path = "./project.xml";
  }
  return (project->to_file()) ? results::Save::SAVED
                              : results::Save::SAVE_FAILED;
}

} // namespace img_orchestrer::app