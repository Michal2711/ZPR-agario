cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Set project name and version
project(Agario VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING
      "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" ON)

if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

# Find SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)
find_package((Box2D REQUIRED))

add_subdirectory(tests)
include_directories(${Boost_INCLUDE_DIRS})

# Compile executable
add_executable(Agario src/main.cpp src/Board.cpp src/Ball.cpp src/Game.cpp src/Player.cpp)

# Set include directory search paths
target_include_directories(Agario
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

# Set executable RPATH
set_target_properties(Agario
  PROPERTIES
      INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
  )

# Link executable to required SFML modules
target_link_libraries(Agario sfml-graphics sfml-audio)
target_link_libraries(Agario ${Boost_LIBRARIES})
target_link_libraries(your_target Box2D::Box2D)

# Set executable install location
install(TARGETS Agario DESTINATION bin)

# # Set install location for resources
# install(DIRECTORY content
#   DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
# )
