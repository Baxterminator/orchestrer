/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Flux component (video flux from an outside source)
 *========================================================================**/

#ifndef IMG_ORCH_FLUX_COMP
#define IMG_ORCH_FLUX_COMP

#include "project/components/scene_component.hpp"
#include <pugixml.hpp>
#include <string>

namespace img_orchestrer::project::components {

class FluxComponent : public SceneComponent {
private:
  void load_from_xml(const pugi::xml_node &);

protected:
  std::string source;
  virtual std::ostream &toStr(std::ostream &) const override;

public:
  FluxComponent(const pugi::xml_node &);
};

} // namespace img_orchestrer::project::components

#endif