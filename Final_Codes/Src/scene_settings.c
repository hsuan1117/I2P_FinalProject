// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu.h"
#include "shared.h"
#include "utility.h"
#include "../Lib/components/TextInput.h"
#include "../Lib/components/TextButton.h"
#include "../Lib/components/ProgressBar.h"
#include "../Lib/components/Select.h"

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */
int static volume = 10;
int static effect = 10;
static ALLEGRO_BITMAP *volume_bar[11] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static ALLEGRO_BITMAP *effect_bar[11] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
static TextInput input;
static ProgressBar progressBar;
static TextButton btn;
static Selector aSelector;
// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.

static void draw(void) {
    float marginLeft = 20;
    const float scale = 1.5;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(jfFont, al_map_rgb(255, 255, 255), 400, 10, ALLEGRO_ALIGN_CENTER, "設定");
    al_draw_text(jfFont, al_map_rgb(255, 255, 255), marginLeft, 70, ALLEGRO_ALIGN_LEFT, "背景音量");
    al_draw_text(faFont, al_map_rgb(255, 255, 255), marginLeft + 250, 70, ALLEGRO_ALIGN_LEFT, "\uF027");
    //al_draw_textf(jfFont, al_map_rgb(255, 255, 255), marginLeft + 510, 70, ALLEGRO_ALIGN_LEFT, "%d", volume);
    al_draw_text(faFont, al_map_rgb(255, 255, 255), marginLeft + 470, 70, ALLEGRO_ALIGN_LEFT, "\uF028");
    al_draw_text(jfFont, al_map_rgb(255, 255, 255), marginLeft, 110, ALLEGRO_ALIGN_LEFT, "音效音量");
    //al_draw_text(jfFont, al_map_rgb(255, 255, 255), marginLeft + 250, 110, ALLEGRO_ALIGN_LEFT, "－");
    al_draw_text(faFont, al_map_rgb(255, 255, 255), marginLeft + 250, 110, ALLEGRO_ALIGN_LEFT, "\uF027");
    // al_draw_textf(jfFont, al_map_rgb(255, 255, 255), marginLeft + 300, 110, ALLEGRO_ALIGN_LEFT, "%d", effect);
    al_draw_text(faFont, al_map_rgb(255, 255, 255), marginLeft + 470, 110, ALLEGRO_ALIGN_LEFT, "\uF028");

    al_draw_scaled_bitmap(
            volume_bar[volume],
            0, 0,
            102.0, 15.0,
            marginLeft + 300, 72,
            102.0 * scale, 15.0 * scale,
            0
    );
    al_draw_scaled_bitmap(
            effect_bar[effect],
            0, 0,
            102.0, 15.0,
            marginLeft + 300, 112,
            102.0 * scale, 15.0 * scale,
            0
    );

    al_draw_text(jfFont, al_map_rgb(255, 255, 255), 400, 700, ALLEGRO_ALIGN_CENTER,
                 "Press \"Left Arrow or Enter\" to save and back to menu");

    al_draw_text(jfFont, al_map_rgb(255, 255, 255), marginLeft, 150, ALLEGRO_ALIGN_LEFT, "用戶名稱");
    ruru_draw_text_input(input);
    drawTextButton(btn);
    draw_progress_bar(progressBar);
    drawSelector(&aSelector);
}

static void on_mouse_down(ALLEGRO_MOUSE_EVENT button, int x, int y) {
    if (x > 270 && x < 320 && y > 70 && y < 110) {
        if (volume > 0) {
            volume--;
        }
    } else if (x > 490 && x < 600 && y > 70 && y < 110) {
        if (volume < 10) {
            volume++;
        }
    } else if (x > 270 && x < 320 && y > 110 && y < 150) {
        if (effect > 0) {
            effect--;
        }
    } else if (x > 490 && x < 600 && y > 110 && y < 150) {
        if (effect < 10) {
            effect++;
        }
    }
}

static void on_key_down(int key) {
    if (key == ALLEGRO_KEY_LEFT || key == ALLEGRO_KEY_ENTER) {
        set_volume_effect(volume, effect);
        game_change_scene(scene_menu_create());
    }
}

static void btn_click() {
    printf("hi, this button clicked \n");
}

static const char *options[3] = {"test1", "test2", "test3"};
// The only function that is shared across files.
Scene scene_settings_create(void) {
    Scene scene;
    memset(&scene, 0, sizeof(Scene));
    scene.name = "Settings";
    scene.draw = &draw;
    // TODO: Register more event callback functions such as keyboard, mouse, ...
    scene.on_mouse_down = &on_mouse_down;
    scene.on_key_down = &on_key_down;

    scene.components = malloc(sizeof(TextInput) * 10);
    scene.component_types = malloc(10);
    scene.component_size = 0;

    for (int i = 0; i <= 10; i++) {
        char path[100];
        sprintf(path, "Assets/ProgressBar/%d.png", i);
        volume_bar[i] = load_bitmap(path);
        effect_bar[i] = load_bitmap(path);
    }
    volume = load_volume();
    effect = load_effect();

    input = ruru_create_textInput(20 + 250, 150, 300, 50, "test");
    input.maxLength = 5;
    btn = textButton_create(20 + 250, 230, 300, 50, "test", al_map_rgb(0, 0, 255));
    btn.onclick = &btn_click;
    progressBar = create_progress_bar(20 + 250, 290, 300, 5, 0.7, al_map_rgb(0, 0, 255));

    aSelector = selector_create(20 + 250, 400, 300, 200, options, 3, 0, al_map_rgb(0, 0, 255));

    int cnt = scene.component_size++;
    scene.component_types[cnt] = RURU_TEXT_INPUT;
    scene.components[cnt] = &input;
    cnt = scene.component_size++;
    scene.component_types[cnt] = RURU_TEXT_BUTTON;
    scene.components[cnt] = &btn;
    cnt = scene.component_size++;
    scene.component_types[cnt] = RURU_PROGRESS_BAR;
    scene.components[cnt] = &progressBar;
    cnt = scene.component_size++;
    scene.component_types[cnt] = SELECTOR;
    scene.components[cnt] = &aSelector;

    game_log("Settings scene created");
    return scene;
}

void destroy() {
    for (int i = 0; i <= 10; i++) {
        al_destroy_bitmap(volume_bar[i]);
    }
    for (int i = 0; i <= 10; i++) {
        al_destroy_bitmap(effect_bar[i]);
    }
}