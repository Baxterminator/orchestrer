cmake_minimum_required(VERSION 3.5)
project(image_orchestrer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c++17)
endif()

find_package(Qt5 COMPONENTS Core Widgets WebKit WebKitWidgets REQUIRED)

# =================================================================
#                        QT 5 UI Generator
# =================================================================
set(CMAKE_INCLUDE_CURRENT_DIR "YES")
set(CMAKE_AUTOUIC_SEARCH_PATHS "resources/ui")
set(CMAKE_AUTOMOC "YES")
set(CMAKE_AUTOUIC "YES")
# =================================================================
#                              OUTPUT
# =================================================================

add_library(project_data
  src/project/project_data.cpp
  src/project/components/scene_component.cpp
  src/project/components/component_factory.cpp
  src/project/components/flux_component.cpp
)
target_include_directories(project_data PRIVATE include)

add_library(pugixml
  src/pugixml.cpp)
target_include_directories(pugixml PRIVATE include)

add_executable(img_orchestrer 
  src/app/orchestrer_window.cpp
  src/app/project_manager.cpp
  src/app/components/project_tree.cpp
  src/main_app.cpp 
)
target_include_directories(img_orchestrer PRIVATE include)
target_link_libraries(img_orchestrer Qt5::Core Qt5::Widgets Qt5::WebKit Qt5::WebKitWidgets project_data pugixml)