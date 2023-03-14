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
#include <app/components/project_tree.hpp>
#include <iostream>
#include <memory>
#include <project/project_data.hpp>

namespace img_orchestrer::app {

class ProjectManager {
protected:
  std::shared_ptr<project::ProjectData> project;
  std::unique_ptr<components::ProjectTree> project_tree;

  bool choose_file_path(bool = true);

public:
  static constexpr auto EXTENSION{".orch"};
  static constexpr auto EXT_LENGTH{5};
  results::Save save_project();
  results::Load load_project();
  void make_void_project();
  void print_project();
};

} // namespace img_orchestrer::app

#endif