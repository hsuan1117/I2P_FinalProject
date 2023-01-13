#include "scene_game_over.h"
#include "scene_menu.h"
#include "shared.h"

static int user_score = 0;

static void draw(void) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(menuFont,
                 al_map_rgb(255, 255, 255),
                 400,
                 400,
                 ALLEGRO_ALIGN_CENTER, "Die QQQQQ");
    al_draw_textf(menuFont,
                 al_map_rgb(255, 255, 255),
                 400,
                 435,
                 ALLEGRO_ALIGN_CENTER, "You got %d points", user_score);
    al_draw_text(menuFont,
                 al_map_rgb(255, 255, 255),
                 400,
                 650,
                 ALLEGRO_ALIGN_CENTER, "Press \"Enter\" to back to menu");
}

static void on_key_down(int key) {
    if (key == ALLEGRO_KEY_ENTER)
        game_change_scene(scene_menu_create());
}

Scene scene_game_over_create(int score) {
    Scene scene;
    memset(&scene, 0, sizeof(Scene));
    scene.name = "game_over";
    scene.draw = &draw;
    // TODO: Register more event callback functions such as keyboard, mouse, ...
    scene.on_key_down = on_key_down;

    user_score =  score;

    game_log("game_over scene created");
    return scene;
}