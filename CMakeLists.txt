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
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE) # Build SDL2 as a static library
FetchContent_MakeAvailable(sdl)

# Fetch and configure SDL_image
FetchContent_Declare(
  sdl_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG SDL2
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE) # Build SDL_image as a static library

# Disable formats with missing dependencies (optional)
set(SDL2IMAGE_AVIF OFF CACHE BOOL "" FORCE)
set(SDL2IMAGE_TIFF OFF CACHE BOOL "" FORCE)
set(SDL2IMAGE_WEBP OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(sdl_image)

# Debugging: Check if SDL2_image targets exist
if (TARGET SDL2_image)
    message(STATUS "SDL2_image target found: SDL2_image")
else()
    message(WARNING "SDL2_image target NOT found!")
endif()

if (TARGET SDL2_image::SDL2_image)
    message(STATUS "SDL2_image::SDL2_image target found")
else()
    message(WARNING "SDL2_image::SDL2_image target NOT found!")
endif()

# Manually define SDL2_image::SDL2_image target if it doesn't exist
if (NOT TARGET SDL2_image::SDL2_image AND TARGET SDL2_image)
    add_library(SDL2_image::SDL2_image ALIAS SDL2_image)
    message(STATUS "Manually defined SDL2_image::SDL2_image target")
endif()

# Add your game source files
file(GLOB GAME_FILES src/*.cpp)

# Create your game executable
add_executable(game ${GAME_FILES})

# Link the SDL2 and SDL_image libraries to the game executable
target_link_libraries(game PRIVATE SDL2::SDL2 SDL2_image::SDL2_image)

# Include directories for SDL2 and SDL_image
target_include_directories(game PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Define SDL_STATIC if building statically
target_compile_definitions(game PRIVATE SDL_STATIC)