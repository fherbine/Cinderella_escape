#include "cinderella.h"

int main()
{
    t_box tst;

    tst = init_box(10, 10, 100, 40);

    init_all();
    backgroundColor(WHITE);

    tst.bg_color = WHITE;
    tst.borders = BLUE;
    tst.text = "tutu";
    put_box(tst);


    while(!key[KEY_ESC]);
    return 0;
}
END_OF_MAIN();
