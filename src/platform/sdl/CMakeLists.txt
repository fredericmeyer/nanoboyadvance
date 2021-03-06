set(SOURCES
    main.cpp
)

set(HEADERS
    device/audio_device.hpp
)

include(FindSDL2)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
set(GLEW_VERBOSE ON)
find_package(GLEW REQUIRED)

add_executable(NanoBoyAdvance ${SOURCES} ${HEADERS})
target_include_directories(NanoBoyAdvance PRIVATE ${SDL2_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS})
target_link_libraries(NanoBoyAdvance nba ${SDL2_LIBRARY} OpenGL::GL GLEW::GLEW)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resource/config.toml" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resource/keymap.toml" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_custom_target(CopyShaders ALL
  COMMAND ${CMAKE_COMMAND} -DSRCDIR=${CMAKE_CURRENT_SOURCE_DIR}/resource/shader
          -DDSTDIR=${CMAKE_CURRENT_BINARY_DIR}/shader
          -P ${CMAKE_CURRENT_SOURCE_DIR}/resource/shader.cmake
  COMMENT "Copy GLSL shaders to project build directory."
)
