#include <iostream>
#include <allegro.h>
#include <time.h>
#include "game_errors.hpp"
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


    ///rysowanie menu
    BITMAP *menu = NULL;
    menu = load_bitmap("img/menu.bmp", default_palette);
    if(!menu){
        bitmap_error("img/menu.bmp");
    }
    int menu_x = 100;
    int menu_y = 100;
    draw_sprite(screen, menu, menu_x,menu_y);



    readkey();
    allegro_exit();
    return 0;
}
END_OF_MAIN();
