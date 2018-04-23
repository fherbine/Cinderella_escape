#ifndef CINDERELLA_H_INCLUDED
#define CINDERELLA_H_INCLUDED

#include <allegro.h>
#include <stdlib.h>
#include "colors.h"
#include "projectStruct.h"

int         init_all(void);

void        backgroundColor(int color);
t_box       init_box(void);
void        put_box(t_box box);

#endif
