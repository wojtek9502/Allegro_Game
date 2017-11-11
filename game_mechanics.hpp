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

    words.push_back(Word(0,"SPRZEDAWCA","ZAWOD","EWCA","SPRZ-DA---"));
    words.push_back(Word(1,"KARTOFEL","WARZYWO","AROEL","K--T-F--"));
    words.push_back(Word(2,"MATEMATYKA","PRZEDMIOT SZKOLNY","ATEY","M---M---K-"));
    return words;
}


  const char* get_data_and_conv(vector<Word>& words, int p_word_number, string field_in_class, const char* string_array)
        {
           words[p_word_number].print();

          if(field_in_class.compare("category")==0)
            return words[p_word_number].category.c_str();

          if(field_in_class.compare("word")==0)
            return words[p_word_number].word.c_str();

          if(field_in_class.compare("delLetters")==0)
            return words[p_word_number].delLetters.c_str();

          if(field_in_class.compare("wordToPlay")==0)
            return words[p_word_number].wordToPlay.c_str();
        }

 const char* int_to_const_char(int number)
 {
    stringstream temp_str;
    temp_str<<(number);
    string str = temp_str.str();
    const char* cstr2 = str.c_str();
    return cstr2;
 }

 const char* pressed_key_info(int key)
 {
    cout << endl << "Nacisnieto klawisz: " << static_cast < char >( key );
 }


#endif // GAME_MECHANICS_HPP_INCLUDED
