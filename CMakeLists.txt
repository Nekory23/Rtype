cmake_minimum_required(VERSION 3.17)
project(CPP_RTYPE)
set(CMAKE_CXX_STANDARD 20)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if (UNIX)
    add_compile_options(-Wall -Wextra -g3)
else ()
    add_compile_options(/EHsc /W2)
endif ()

include(shared/shared.cmake)

include_directories(client/include)

add_executable(r-type_client
    client/src/Main.cpp
    client/src/GUI/Menu.cpp
    client/src/GUI/ClickableButton.cpp
    client/src/GUI/EntryButton.cpp
    client/src/GUI/Slider.cpp
    client/src/GUI/UpdateButton.cpp
    ${SHARED_SRC}
    ${SHARED_HDR}
)

include_directories(server/include)

add_executable(r-type_server
    server/include/Server.hpp
    server/src/Main.cpp
)

foreach(file IN LISTS SHARED_SRC + SHARED_HDR)
    get_filename_component(file_path "${file}" PATH)
    string(REPLACE "/" "\\" file_path_msvc "${file_path}")
    source_group("${file_path_msvc}" FILES "${file}")
endforeach()

target_link_libraries(r-type_client PRIVATE ${CONAN_LIBS})
target_include_directories(r-type_client PRIVATE ${CONAN_INCLUDE_DIRS})

target_link_libraries(r-type_server PRIVATE ${CONAN_LIBS})
target_include_directories(r-type_server PRIVATE ${CONAN_INCLUDE_DIRS})

get_target_property(RTYPE_EXE_PATH r-type_client CMAKE_RUNTIME_OUTPUT_DIRECTORY)
get_target_property(RTYPE_EXE_PATH r-type_server CMAKE_RUNTIME_OUTPUT_DIRECTORY)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT r-type_client)
