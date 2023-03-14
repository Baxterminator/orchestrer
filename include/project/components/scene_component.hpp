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

#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

namespace img_orchestrer::project::components {

class SceneComponent {
protected:
  std::string obj_name;
  std::string obj_type = "SceneComponent";

  SceneComponent(const std::string &name = "") {
    if (!name.length()) {
      static int obj_number = 1;
      obj_name = "component_" + std::to_string(obj_number++);
    } else {
      obj_name = name;
    }
  }

  virtual std::ostream &toStr(std::ostream &) const;

public:
  friend std::ostream &operator<<(std::ostream &, const SceneComponent &);
  inline std::string type() { return obj_type; }
  inline std::string name() { return obj_name; }
};

} // namespace img_orchestrer::project::components

#endif