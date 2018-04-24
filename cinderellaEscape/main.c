#include "cinderella.h"

int main()
{
    t_box tst;

    init_all();
    backgroundColor(WHITE);
    tst = newButton(150, 150, "hello world !");
    put_box(tst);


    while(!key[KEY_ESC])
    {
        show_mouse(screen);
        tst = buttonStatusUpdate(tst);
    }
    return 0;
}
END_OF_MAIN();
