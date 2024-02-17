/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "scrabbleAssistant.h"
#include <algorithm>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

ScrabbleAssistant::ScrabbleAssistant(vector<string> words){
  this->table = new HashTable<string, string>; 
  this->anagramDictionary = new HashTable<string, vector<string>>; 
  for (int i = 0; i < words.size(); i++){
    this->table->insert(words.at(i), words.at(i));
    string sortedString = sortLetters(words.at(i));
    vector<string> insertables;
    //if the sortedString exists as a key, current word is an anagram of a previous word 
    if (this->anagramDictionary->contains(sortedString))
    {
      insertables = anagramDictionary->get(sortedString);
      insertables.push_back(words.at(i));
      this->anagramDictionary->update(sortedString, insertables);
    }
    //otherwise, current word is unique 
    else{
      insertables.push_back(words.at(i));
      this->anagramDictionary->insert(sortedString, insertables);
    }
  }
}

ScrabbleAssistant::~ScrabbleAssistant(){
  delete this->table;
  delete this->anagramDictionary;
}

bool ScrabbleAssistant::spellCheck(string word){
  return this->table->contains(word);
}

vector<string> ScrabbleAssistant::anagramsOf(string letters){
  //If there are no anagrams for letters, return empty vector. 
  if(!this->anagramDictionary->contains(sortLetters(letters))){
    return {}; 
  }
  return this->anagramDictionary->get(sortLetters(letters));
}

vector<string> ScrabbleAssistant::findWords(string letters){
  //Generate all combinations of letters
  vector<string> allCombo = stringPowerSet(letters);
  vector<string> validWords;
  vector<string> anagrams;
  //Keep track of already used words
  HashTable<string, int> usedWords; 
  for (int i = 0; i < allCombo.size(); i++){
    //Generate valid anagrams for each combination 
    anagrams = this->anagramsOf(allCombo.at(i));
    for(int j = 0; j < anagrams.size(); j++){
      //If an anagram has not been used, insert to validWords
      if(!usedWords.contains(anagrams[j])){
        usedWords.insert(anagrams[j], 1);
        validWords.push_back(anagrams[j]); 
      }
    }
  }
  return validWords;
}

vector<string> ScrabbleAssistant::stringPowerSet(string letters){
  vector<string> result;
  //base case: return empty set if letters is empty
  if (letters == "")
  {
    result.push_back("");
    return result;
  }

  char firstChar = letters[0];
  string sub = letters.substr(1);

  //recursive case: find subset of last n-1 elements in set
  vector<string> smallerResult = stringPowerSet(sub);

  for (int i = 0; i < smallerResult.size(); i++)
  {
    result.push_back(smallerResult[i]);             // recursive results
    result.push_back(firstChar + smallerResult[i]); // append first element
  }
  return result;
}


string ScrabbleAssistant::sortLetters(string s)
{
  sort(s.begin(), s.end());
  return s;
}