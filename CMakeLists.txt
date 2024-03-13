cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Lab4)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories("src/Applictaion/")

add_executable(Lab4 src/main.cpp
        src/Applictaion/App.cpp
        src/Applictaion/App.hpp
        src/Applictaion/Text.cpp
        src/Applictaion/Text.hpp
)
target_link_libraries(Lab4 PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
target_compile_features(Lab4 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET Lab4
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Lab4>
        VERBATIM)
endif()

install(TARGETS Lab4)