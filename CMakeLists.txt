cmake_minimum_required(VERSION 3.25)
project(Game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch and configure SDL2
include(FetchContent)

FetchContent_Declare(
  sdl
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG SDL2
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(sdl)

# Fetch and configure SDL_image
FetchContent_Declare(
  sdl_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG SDL2
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(sdl_image)

if (TARGET SDL2_image::SDL2_image)
    message(STATUS "SDL2_image target found: SDL2_image::SDL2_image")
else()
    message(WARNING "SDL2_image target NOT found!")
endif()

# Add your game source files
file(GLOB GAME_FILES src/*.cpp)

# Create your game executable
add_executable(game ${GAME_FILES})

# Link the SDL2 and SDL_image libraries to the game executable
target_link_libraries(game PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

target_compile_definitions(game PRIVATE
    SDL_STATIC  # Define SDL_STATIC to ensure SDL2 is built/used statically
)