//
// Created by Hsuan on 2023/1/14.
//

#ifndef ALLEGRO5TEMPLATE_PROGRESSBAR_H
#define ALLEGRO5TEMPLATE_PROGRESSBAR_H


#include "utility.h"
#include "common.h"

typedef struct {
    RecArea body;
    float percent;
    ALLEGRO_COLOR color;
    ALLEGRO_FONT *font;

    func_ptr_register event_register;
} ProgressBar;

ProgressBar create_progress_bar(float x, float y, float w, float h, float percent, ALLEGRO_COLOR color);
void draw_progress_bar(ProgressBar progressBar);
void component_register_progress_bar(ProgressBar *progressBar, ALLEGRO_EVENT event);

#endif //ALLEGRO5TEMPLATE_PROGRESSBAR_H
