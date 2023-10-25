This is a demo library that show you how to create SHARED library in two mode and use them in your project

First, you can create a sub_directory like me to store your library, i call it <my_lib> as an example

In your <my_lib>, create a CMakeLists.txt and set up like this:

    1. Add your header file and cpp file with add_library(), my_lib is name of my library, SHARED keywork showed that you want to build this as SHARE LIBRARY
    
    add_library(my_lib SHARED
        src/calculator_lib.cpp
        include/calculator_lib.h
        include/calculator_lib_global.h
    )
    
    2. Add header file to my library, in this example, include is FOLDER contains header file
    target_include_directories(my_lib PUBLIC include)

    3. Add library that you want to link to your target library
    target_link_libraries(my_lib PRIVATE Qt${QT_VERSION_MAJOR}::Core)

    4. Install your target library into lib folder and export it into my_lib folder in build folder
    install(TARGETS my_lib EXPORT my_lib-export DESTINATION lib)

    5. Export INFOMATION about your library in to 
        -----> Find<your_lib>.cmake [MODULE MODE]
    export(EXPORT my_lib-export FILE Findmy_lib.cmake) # Create SomeLibConfig.cmake
        -----> <your_lib>-config.cmake || <your_lib>Config.cmake [CONFIG MODE]

    6. Finally package your library in to my_lib folder
    export(PACKAGE my_lib)

In your main directory, you just:
    add_subdirectory(my_lib)
to add your sub_directory.
