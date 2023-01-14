//
// Created by Hsuan on 2023/1/14.
//

#include <allegro5/allegro_primitives.h>
#include "ProgressBar.h"

/*
 * @name 建立
 * @param x x座標
 * @param y y座標
 * @param w 寬度
 * @param h 高度
 * @param percent 百分比
 * @param color 顏色
 */
ProgressBar create_progress_bar(float x, float y, float w, float h, float percent, ALLEGRO_COLOR color) {
    ProgressBar button;
    memset(&button, 0, sizeof(ProgressBar));

    button.body.x = x;
    button.body.y = y;
    button.body.w = w;
    button.body.h = h;
    button.percent = percent;
    button.color = color;

    // some default style settings
    button.font = mainFont;

    button.event_register = &component_register_progress_bar;
    return button;
}

void draw_progress_bar(ProgressBar progressBar) {
    float x = progressBar.body.x, y = progressBar.body.y, w = progressBar.body.w, h = progressBar.body.h;
    float percent = progressBar.percent;

    for(int i=0;i<10;i++) {
        al_draw_filled_rectangle(x, y + i * h / 10, x + w, y + (i + 1) * h / 10, al_map_rgb(255, 255, 255));
    }
    al_draw_filled_rectangle(x, y, x + w * percent, y + h, progressBar.color);
    //al_draw_rectangle(x + w , y, x + w, y + h, al_map_rgb(0, 255, 0), 1);
}

void component_register_progress_bar(ProgressBar *progressBar, ALLEGRO_EVENT event) {

}