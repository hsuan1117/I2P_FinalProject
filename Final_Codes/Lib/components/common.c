//
// Created by Hsuan on 2023/1/14.
//

#include "common.h"
#include "TextInput.h"
#include "TextButton.h"

void register_scene_components(void *scene, ALLEGRO_EVENT event) {
    AllegroScene *active_scene = (AllegroScene *) scene;
    if (active_scene->components) {
        for (int i = 0; i < active_scene->component_size; i++) {
            switch (active_scene->component_types[i]) {
                case RURU_TEXT_INPUT:
                    ((TextInput *) (active_scene->components[i]))->event_register(
                            (component *) (active_scene->components[i]), event);
                    break;
                case RURU_TEXT_BUTTON:
                    ((TextButton *) (active_scene->components[i]))->event_register(
                            (component *) (active_scene->components[i]), event);

            }
        }
    }
}