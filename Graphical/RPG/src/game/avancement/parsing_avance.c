/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** parsing_avance
*/

#include "../../../include/func_name.h"

static void parsing_avance4(rpg_t *rpg)
{
    if (rpg->game->in_game->game_status == GM_RILEY_WARREN) {
        rect_move_player(rpg, UP);
        rpg->game->in_game->map->last_pos = UP;
        if (rpg->basic->evt->event.type == sfEvtKeyReleased &&
        rpg->basic->evt->event.key.code == sfKeySpace)
            sfSound_stop(rpg->game->in_game->ig_sound->riley_warren);
        if (sfSound_getStatus(rpg->game->in_game->ig_sound->riley_warren)
        == sfStopped)
            rpg->game->in_game->game_status = GM_NOTIF7;
        rpg->game->in_game->inventory->vaccine_status = TRUE;
    }
    if (rpg->game->in_game->game_status == GM_NOTIF7) {
        phone_main(rpg);
        cdc_hitbox(rpg);
    }
    if (rpg->game->in_game->game_status == GM_ELEVATOR) {
        phone_main(rpg);
    }
}

static void parsing_avance3(rpg_t *rpg)
{
    if (rpg->game->in_game->game_status == GM_NOTIF4) {
        phone_main(rpg);
        car_hitbox(rpg);
        if (rpg->game->in_game->phone->alarm_status == FALSE) {
            sfSound_play(rpg->game->in_game->phone->alarm);
            rpg->game->in_game->phone->alarm_status = TRUE;
        }
    }
    if (rpg->game->in_game->game_status == GM_NOTIF5) {
        phone_main(rpg);
        if (rpg->game->in_game->map->status != MAP_INSIDE_POLICE &&
        rpg->game->in_game->map->status != MAP_OUTSIDE_POLICE) {
            rpg->game->in_game->phone->notif_prev =
            rpg->game->in_game->phone->notif_index;
            rpg->game->in_game->game_status = GM_NOTIF6;
        }
    }
    if (rpg->game->in_game->game_status == GM_NOTIF6) {
        phone_main(rpg);
        warren_hitbox(rpg);
    }
}

static void parsing_avance2(rpg_t *rpg)
{
    if (rpg->game->in_game->game_status == GM_INCOMMING_CALL) {
        call_hitbox(rpg);
        phone_main(rpg);
        if (rpg->game->in_game->phone->call_status == FALSE &&
        rpg->game->in_game->phone->phone_status == 1) {
            sfSound_play(rpg->game->in_game->phone->call_sound);
            rpg->game->in_game->phone->call_status = TRUE;
        }
    }
    if (rpg->game->in_game->game_status == GM_CALL) {
        rpg->game->in_game->phone->phone_status = 2;
        sfSound_stop(rpg->game->in_game->phone->call_sound);
        print_phone(rpg);
        incall_hitbox(rpg);
        rpg->game->in_game->phone->notif_bool = TRUE;
    }
    if (rpg->game->in_game->game_status == GM_NOTIF3) {
        phone_main(rpg);
        button_hitbox(rpg);
    }
}

static void parsing_avance1(rpg_t *rpg)
{
    if (rpg->game->in_game->game_status == GM_BEGIN) {
        phone_main(rpg);
        desk_hitbox(rpg);
    }
    if (rpg->game->in_game->game_status == GM_SPEECH) {
        rect_move_player(rpg, DOWN);
        rpg->game->in_game->map->last_pos = DOWN;
        if (rpg->basic->evt->event.type == sfEvtKeyReleased &&
        rpg->basic->evt->event.key.code == sfKeySpace)
            sfSound_stop(rpg->game->in_game->ig_sound->riley);
        if (sfSound_getStatus(rpg->game->in_game->ig_sound->riley) == sfStopped)
            rpg->game->in_game->game_status = GM_NOTIF2;
    }
    if (rpg->game->in_game->game_status == GM_NOTIF2) {
        phone_main(rpg);
        notif2_hitbox(rpg);
    }
}

void parsing_story(rpg_t *rpg)
{
    chose_map(rpg);
    print_warren(rpg);
    key_event_game(rpg);
    print_xp_life(rpg);
    shoot_bullet(rpg);
    lose_game(rpg);
    parsing_avance1(rpg);
    parsing_avance2(rpg);
    parsing_avance3(rpg);
    parsing_avance4(rpg);
}