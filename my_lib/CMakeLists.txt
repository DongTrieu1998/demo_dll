find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(my_lib SHARED
    src/calculator_lib.cpp
    include/calculator_lib.h
    include/calculator_lib_global.h
)

target_include_directories(my_lib PUBLIC include)

#target_include_directories( my_lib PUBLIC
#$<INSTALL_INTERFACE:include>
#$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(my_lib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

#install(FILES
#    ${CMAKE_CURRENT_SOURCE_DIR}/include/calculator_lib.h
#    ${CMAKE_CURRENT_SOURCE_DIR}/include/calculator_lib_global.h
#    DESTINATION
#    ${CMAKE_INSTALL_PREFIX}/include/my_lib)

#install(TARGETS my_lib EXPORT my_export DESTINATION bin)

#install(EXPORT my_export FILE my_lib-config.cmake DESTINATION bin)

install(TARGETS my_lib EXPORT my_lib-export DESTINATION lib)
export(EXPORT my_lib-export FILE Findmy_lib.cmake) # Create SomeLibConfig.cmake
export(PACKAGE my_lib)

message(bin)
