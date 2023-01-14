//
// Created by Hsuan on 2023/1/14.
//

#ifndef ALLEGRO5TEMPLATE_COMMON_H
#define ALLEGRO5TEMPLATE_COMMON_H

#include <allegro5/events.h>
#include <allegro5/allegro_font.h>

typedef void* component;

typedef void(*func_ptr)(void);

typedef void(*func_ptr_keyboard)(int keycode);

typedef void(*func_ptr_mouse)(int btn, int x, int y, int dz);

typedef enum {
    RURU_TEXT_INPUT,
    RURU_TEXT_BUTTON,
} InputType;

typedef struct {
    char *name;
    func_ptr initialize;
    func_ptr update;
    func_ptr draw;
    func_ptr destroy;
    func_ptr_keyboard on_key_down;
    func_ptr_keyboard on_key_up;
    func_ptr_mouse on_mouse_down;
    func_ptr_mouse on_mouse_move;
    func_ptr_mouse on_mouse_up;
    func_ptr_mouse on_mouse_scroll;

    component *components;
    InputType *component_types;
    int component_size;
} AllegroScene;

extern ALLEGRO_FONT *mainFont;
extern ALLEGRO_FONT *smallFont;

void register_scene_components(void *scene, ALLEGRO_EVENT event);
void component_init();
#endif //ALLEGRO5TEMPLATE_COMMON_H
