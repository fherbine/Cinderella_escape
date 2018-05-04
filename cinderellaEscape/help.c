#include "cinderella.h"

t_page  *help_init(void)
{
    t_page *help;

    if (!(help = (t_page *)malloc(sizeof(t_page))))
        exit(EXIT_FAILURE);
    if (!(help->buts = (t_box *)malloc(sizeof(t_box) * 10))) /// 10 !!
        exit(EXIT_FAILURE);
    return (help);
}
