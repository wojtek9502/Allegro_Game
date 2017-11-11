#include <iostream>
#include <allegro.h>
#include <time.h>
#define width 800
#define height 600
using namespace std;

int main()
{
    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, width, height, 0, 0);
    clear_to_color(screen, makecol(0,0,0));
    ///pokazanie kursora myszki w grze
    show_mouse( screen );



    readkey();
    allegro_exit();
    return 0;
}
END_OF_MAIN();
