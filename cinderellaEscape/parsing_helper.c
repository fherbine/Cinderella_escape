#include "cinderella.h"


static void initial_fill(t_text *editor)
{
    for(int i = 0; i < 255; i++)
    {
        editor->buf[i] = ' ';
    }
    editor->buf[255] = '\0';
}

t_text      *new_txt(int x1, int y1, int x2, int y2)
{
    t_text  *editor;

    if (!(editor = (t_text *)malloc(sizeof(t_text))))
        exit(EXIT_FAILURE);
    initial_fill(editor);
    editor->x1 = x1;
    editor->y1 = y1;
    editor->x2 = x2 - 8;
    editor->y2 = y2 - 8;
    editor->cx = x1;
    editor->cy = y1;
    editor->cursor = 0;
    return(editor);
}

static void add_char_buf(t_text *editor, char c)
{
    (editor->buf)[editor->cursor] = c;
}

void    read_buf(t_text *editor, t_page *game)
{
    int key_pressed, scancode;
    if (!keypressed())
        return ;
    key_pressed = readkey();
    scancode = key_pressed >> 8;
    textprintf_ex(game->win, font, editor->cx, editor->cy + 8, BLACK, WHITE, " ");
    if (scancode == KEY_LEFT && editor->cursor > 0)
    {
        if (editor->cursor <= 0)
            return ;
        editor->cursor -= 1;
        if (editor->cx > editor->x1)
            editor->cx -= 8;
        else if (editor->cy > editor->y1)
        {
            editor->cx = editor->x2;
            editor->cy -= 16;
        }
    }
    else if (scancode == KEY_BACKSPACE && editor->cursor > 0)
    {
        if (editor->cursor <= 0)
            return ;
        editor->cursor -= 1;
        add_char_buf(editor, ' ');
        if (editor->cx > editor->x1)
            editor->cx -= 8;
        else if (editor->cy > editor->y1)
        {
            editor->cx = editor->x2;
            editor->cy -= 16;
        }
        textprintf_ex(game->win, font, editor->cx, editor->cy, BLACK, WHITE, " ");
    }
    else if (scancode == KEY_RIGHT && editor->cursor < 254)
    {
        if (editor->cursor >= 254)
            return ;
        editor->cursor += 1;
        if (editor->cx < editor->x2)
            editor->cx += 8;
        else if (editor->cy < editor->y2)
        {
            editor->cx = editor->x1;
            editor->cy += 16;
        }
    }
    else
    {
        if (editor->cursor >= 254)
            return ;
        add_char_buf(editor, (char)key_pressed);
        editor->cursor += 1;
        textprintf_ex(game->win, font, editor->cx, editor->cy, BLACK, WHITE, "%c", (char)key_pressed);
        if (editor->cx == editor->x2)
        {
            editor->cx = editor->x1;
            editor->cy += 16;
        }
        else
            editor->cx += 8;
    }
    textprintf_ex(game->win, font, editor->cx, editor->cy + 8, BLACK, WHITE, "^");
}
