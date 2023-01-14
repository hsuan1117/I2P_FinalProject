#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "utility.h"
#include "shared.h"
#include "game.h"

typedef struct {
    RecArea body;
    bool hovered;
    const char *text;
    ALLEGRO_COLOR color;
    ALLEGRO_COLOR hovered_color;
    ALLEGRO_FONT *font;
    int rounded;
    int thickness;

    func_ptr onclick;
    func_ptr_register event_register;
} TextButton;

TextButton textButton_create(float x, float y, float w, float h, const char* text, ALLEGRO_COLOR color);
void drawTextButton(TextButton button);
void textButtonHover(TextButton *button, int x, int y);
void ruru_register_text_button(TextButton *textButton, ALLEGRO_EVENT event);

#endif
