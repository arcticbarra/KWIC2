#include <stdlib.h>
#include "Controller.h"
#include <string>
#include <list>

using namespace std;

int main()
{

  int opt;
  int sortingType;
  string nameFile;
  vector<string> stopWords, words;
  //Load the data with fileToList() and process with printer()
  cout << "KWIC Program" << endl;
  cout << "1. ASC" << endl;
  cout << "2. DESC" << endl;
  cout << "Select sorting type: ";

  cin >> sortingType;

  cout << "1. Enter stop words by file" << endl;
  cout << "2. Enter stop words by terminal" << endl;
  cout << "Select option: ";

  cin >> opt;

  if (opt == 1)
  {
    cout << "Give the data file name: " << endl;
    cin >> nameFile;
    stopWords = getStopWords(nameFile);
  }
  else if (opt == 2)
  {
  }

  cout << "1. Enter data by file" << endl;
  cout << "2. Enter data by terminal" << endl;
  cout << "Select option: ";

  cin >> opt;

  if (opt == 1)
  {
    cout << "Give the data file name: " << endl;
    cin >> nameFile;
    words = fileToList(nameFile);
  }
  else if (opt == 2)
  {
    string line;
    cout << "Enter number of lines: ";
    int number_of_lines;
    cin >> number_of_lines;
    number_of_lines++;
    while (number_of_lines--)
    {
      getline(cin, line);
      words.push_back(line);
    }
  }

  printer(words, stopWords, sortingType);
  return 0;
}
