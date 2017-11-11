#include <iostream>
#include <allegro.h>
#include <time.h>
#include "game_errors.hpp"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
using namespace std;

bool menu_quit_bool = false;
bool new_game_clicked = false;
bool game_quit_bool = false;

int main()
{
    cout << "Press ESC to exit or click QUIT" << endl;
    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    clear_to_color(screen, makecol(0,0,0));
    show_mouse( screen );

    ////Wczytywanie bitmap
    ///bufor
    BITMAP *bufor = create_bitmap(SCREEN_WIDTH,SCREEN_HEIGHT);

    ///bitmapa menu
    BITMAP *menu =  load_bitmap("img/menu.bmp", default_palette);
    if(!menu){ bitmap_error("img/menu.bmp"); }

    ///bitmapa menu_new_game
    BITMAP *menu_new_game =  load_bitmap("img/menu_new_game.bmp", default_palette);
    if(!menu){ bitmap_error("img/menu_new_game.bmp"); }

    ///bitmapa menu_quit
    BITMAP *menu_quit =  load_bitmap("img/menu_quit.bmp", default_palette);
    if(!menu){ bitmap_error("img/menu_quit.bmp"); }

    ///


    //################################################-----PETLA MENU-----#######################################3
    while( menu_quit_bool == false )
    {
        if(key[KEY_ESC])
            menu_quit_bool = true;

        //####Obs³uga menu

        ///po najechaniu na new_game narysuj menu_new_game.bmp, po kliknieciu graj
        if(mouse_x > 242 && mouse_x < 628 && mouse_y > 274 && mouse_y < 323)
        {
            draw_sprite(screen, menu_new_game, 0, 0);
            if(mouse_b == 1)
            {
                new_game_clicked=true;
                menu_quit_bool=true;
            }
        }
        ///po najechaniu na quit narysuj menu_quit.bmp, po kliknieciu wyjdz
        else if(mouse_x > 242 && mouse_x < 410 && mouse_y > 350 && mouse_y < 414)
        {
            draw_sprite(screen, menu_quit, 0, 0);
            if(mouse_b == 1)
            {
                menu_quit_bool = true;
            }
        }
        ///gdy poza napisami narysuj zwykle menu
        else
        draw_sprite(screen, menu, 0, 0);
    }

    //##################################################---GRA---###########################
    if(new_game_clicked == true)
    {
        cout << "Zaczeto nowa gre";
        //rysujemy gre i usuwamy stare bitmapy menu
        draw_sprite(screen, bufor, 0, 0);
        clear_to_color(bufor, makecol(0, 0, 0));
        destroy_bitmap(menu);
        destroy_bitmap(menu_new_game);
        destroy_bitmap(menu_quit);

        //##### PETLA GRY
        while(game_quit_bool == false)
        {
            if(key[KEY_ESC])
                game_quit_bool = true;
        }


    }
    else
    {
        //nie weszlo w nowa gre ale bitmapy menu by wypadalo usunac
        destroy_bitmap(menu);
        destroy_bitmap(menu_new_game);
        destroy_bitmap(menu_quit);
    }



    destroy_bitmap(bufor);
    allegro_exit();

    return 0;
}
END_OF_MAIN();
