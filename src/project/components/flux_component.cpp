/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Flux component (video flux from an outside source)
 *========================================================================**/
#include "project/components/flux_component.hpp"
#include "project/components/scene_component.hpp"
#include <string>

namespace img_orchestrer::project::components {

FluxComponent::FluxComponent(const pugi::xml_node &node)
    : SceneComponent(node.attribute("name").value()) {
  obj_type = "Flux";
  load_from_xml(node);
}

/*================================ XML Loading ==============================*/

void FluxComponent::load_from_xml(const pugi::xml_node &node) {
  source = node.attribute("src").value();
}

std::ostream &FluxComponent::toStr(std::ostream &os) const {
  os << "<Flux name=\"" << obj_name << "\" src=\"" << source << "\"/>";
  return os;
}

} // namespace img_orchestrer::project::components