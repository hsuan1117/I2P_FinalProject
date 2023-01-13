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
    if(textInput.isFocus){
        al_draw_rectangle(textInput.body.x, textInput.body.y, textInput.body.x + textInput.body.w,
                          textInput.body.y + textInput.body.h, al_map_rgb(255, 0, 0), 2);
    }
    al_draw_text(jfFont, al_map_rgb(0, 0, 0), textInput.body.x + 10, textInput.body.y + 10, 0, textInput.value);
}

/**
 * @name 註冊文字輸入框事件
 * @param textInput 要註冊的文字輸入框
 * @param key 按鍵輸入值
 * @example 用於 on_key_down() 中
 * */
void ruru_register_text_input_key(TextInput *textInput, int key) {
    if (!textInput->isFocus) {
        return;
    }
    if (key == ALLEGRO_KEY_BACKSPACE) {
        if (strlen(textInput->value) > 0) {
            textInput->value[strlen(textInput->value) - 1] = '\0';
        }
    } else if (key == ALLEGRO_KEY_ENTER) {

    } else {
        char *temp = malloc(sizeof(char) * (strlen(textInput->value) + 2));
        strcpy(temp, textInput->value);
        temp[strlen(textInput->value)] = (char) (96 + key);
        temp[strlen(textInput->value) + 1] = '\0';
        textInput->value = temp;
    }
    // printf("%s", textInput->value);
}

/**
 * @name 註冊文字輸入框事件
 * @param textInput 要註冊的文字輸入框
 * @param key 按鍵輸入值
 * @example 用於 on_key_down() 中
 * */
void ruru_register_text_input_mouse(TextInput *textInput, int x, int y) {
    if (x >= textInput->body.x && x <= textInput->body.x + textInput->body.w &&
        y >= textInput->body.y && y <= textInput->body.y + textInput->body.h) {
        textInput->isFocus = true;
    } else {
        textInput->isFocus = false;
    }
}