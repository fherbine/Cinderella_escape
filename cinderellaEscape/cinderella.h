#ifndef CINDERELLA_H_INCLUDED
#define CINDERELLA_H_INCLUDED

#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "colors.h"
#include "projectStruct.h"

int         init_all(void);

void        backgroundColor(int color);
t_box       init_box(int x1, int y1, int x2, int y2);
void        put_box(t_box box);
void        hide_box(t_box box);

t_box       newButton(int x, int y, char *text);
t_box       regularButton(t_box button);
t_box       hoverButton(t_box button);
t_box       buttonStatusUpdate(t_box button);

#endif
