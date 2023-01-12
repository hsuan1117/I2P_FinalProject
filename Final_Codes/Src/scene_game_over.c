#include "scene_game_over.h"
#include "shared.h"

static void draw(void) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(menuFont,
                 al_map_rgb(255, 255, 255),
                 400,
                 400,
                 ALLEGRO_ALIGN_CENTER, "Die QQQQQ");
}

Scene scene_game_over_create(void) {
    Scene scene;
    memset(&scene, 0, sizeof(Scene));
    scene.name = "game_over";
    scene.draw = &draw;
    // TODO: Register more event callback functions such as keyboard, mouse, ...
    game_log("game_over scene created");
    return scene;
}