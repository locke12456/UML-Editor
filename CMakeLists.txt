cmake_minimum_required(VERSION 2.8.11)

# Default configuration values. These must be before the project command or
# they won't work in Windows.
# If no build type is specified, default to "Release"
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING
      "None Debug Release RelWithDebInfo MinSizeRel"
      FORCE)
endif()
# Install to "dist" directory in Windows for testing and as a staging directory
# for the installer.
if (WIN32 AND NOT CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX dist CACHE STRING "Install path prefix.")
endif()

project(UMLEditor)
set(PROJECT_LONGNAME "UML Editor")
set(PROJECT_VERSION "1.0.0")

# Global CMake options
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# Configure Qt
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

if (NOT MSVC)
  # Enable the C++11 standard
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++11)
endif()
file(GLOB_RECURSE UI_FILES ui/*.ui)
file(GLOB_RECURSE CODE_FILES src/*.cpp)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})
qt5_add_resources(RESOURCE_FILES resource/umleditor.qrc)

# Windows application icon
#if (WIN32)
#  set(WINDOWS_RES_FILE ${CMAKE_CURRENT_BINARY_DIR}/resources.obj)
#  if (MSVC)
#    add_custom_command(OUTPUT ${WINDOWS_RES_FILE}
#      COMMAND rc.exe /fo ${WINDOWS_RES_FILE} resources.rc
#      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/win
#    )
#  else()
#    add_custom_command(OUTPUT ${WINDOWS_RES_FILE}
#      COMMAND windres.exe resources.rc ${WINDOWS_RES_FILE}
#      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/win
#    )
#  endif()
#endif()
INCLUDE_DIRECTORIES(inc)
add_executable(${CMAKE_PROJECT_NAME} WIN32
  ${UI_HEADERS}
  ${CODE_FILES}
  ${RESOURCE_FILES}
  ${WINDOWS_RES_FILE}
)
target_link_libraries(${CMAKE_PROJECT_NAME}
  Qt5::Widgets
)

if (UNIX)
  install(TARGETS ${CMAKE_PROJECT_NAME}
          RUNTIME DESTINATION bin)
elseif (WIN32)
  install(TARGETS ${CMAKE_PROJECT_NAME}
          DESTINATION .)
endif()