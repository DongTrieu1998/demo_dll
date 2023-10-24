find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(my_lib SHARED
src/calculator_lib.cpp
)

#target_include_directories(my_math PUBLIC include)
target_include_directories( my_lib PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(my_lib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/calculator_lib.h ${CMAKE_CURRENT_SOURCE_DIR}/include/calculator_lib_global.h  DESTINATION ${CMAKE_INSTALL_PREFIX}/include/my_lib)

install(TARGETS my_lib EXPORT my_export DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/my_lib)

install(EXPORT my_export FILE my_lib-config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/my_lib)

message(${CMAKE_INSTALL_PREFIX})
