/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project managing part of the main window
 *========================================================================**/
#ifndef IMG_ORCH_PROJ_MANAGER
#define IMG_ORCH_PROJ_MANAGER

#include <app/action_result.hpp>
#include <iostream>
#include <memory>
#include <project/project_data.hpp>

namespace img_orchestrer::app {

class ProjectManager {
protected:
  std::unique_ptr<project::ProjectData> project;

  bool choose_file_path(bool = true);

public:
  results::Save save_project();
  results::Load load_project();
  void make_void_project();
};

} // namespace img_orchestrer::app

#endif