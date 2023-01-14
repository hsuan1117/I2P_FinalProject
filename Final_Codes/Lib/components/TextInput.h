#ifndef ALLEGRO5TEMPLATE_TEXTINPUT_H
#define ALLEGRO5TEMPLATE_TEXTINPUT_H

#include "utility.h"
#include "common.h"

typedef void(*func_ptr_register)(component *component, ALLEGRO_EVENT event);

typedef struct TextInput {
    RecArea body;
    char *value;
    bool isFocus;
    int maxLength;
    char *errorMessage;

    func_ptr_register event_register;
} TextInput;

TextInput ruru_create_textInput(float x, float y, float w, float h, char *value);
void ruru_draw_text_input(TextInput textInput);
void ruru_register_text_input(TextInput *textInput, ALLEGRO_EVENT event);

#endif //ALLEGRO5TEMPLATE_TEXTINPUT_H