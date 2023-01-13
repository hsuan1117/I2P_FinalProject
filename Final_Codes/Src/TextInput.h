#ifndef ALLEGRO5TEMPLATE_TEXTINPUT_H
#define ALLEGRO5TEMPLATE_TEXTINPUT_H

#include "utility.h"

typedef struct TextInput {
    RecArea body;
    char *value;
    bool isFocus;
} TextInput;

TextInput ruru_create_textInput(float x, float y, float w, float h, char *value);
void ruru_draw_text_input(TextInput textInput);
void ruru_register_text_input_key(TextInput *textInput, int key);
void ruru_register_text_input_mouse(TextInput *textInput, int x, int y);

#endif //ALLEGRO5TEMPLATE_TEXTINPUT_H