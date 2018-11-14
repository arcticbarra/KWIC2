#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <list>
#include "Model.h"
#include "Helper.h"

using namespace std;

vector<string> getStopWords(string nameFile)
{
  vector<string> stopWords = fileToList(nameFile);
  return stopWords;
}

void printer(vector<string> phrases, vector<string> stopWords, int sortingType)
{
  //Retrieving data
  size_t size = phrases.size();
  vector<string> results;
  for (size_t i = 0; i < size; i++)
  {
    //String to rotate
    vector<string> words = split(phrases.back(), ' ');

    for (size_t w = 0, w_end = words.size(); w < w_end; w++)
    {
      if (find(stopWords.begin(), stopWords.end(), words[w]) != stopWords.end())
      {
        words.erase(words.begin() + w);
      }
    }

    phrases.pop_back();

    for (size_t j = 0, j_end = words.size(); j < j_end; j++)
    {

      //Join vecctor to string
      string result = join(words, " ");
      //Print Line
      //Normalize string and push
      results.push_back(stringToLower(result));
      //Inser Element at begin and delete Last Element
      rotate(words.begin(), words.begin() + words.size() - 1, words.end());
    }

    //Sort yo order alphabeticly
    if (sortingType == 1)
    {
      sort(results.begin(), results.end(), compare_by_word_asc);
    }
    else
    {
      sort(results.begin(), results.end(), compare_by_word_desc);
    }
  }

  //Print result
  for (int i = 0; i < results.size(); i++)
  {
    cout << results[i] << endl;
  }
}
