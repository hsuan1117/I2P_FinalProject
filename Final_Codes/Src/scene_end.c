#include "scene_end.h"

static void draw(void) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

Scene scene_end_create(void) {
    Scene scene;
    memset(&scene, 0, sizeof(Scene));
    scene.name = "End";
    scene.draw = &draw;

    // TODO: Register more event callback functions such as keyboard, mouse, ...

    game_log("End scene created");
    return scene;
}