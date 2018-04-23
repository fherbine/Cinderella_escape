#include "cinderella.h"

int main()
{
    t_box tst;

    init_all();
    backgroundColor(WHITE);

    tst = newButton(150, 150, "hello");
    put_box(tst);


    while(!key[KEY_ESC]);
    return 0;
}
END_OF_MAIN();
