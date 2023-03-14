/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Component to be used in the scene
 *========================================================================**/
#include <ostream>
#include <project/components/scene_component.hpp>

namespace img_orchestrer::project::components {

std::ostream &SceneComponent::toStr(std::ostream &os) const {
  os << "<SceneComponent name=\"" << obj_name << "\">";
  return os;
}

std::ostream &operator<<(std::ostream &os, const SceneComponent &comp) {
  return comp.toStr(os);
}
} // namespace img_orchestrer::project::components