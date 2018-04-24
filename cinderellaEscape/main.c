#include "cinderella.h"

static void test()
{
    t_box tst;

    init_all();
    backgroundColor(WHITE);
    tst = newButton(150, 150, "hello world !");
    put_box(tst);


    while(!key[KEY_ENTER])
    {
        show_mouse(screen);
        tst = buttonStatusUpdate(tst);
    }
}

int main()
{
    test();
    return 0;
}
END_OF_MAIN();
