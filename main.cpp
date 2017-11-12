#include <iostream>
#include <allegro.h>
#include <time.h>
#include <string.h>
#include "game_errors.hpp"
#include "game_mechanics.hpp"
#include <vector>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
using namespace std;

bool menu_quit_bool = false;
bool new_game_clicked = false;
bool game_quit_bool = false;

/*@TODO
uzupelnianie kresek po wprowadzeniu poprawnej litery
poprawic odswiezanie ekranu
*/
int main()
{
    cout << "Press ESC to exit or click QUIT" << endl;
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    clear_to_color(screen, makecol(0,0,0));
    show_mouse( screen );

    FONT *hud_font = load_font("fonts/hud_font.pcx",NULL,NULL);
        if(!hud_font) { font_error("fonts/hud_font.pcx"); }
    FONT *word_font = load_font("fonts/word_font.pcx",NULL,NULL);
        if(!word_font) { font_error("fonts/word_font.pcx"); }

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

    ///##########################BITMAPY WISIELCA
    BITMAP *hangman1 =  load_bitmap("img/hangman1.bmp", default_palette);
        if(!menu){ bitmap_error("img/hangman1.bmp"); }

    BITMAP *hangman2 =  load_bitmap("img/hangman2.bmp", default_palette);
        if(!menu){ bitmap_error("img/hangman2.bmp"); }

    BITMAP *hangman3 =  load_bitmap("img/hangman3.bmp", default_palette);
        if(!menu){ bitmap_error("img/hangman3.bmp"); }

    BITMAP *hangman4 =  load_bitmap("img/hangman4.bmp", default_palette);
        if(!menu){ bitmap_error("img/hangman4.bmp"); }

    BITMAP *hangman5 =  load_bitmap("img/hangman5.bmp", default_palette);
        if(!menu){ bitmap_error("img/hangman5.bmp"); }




    //################################################-----PETLA MENU-----#######################################3
    while( menu_quit_bool == false )
    {
        if(key[KEY_ESC])
            menu_quit_bool = true;

        //####Obs�uga menu

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
        int lifes = 5;
        ///wektor slow
        vector<Word> words;

        ///wypelnij wektor slow
        words = generate_words(words);
        ///wylosuj slowo
        int word_number = rand_word_id(words.size());

        ///POBIERANIE WARTOSCI POTRZEBNYCH DO GRY Z KLASY I KONWERSJA NA CHAR[]
        const char* charCategory = get_data_and_conv(words, word_number, "category", charCategory);
        const char* charWordToPlay = get_data_and_conv(words, word_number, "wordToPlay", charWordToPlay);


        //rysujemy gre i usuwamy stare bitmapy menu
        clear_to_color(screen, makecol(0, 0, 0));
        destroy_bitmap(menu);
        destroy_bitmap(menu_new_game);
        destroy_bitmap(menu_quit);

        //##### PETLA GRY
        while(game_quit_bool == false)
        {
            clear_to_color(screen, makecol(0, 0, 0));

            ///rysuj wisielca
            switch(lifes)
            {
                case 4:
                {
                    masked_blit( hangman1, screen, 0, 0, 200, 100, hangman1->w, hangman1->h );
                }break;

                case 3:
                {
                    masked_blit( hangman2, screen, 0, 0, 200, 100,hangman2->w,hangman2->h );
                }break;

                case 2:
                {
                    masked_blit( hangman3, screen, 0, 0, 200, 100, hangman3->w, hangman3->h );
                }break;

                case 1:
                {
                    masked_blit( hangman4, screen, 0, 0, 200, 100, hangman4->w, hangman4->h );
                }break;
            }

            ///jesli brak zyc
            if(lifes==0)
            {
                clear_to_color(screen, makecol(0, 0, 0));
                textout_ex( screen, word_font, "GAME OVER", (SCREEN_WIDTH/2)-100, 500, makecol( 255, 0, 0 ), - 1 );
                masked_blit( hangman5, screen, 0, 0, 200, 100, hangman5->w, hangman5->h );

                readkey();
                game_quit_bool = true;
                destroy_bitmap(hangman1);
                destroy_bitmap(hangman2);
                destroy_bitmap(hangman3);
                destroy_bitmap(hangman4);
                destroy_bitmap(hangman5);
                continue;
            }

            if(key[KEY_ESC])
                game_quit_bool = true;

            ///######## rysuj HUD
            textout_ex( screen, hud_font, "Kategoria:", 20, 20, makecol( 234, 247, 0 ), - 1 );
            //text_length() zwraca ilosc pikseli w napisie slowa
            textout_ex( screen, hud_font, charCategory, text_length(hud_font, "Kategoria:")+30, 20, makecol( 234, 247, 0 ), - 1 );

            textout_ex( screen, hud_font, "Pozostalo zyc:", 620, 20, makecol( 234, 247, 0 ), - 1 );
            textout_ex( screen, hud_font, int_to_const_char(lifes), 620+text_length(hud_font, "Pozostalo zyc:")+10, 20 , makecol( 234, 247, 0 ), - 1 );

            int word_x = (SCREEN_WIDTH/2)-(text_length(word_font,charWordToPlay)/2);
            textout_ex( screen, word_font, charWordToPlay, word_x, 500, makecol( 234, 247, 0 ), - 1 );


            ///############## INTERAKCJA Z USEREM
            ///Reakcja na nacisniecie klawisza (konwersja na duza litere)
            int pressed_key = readkey()-32;

            ///wektor na indeksy znalezionych liter
            vector<int> positions_vector;

            //sprawdz czy wcisnieta litera zwiera sie w slowe
            //jesli nie to zwroc false jesli tak to zwroc wektor pozycji liter w wyrazie i zwroc true
            bool is_found = check_letter(pressed_key,words,word_number, positions_vector );

            if(is_found == true)
            {
                //jesli zgadl uzupelnij wyraz
                //charWordToPlay = complete_word(pressed_key, words, word_number);
                ///pobierz wyraz ktorym grasz


                char charTmp[1000] = {0};
                strcpy(charTmp,charWordToPlay);
                cout << endl << "do funkcji idzie charTmp: " << charTmp;
                ///uzupelnij slowo i zwroc juz uzupelnione
                complete_word(pressed_key, positions_vector, strlen(charTmp),charTmp);
                cout << endl << "Po uzupelnieniu charTmp: " << charTmp;

                //
            }
            else
            {
                ///jesli nie zgadl zabierz zycie
                lifes--;
            }
        }
    }
    else
    {
        //nie weszlo w nowa gre ale bitmapy by wypadalo usunac
        destroy_bitmap(menu);
        destroy_bitmap(menu_new_game);
        destroy_bitmap(menu_quit);
        destroy_bitmap(hangman1);
        destroy_bitmap(hangman2);
        destroy_bitmap(hangman3);
        destroy_bitmap(hangman4);
        destroy_bitmap(hangman5);
    }



    destroy_bitmap(bufor);
    allegro_exit();

    return 0;
}
END_OF_MAIN();
