#ifndef CINDERELLA_H_INCLUDED
#define CINDERELLA_H_INCLUDED

#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "maps.h"
#include "projectStruct.h"

#define NSEQ 1

int         init_all(void);

BITMAP      *backgroundColor(int color, BITMAP *buff);
t_box       init_box(int x1, int y1, int x2, int y2);
BITMAP      *put_box(t_box box, BITMAP *buff);
void        hide_box(t_box box);

t_box       newButton(int x, int y, char *text);
t_box       buttonStatusUpdate(t_box button);

void        cind(void);

BITMAP      *add_alph_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y);
BITMAP      *add_reg_bmp(BITMAP *curr, char *path, int pic_w, int pic_h, int dest_x, int dest_y);

void        leave_game(t_page *game, t_page *menu);

void        init_all_seq(void);
t_bots      *new_bot(t_bots_seq seq, int x, int y, t_page *game);
void        refresh_bot(t_bots *bot, int dest_x, int dest_y, t_page *game);


extern      t_bots_seq         bots_tab[NSEQ];

#endif
