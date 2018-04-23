#ifndef CINDERELLA_H_INCLUDED
#define CINDERELLA_H_INCLUDED

#include <allegro.h>
#include <stdlib.h>
#include "colors.h"
#include "projectStruct.h"

int         init_all(void);

void        backgroundColor(int color);
t_box       init_box(int x1, int y1, int x2, int y2);
void        put_box(t_box box);

#endif
