/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Component to be used in the scene
 *========================================================================**/
#include <project/scene_component.hpp>

namespace img_orchestrer::project {

std::ostream &operator<<(std::ostream &os, const SceneComponent &comp) {
  os << comp.obj_name;
  return os;
}
} // namespace img_orchestrer::project