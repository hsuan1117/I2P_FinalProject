// [shared.c]
// you should define the shared variable declared in the header here.

#include "shared.h"
#include "utility.h"
#include "game.h"
// #include "scene_menu.h"

ALLEGRO_FONT *font_pirulen_32;
ALLEGRO_FONT *font_pirulen_24;
ALLEGRO_SAMPLE *themeMusic = NULL;
ALLEGRO_SAMPLE *PACMAN_MOVESOUND = NULL;
ALLEGRO_SAMPLE *PACMAN_DEATH_SOUND = NULL;
ALLEGRO_FONT *menuFont = NULL;
ALLEGRO_FONT *sansFont = NULL;
ALLEGRO_FONT *jfFont = NULL;
int fontSize = 30;
float music_volume = 0.5;
float effect_volume = 0.5;
bool gameDone = false;

/*
	A way to accelerate is load assets once.
	And delete them at the end.
	This method does provide you better management of memory.
	
*/
void shared_init(void) {

    menuFont = load_font("Assets/Minecraft.ttf", fontSize);
    sansFont = load_font("Assets/NotoSansTC-Regular.ttf", fontSize);
    jfFont = load_font("Assets/jf.ttf", fontSize);
    themeMusic = load_audio("Assets/Music/original_theme.ogg");
    PACMAN_MOVESOUND = load_audio("Assets/Music/pacman-chomp.ogg");
    PACMAN_DEATH_SOUND = load_audio("Assets/Music/pacman_death.ogg");
}

void shared_destroy(void) {

    al_destroy_font(menuFont);
    al_destroy_font(sansFont);
    al_destroy_font(jfFont);
    al_destroy_sample(themeMusic);
    al_destroy_sample(PACMAN_MOVESOUND);
    al_destroy_sample(PACMAN_DEATH_SOUND);
}