cmake_minimum_required(VERSION 3.9)
project(wxSerialTerminal)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(wxWidgets REQUIRED)

include(${wxWidgets_USE_FILE})
add_library(Serial ceSerial.cpp ceSerial.h)

add_executable(wxserterm wxSerial.cpp)
add_dependencies(wxserterm Serial)
target_link_libraries(wxserterm Serial)
target_link_libraries(wxserterm ${wxWidgets_LIBRARIES})

