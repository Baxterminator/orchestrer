/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Factory to make components instance from a string type
 *========================================================================**/
#include "project/components/flux_component.hpp"
#include "project/components/scene_component.hpp"
#include <algorithm>
#include <cctype>
#include <project/components/component_factory.hpp>

namespace img_orchestrer::project::components {

bool same_str(const std::string &stringA, const std::string &stringB) {
  return std::equal(
      stringA.begin(), stringA.end(), stringB.begin(), stringB.end(),
      [](char a, char b) { return std::tolower(a) == std::tolower(b); });
}

SceneComponent *ComponentFactory::make_component(const pugi::xml_node &node) {
  if (same_str(node.name(), "flux"))
    return new FluxComponent(node);
  return nullptr;
}

} // namespace img_orchestrer::project::components