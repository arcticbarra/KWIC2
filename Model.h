#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Load a file and return a list with lines of file
vector<string> fileToList(string nameFile)
{
  vector<string> phrases;
  ifstream inputFile(nameFile);
  ;
  string line;
  while (getline(inputFile, line))
  {
    phrases.insert(phrases.begin(), line);
  }
  return phrases;
}
