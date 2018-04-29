#include "cinderella.h"

t_bots_seq         bots_tab[NSEQ] =
{
    // path              nimg wdth height
    {"imgs/cind_right.bmp", 4, 35, 35},
    {"imgs/prince.bmp",     4, 35, 35}
};

static void test()
{
    t_box tst;
    BITMAP *buff;

    init_all();
    buff = create_bitmap(SCREEN_W, SCREEN_H);
    buff = backgroundColor(WHITE, buff);
    tst = newButton(150, 150, "hello world !");
    buff = put_box(tst, buff);



    while(!key[KEY_ENTER])
    {
        //clear_bitmap(buff);
        tst = buttonStatusUpdate(tst);
        buff = put_box(tst, buff);
        blit(buff, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
}

int main()
{
 ///  test();
    cind();
    return 0;
}
END_OF_MAIN();
