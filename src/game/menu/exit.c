/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** exit
*/

#include "../../../include/func_name.h"

void exit_resume(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 390)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 465))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->ig_menus->pause_menu[RESUME_PAUSE], NULL);
    }
}

void exit_option(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 500)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 577))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->ig_menus->pause_menu[OPTION_PAUSE], NULL);
    }
}

void exit_quit(rpg_t *rpg)
{
    if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 614)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 689))) {
        sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
        rpg->game->in_game->ig_menus->pause_menu[QUIT_PAUSE], NULL);
    }
}

void assemble_spt_pause(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->ig_menus->exit, NULL);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->ig_menus->pause_menu[MENU_PAUSE], NULL);
    exit_resume(rpg);
    exit_option(rpg);
    exit_quit(rpg);
    click_on_resume(rpg);
    click_on_option(rpg);
    click_on_quit(rpg);
}