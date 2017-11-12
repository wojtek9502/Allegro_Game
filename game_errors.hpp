#ifndef GAME_ERRORS_HPP_INCLUDED
#define GAME_ERRORS_HPP_INCLUDED

using namespace std;

void bitmap_error(string bitmap_path)
{
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    string message = "Cant't load bitmap: " + bitmap_path;
    allegro_message(message.c_str());
    allegro_exit();
    cout << message << endl;
}

void font_error(string font_path)
{
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    string message = "Cant't load font" + font_path;
    allegro_message(message.c_str());
    allegro_exit();
    cout << message << endl;
}


#endif // GAME_ERRORS_HPP_INCLUDED
