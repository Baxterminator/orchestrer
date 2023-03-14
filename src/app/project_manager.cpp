/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project managing part of the main window
 *========================================================================**/
#include "app/action_result.hpp"
#include <QFileDialog>
#include <app/project_manager.hpp>
#include <iostream>
#include <qfiledialog.h>
#include <sstream>

namespace img_orchestrer::app {

/// @brief Show the user a QFileDialog to choose for a file
/// @return true if a file was selected, false in other cases
bool ProjectManager::choose_file_path(bool exist) {
  if (project == nullptr)
    make_void_project();

  QFileDialog file_diag;
  file_diag.setFileMode(exist ? QFileDialog::ExistingFile
                              : QFileDialog::AnyFile);
  file_diag.setNameFilter("Image Orchestra Project (.orch)");
  if (file_diag.exec()) {
    auto list_files = file_diag.selectedFiles();
    if (list_files.size() > 0) {
      project->file_path = list_files.at(0).toStdString();
      return true;
    }
    return false;
  }
  return false;
}

void ProjectManager::make_void_project() {
  if (project != nullptr) {
    // TODO: closing project / saving project
  }

  project = std::make_unique<project::ProjectData>();
  project->name = "New Project";
  std::cout << "New project" << std::endl;
}

/// @brief Save the project to the corresponding file
results::Save ProjectManager::save_project() {
  if (project == nullptr)
    return results::Save::NO_PROJECT;

  if (std::empty(project->file_path)) {
    choose_file_path(false);
    if (project->file_path.substr(project->file_path.length() - EXT_LENGTH) !=
        EXTENSION) {
      project->file_path += EXTENSION;
    }
  }
  return (project->to_file()) ? results::Save::SAVED
                              : results::Save::SAVE_FAILED;
}

/// @brief LOad a project from an XML project file
results::Load ProjectManager::load_project() {
  if (project != nullptr) {
    // TODO: Save existing project ?
  }

  if (!choose_file_path())
    return results::Load::NO_SELECTION;

  return (project->from_file()) ? results::Load::LOADED
                                : results::Load::LOAD_FAILED;
}

void ProjectManager::print_project() {
  std::cout << *(project.get()) << std::endl;
}

} // namespace img_orchestrer::app