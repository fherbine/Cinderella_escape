#ifndef CINDERELLA_H_INCLUDED
#define CINDERELLA_H_INCLUDED

#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "colors.h"
#include "maps.h"
#include "projectStruct.h"

#define NSEQ 2

int         init_all(void);

BITMAP      *backgroundColor(int color, BITMAP *buff);
BITMAP      *backgroundImg(char *path, BITMAP *buff);
t_box       init_box(int x1, int y1, int x2, int y2);
BITMAP      *put_box(t_box box, BITMAP *buff);
void        hide_box(t_box box);

t_box       newButton(int x, int y, char *text);
t_box       buttonStatusUpdate(t_box button);
int         get_def_click(int x1, int y1, int x2, int y2);



void        cind(void);

BITMAP      *add_alph_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y);
BITMAP      *add_reg_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y);
t_elems     *new_elem(float x, float y, char *path, t_page *game);
void        free_elems(t_elems **tab);

void        leave_game(t_page *game, t_page *menu);
int         check_all_be_col(t_page *game);

void        init_all_seq(void);
t_bots      *new_bot(t_bots_seq seq, float x, float y, t_page *game);
int         refresh_bot(t_bots *bot, float dest_x, float dest_y, t_page *game, t_bots **bots);
void        refresh_pos(t_bots *bot, t_page *game);


void        menu_func(t_page *menu, t_page *game, int *status);
void        menu_routine(t_page *menu, t_page *game);
t_page      *menu_init(void);

t_page      *game_init(void);
void        game_routine(t_page *game);
void        game_func(t_page *game, int *status);
void        clear_lvl(t_page *game);

t_page      *help_init(void);
void        help_routine(t_page *help);
void        help_func(t_page *help, int *status);

t_text      *new_txt(int x1, int y1, int x2, int y2);
void        read_buf(t_text *editor, t_page *game);

void        exec_code(t_page *game);
int         get_one_move(void);

void        reset_coltab(t_page *game);
void        add_color_case(t_page *game, t_bots *current);
void        display_color(t_page *game);

extern      t_bots_seq         bots_tab[NSEQ];

#endif
