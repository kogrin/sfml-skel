cmake_minimum_required( VERSION 3.0 )

project( sfmleton
         LANGUAGES CXX
)

find_package( Threads REQUIRED )

set( BUILD_SHARED_LIBS FALSE )
add_subdirectory( git-submodules/sfml )

add_executable( sfmleton
    src/main.cpp
)

target_link_libraries( sfmleton
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-network
    sfml-system

    Threads::Threads
)

# do platform specific linking garbage
if( WIN32 )
    target_link_libraries( sfmleton
        ws2_32
    )

    # this ensures we link statically against everything
    target_link_options( sfmleton
        PUBLIC -static -static-libstdc++ -static-libgcc
    )

    # disable the CMD console window
    if( NOT DEBUG )
        target_link_options( sfmleton
            PUBLIC -mwindows
        )
    endif()
endif()

# set non-ancient C++ standard
set_target_properties( sfmleton
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
