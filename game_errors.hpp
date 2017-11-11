#ifndef GAME_ERRORS_HPP_INCLUDED
#define GAME_ERRORS_HPP_INCLUDED

using namespace std;

void bitmap_error(string bitmap_path)
{
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("blad podczas wczytywania bitmapy");
    allegro_exit();
    cout << "Error: Bitmap " << bitmap_path << " not loaded" << endl;
}


#endif // GAME_ERRORS_HPP_INCLUDED
