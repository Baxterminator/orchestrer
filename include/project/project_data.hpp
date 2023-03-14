/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project file definition
 *========================================================================**/

#ifndef IMG_ORCH_PROJECT
#define IMG_ORCH_PROJECT

#include <ostream>
#include <project/scene_component.hpp>
#include <string>
#include <vector>

namespace img_orchestrer::project {

typedef std::vector<SceneComponent> ComponentList;

struct Scene {
  std::string scene_id;
  ComponentList list{};

  friend std::ostream &operator<<(std::ostream &os, const Scene &str);
};

typedef std::vector<Scene> SceneList;

struct ProjectData {
  std::string name, file_path;
  SceneList scenes{};

  bool to_file();
  bool from_file();

  friend std::ostream &operator<<(std::ostream &, const ProjectData &);
};

} // namespace img_orchestrer::project

#endif