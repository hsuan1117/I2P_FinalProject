cmake_minimum_required(VERSION 3.24)
project(Allegro5Template)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)

pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_dialog-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)

add_executable(Allegro5Template "01. Create_Window.c")

target_include_directories(Allegro5Template PUBLIC ${ALLEGRO5_INCLUDE_DIRS})
target_compile_options(Allegro5Template PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
target_link_libraries(Allegro5Template ${ALLEGRO5_LIBRARIES})
target_link_directories(Allegro5Template PUBLIC ${ALLEGRO5_LIBRARY_DIRS})
