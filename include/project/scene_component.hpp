/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Component to be used in the scene
 *========================================================================**/
#ifndef IMG_ORCH_SCENE_COMP
#define IMG_ORCH_SCENE_COMP

#include <ostream>
#include <string>

namespace img_orchestrer::project {

class SceneComponent {
protected:
  static int obj_number;
  std::string obj_name;

  SceneComponent() {
    if (!obj_number)
      obj_number = 1;
    obj_name = "component_" + std::to_string(obj_number);
  }

public:
  friend std::ostream &operator<<(std::ostream &, const SceneComponent &);
};

} // namespace img_orchestrer::project

#endif