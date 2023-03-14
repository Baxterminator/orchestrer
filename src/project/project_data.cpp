/**========================================================================
 * ?                                ABOUT
 * @author         :  Meltwin
 * @email          :  geoffrey.cote@centraliens-nantes.org
 * @repo           :  https://github.com/Baxterminator/orchestrer
 * @createdOn      :  13/03/2023
 * @description    :  Project file definition
 *========================================================================**/
#include <bits/types/FILE.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <project/project_data.hpp>
#include <pugixml.hpp>
#include <sstream>
#include <string.h>

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

/*================================ IO ==============================*/

/// @brief Save the project to an xml file
/// @return if the saving process was a success
bool ProjectData::to_file() {
  {
    std::ofstream handle{file_path, std::ios::trunc};

    std::stringstream ss;
    ss << *this;
    std::string out = ss.str();

    handle.write(out.c_str(), out.length());
    handle.close();
  }

  return true;
}

/// @brief Load an project from an XML file
/// @return if the loading process was a success
bool ProjectData::from_file() {
  /*================== OPENING FILE =================*/
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file(file_path.c_str());

  if (!result) {
    std::cout << "XML [" << file_path << "] parsed with errors, attr value: ["
              << doc.child("node").attribute("attr").value() << "]\n";
    std::cout << "Error description: " << result.description() << "\n";
    std::cout << "Error offset: " << result.offset << " (error at [..."
              << (file_path.c_str() + result.offset) << "]\n\n";
    return false;
  }

  /*================== EXTRACTING =================*/
  //* Project Node
  auto xml_project = doc.child("project");
  for (auto &att : xml_project.attributes()) {
    if (strcmp(att.name(), "name"))
      name = att.value();
  }

  return true;
}

} // namespace img_orchestrer::project