#include "TextInput.h"
#include <allegro5/allegro_primitives.h>
#include "shared.h"

/**
 * @name 建立文字輸入框
 * @param x 輸入框左上角 x 座標
 * @param y 輸入框左上角 y 座標
 * @param w 輸入框寬度
 * @param h 輸入框高度
 * @param value 輸入框預設值
 * */
TextInput ruru_create_textInput(float x, float y, float w, float h, char *value) {
    TextInput textInput;
    memset(&textInput, 0, sizeof(TextInput));

    textInput.body.x = x;
    textInput.body.y = y;
    textInput.body.w = w;
    textInput.body.h = h;
    textInput.value = value;
    textInput.isFocus = false;

    textInput.event_register = &ruru_register_text_input;

    return textInput;
}

/**
 * @name 繪製文字輸入框
 * @param textInput 要繪製的文字輸入框
 * @example 用於 draw() 中
 * */
void ruru_draw_text_input(TextInput textInput) {
    al_draw_filled_rectangle(textInput.body.x, textInput.body.y, textInput.body.x + textInput.body.w,
                             textInput.body.y + textInput.body.h, al_map_rgb(255, 255, 255));
    if (textInput.isFocus) {
        al_draw_rectangle(textInput.body.x, textInput.body.y, textInput.body.x + textInput.body.w,
                          textInput.body.y + textInput.body.h, al_map_rgb(69, 86, 245), 3);
        al_draw_rounded_rectangle(textInput.body.x - 4, textInput.body.y - 4, textInput.body.x + textInput.body.w + 4,
                                  textInput.body.y + textInput.body.h + 4, 2, 2, al_map_rgb(255, 255, 255), 2);
    }
    al_draw_text(jfFont, al_map_rgb(0, 0, 0), textInput.body.x + 10, textInput.body.y + 10, 0, textInput.value);
}

/**
 * @name 註冊文字輸入框事件
 * @param textInput 要註冊的文字輸入框
 * @param key 按鍵輸入值
 * @example 用於 on_key_down() 中
 * */
static void ruru_register_text_input_key(TextInput *textInput, int key) {
    if (!textInput->isFocus) {
        return;
    }
    if (key == ALLEGRO_KEY_BACKSPACE) {
        if (strlen(textInput->value) > 0) {
            char *temp = malloc(sizeof(char) * (strlen(textInput->value) + 2));
            strncpy(temp, textInput->value, strlen(textInput->value) - 1);
            temp[strlen(textInput->value) - 1] = '\0';
            textInput->value = temp;
        }
    }
}

/**
 * @name
 * @param textInput 要註冊的文字輸入框
 * @param character
 * @example
 * */
static void ruru_register_text_input_key_char(TextInput *textInput, int character) {
    if (!textInput->isFocus) {
        return;
    }
    // backspace char
    if (character == 127) return;

    char *temp = malloc(sizeof(char) * (strlen(textInput->value) + 2));
    strcpy(temp, textInput->value);
    temp[strlen(textInput->value)] = (char) character;
    temp[strlen(textInput->value) + 1] = '\0';
    textInput->value = temp;
}

/**
 * @name 註冊文字輸入框事件
 * @param textInput 要註冊的文字輸入框
 * @param key 按鍵輸入值
 * @example 用於 on_key_down() 中
 * */
static void ruru_register_text_input_mouse(TextInput *textInput, int x, int y) {
    if (x >= textInput->body.x && x <= textInput->body.x + textInput->body.w &&
        y >= textInput->body.y && y <= textInput->body.y + textInput->body.h) {
        textInput->isFocus = true;
    } else {
        textInput->isFocus = false;
    }
}

void ruru_register_text_input(TextInput *textInput, ALLEGRO_EVENT event) {
    //printf("registered text input\n");
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        ruru_register_text_input_mouse(textInput, event.mouse.x, event.mouse.y);
    } else if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
        ruru_register_text_input_key_char(textInput, event.keyboard.unichar);
    } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        ruru_register_text_input_key(textInput, event.keyboard.keycode);
    }
}