#ifndef GAME_MECHANICS_HPP_INCLUDED
#define GAME_MECHANICS_HPP_INCLUDED
#include<string>
#include <iostream>

using namespace std;

class Word{
public:
    string word;
    string category;
    string delLetters;
    string wordToPlay;

Word(string word, string category, string delLetters, string wordToPlay)
{
    this->word = word;
    this->category = category;
    this->delLetters = delLetters;
    this->wordToPlay = wordToPlay;
}

string getWord() { return(word); }
string getCategory() { return(category); }
string getDelLetters() { return(delLetters); }
string getWordToPlay() { return(wordToPlay); }



void print()
{
    cout << word + category + delLetters +wordToPlay;
}

};



#endif // GAME_MECHANICS_HPP_INCLUDED
