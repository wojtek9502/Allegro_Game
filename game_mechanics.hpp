#ifndef GAME_MECHANICS_HPP_INCLUDED
#define GAME_MECHANICS_HPP_INCLUDED
#include<string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Word{
public:
    int id;
    string word;
    string category;
    string delLetters;
    string wordToPlay;

Word(int id, string word, string category, string delLetters, string wordToPlay)
{
    this->id = id;
    this->word = word;
    this->category = category;
    this->delLetters = delLetters;
    this->wordToPlay = wordToPlay;
}

void print()
{
    cout << id << " " << word << " " << category << " " << delLetters << " " << wordToPlay << endl;
}

};

int rand_word_id(int vector_size)
{
    srand(time(NULL));
    return rand()%vector_size;
}


 vector<Word> generate_words( vector<Word>& words)
{
    ///dodawanie slow tutaj wg wzoru (id, slowo, kategoria, litery_do_usuniecia, gotowe slowo)

    words.push_back(Word(0,"SPRZEDAWCA","ZAWOD","EWCA","SPRZ-D----"));
    words.push_back(Word(1,"KARTOFEL","WARZYWO","AROEL","K--T-F--"));
    words.push_back(Word(2,"MATEMATYKA","PRZEDMIOT SZKOLNY","ATEY","M---M---K-"));
    words.push_back(Word(3,"BIEDRONKA","ZWIERZE","BIERONA","---D---K-"));
    words.push_back(Word(4,"PENDRIVE","URZADZENIE","PENDIVE","----R---"));
    return words;
}


const char* get_data_and_conv(vector<Word>& words, int p_word_number, string field_in_class, const char* string_array)
{
    ///words[p_word_number].print();

    if(field_in_class.compare("category")==0)
        return words[p_word_number].category.c_str();

    if(field_in_class.compare("word")==0)
            return words[p_word_number].word.c_str();

    if(field_in_class.compare("delLetters")==0)
        return words[p_word_number].delLetters.c_str();

    if(field_in_class.compare("wordToPlay")==0)
        return words[p_word_number].wordToPlay.c_str();
}


string get_del_letters(vector<Word>& words, int p_word_number )
{
    return words[p_word_number].delLetters;
}

string get_word(vector<Word>& words, int p_word_number )
{
    return words[p_word_number].word;
}

string get_word_to_play(vector<Word>& words, int p_word_number )
{
    return words[p_word_number].wordToPlay;
}

bool check_letter(int pressed_key, vector<Word>& words, int p_word_number, vector<int>& positions_vector)
 {
    int position = 0;
    char c_pressed_key = static_cast < char >( pressed_key );
    string delLetters = get_del_letters(words,p_word_number);
    string word = get_word(words,p_word_number);


    cout << endl << "Wcisnieto " << (char)pressed_key << "    Brakuje: " << delLetters << "     Cale slowo to: " << word;


    ///szukanie znaku
    position = word.find( c_pressed_key);
    if( position == string::npos )
    {
        return false;
    }
    else
    {
        do
        {
            positions_vector.push_back(position);
            position = word.find( c_pressed_key, position + 1 );
        } while( position != string::npos );
        return true;
    }
 }

 const char* int_to_const_char(int number)
 {
    stringstream temp_str;
    temp_str<<(number);
    string str = temp_str.str();
    const char* cstr2 = str.c_str();
    return cstr2;
 }

 void pressed_key_info(int key)
 {
    cout << endl << "Nacisnieto klawisz: " << static_cast < char >( key );
 }

 void print_position_vector(vector<int>& positions_vector)
 {
     cout << endl << "print position_vector";
     for(int i=0; i<positions_vector.size(); i++)
     {
         cout << endl << "position vector[" << i << "] = " << positions_vector[i];
     }
     cout << endl;
 }

 char int_to_char(int number)
 {
     char tmp = (char) number;
     return tmp;
 }

void complete_word(int pressed_key, vector<int>& positions_vector,  vector<Word>& words, int word_number)
{
    //iterator
    vector<int>::iterator element;
    string word_tmp = get_word_to_play(words,word_number);

    //przejdz przez cale slowo, jesli ktorys z indeksow slowa znajduje sie w position_vectors to zamien ten indeks na wcisnieta litere
    for(int i=0; i<word_tmp.length(); i++)
       for(element=positions_vector.begin(); element!=positions_vector.end(); ++element)
       {
         if(i==*element)
         {
            word_tmp[i]=pressed_key;
         }
       }

    ///zamien pole wordToPlay w klasie Word. Tego pola uzyje sie potem do wypisania go na ekran
    ///plus to zmienione slowo bedzie wykorzystane przy nastepnym wywolaniu tej funkcji
    words[word_number].wordToPlay = word_tmp;
}

///w miare zgadywania liter pole wordToPlay zmienia sie (usuwane sa "-") user wygra jesli pole wordToPlay == pole Word (odgadnie wszystkie litery)
bool check_win(vector<Word>& words, int word_number)
{
    //pobranie pol
    string tmpWordToPlay = get_word_to_play(words, word_number);
    string tmpWord = get_word(words, word_number);

    //cout << endl << "Word: " << tmpWord;
    //cout << endl << "WordToPlay: " << tmpWordToPlay;

    if(tmpWordToPlay.compare(tmpWord)==0)
        return true;
    else
        return false;
}

#endif // GAME_MECHANICS_HPP_INCLUDED
