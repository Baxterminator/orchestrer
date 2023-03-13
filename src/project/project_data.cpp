/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project file definition
 *========================================================================**/
#include <ostream>
#include <project/project_data.hpp>

namespace img_orchestrer::project {

/// @brief Transform the scene into a string
std::ostream &operator<<(std::ostream &os, const Scene &scene) {
  os << "<scene name=\"" + scene.scene_id + "\">\n";
  for (auto const &p : scene.list)
    os << p << "\n";
  os << "</scene>\n";
  return os;
}

/// @brief Transform the project into a string
std::ostream &operator<<(std::ostream &os, const ProjectData &project) {
  os << "<project name=\"" + project.name + "\">\n";
  for (auto const &scene : project.scenes)
    os << scene << "\n";
  os << "</project>\n";
  return os;
}

} // namespace img_orchestrer::project