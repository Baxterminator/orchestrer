/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Factory to make components instance from a string type
 *========================================================================**/

#ifndef IMG_ORCH_COMP_FACTORY
#define IMG_ORCH_COMP_FACTORY

#include <project/components/scene_component.hpp>
#include <pugixml.hpp>

namespace img_orchestrer::project::components {

struct ComponentFactory {
  static SceneComponent *make_component(const pugi::xml_node &);
};

} // namespace img_orchestrer::project::components

#endif