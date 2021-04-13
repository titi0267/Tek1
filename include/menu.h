/*
** EPITECH PROJECT, 2021
** menu.h
** File description:
** menu rpg
*/

#ifndef menu_scr
#define menu_scr

typedef struct intro_sound_s
{
    sfSoundBuffer *create_start;
    sfSound *start;
} intro_sound_t;

typedef struct intro_pegi_s
{
    sfIntRect rect_pegi;
    int offset_pegi;
    int line_pegi;
    sfSprite *pegi_spt;
    int wait_pegi;
} intro_pegi_t;

typedef struct intro_basil_s
{
    int line_logo;
    int offset_logo;
    sfIntRect rect_logo;
    sfSprite *basil_spt;
    int wait_basil;

} intro_basil_t;

typedef struct intro_s
{
    intro_sound_t *intro_snd;
    intro_basil_t *intro_basil;
    intro_pegi_t *intro_pegi;
} intro_t;

typedef struct menu_snd_s
{
    sfSoundBuffer *create_a_menu;
    sfSound *a_menu;
} menu_snd_t;

typedef struct background_adn_s
{
    sfSprite *background;
    sfTexture *create_background;
    sfIntRect rect_but;
    int line_rect;
    int offset;
} background_adn_t;

typedef struct menu_s
{
    intro_t *intro;
    menu_snd_t *menu_snd;
    background_adn_t *bgd_adn;
} menu_t;

#endif /* !menu_scr */
