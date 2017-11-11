#ifndef GAME_MECHANICS_HPP_INCLUDED
#define GAME_MECHANICS_HPP_INCLUDED
#include<string>
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


};

int rand_id(int vector_size)
{
    srand(time(NULL));
    return rand()%vector_size;
}


 vector<Word> generate_words( vector<Word>& words)
{
    words.push_back(Word(0,"SPRZEDAWCA","ZAWOD","EWCA","SPRZ_DA___"));
    words.push_back(Word(1,"KARTOFEL","WARZYWO","AROEL","K__T_F__"));
    words.push_back(Word(2,"MATEMATYKA","PRZEDMIOT SZKOLNY","ATEY","M___M___K_"));
    return words;
}



#endif // GAME_MECHANICS_HPP_INCLUDED
