#include "cinderella.h"


static void initial_fill(t_text *editor)
{
    for(int i = 0; i < 255; i++)
    {
        editor->buf[i] = ' ';
    }
    editor->buf[255] = '\0';
}

t_text      *new_txt(void)
{
    t_text  *editor;

    if (!(editor = (t_text *)malloc(sizeof(t_text))))
        exit(EXIT_FAILURE);
    initial_fill(editor);
    return(editor);
}
