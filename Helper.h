#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

template <typename Out>
void split(const string &s, char delim, Out result)
{
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim))
  {
    *(result++) = item;
  }
}

vector<string> split(const string &s, char delim)
{
  vector<string> elems;
  split(s, delim, back_inserter(elems));
  return elems;
}

bool compare_by_word_asc(const string &lhs, const string &rhs)
{
  return lhs < rhs;
}

bool compare_by_word_desc(const string &lhs, const string &rhs)
{
  return lhs > rhs;
}

string stringToLower(string word)
{
  string lowerWord = word;
  for (int i = 0; i < word.length(); i++)
  {
    lowerWord[i] = tolower(word[i]);
  }
  return lowerWord;
}

string join(const vector<string> &elements, const char *const separator)
{
  switch (elements.size())
  {
  case 0:
    return "";
  case 1:
    return elements[0];
  default:
    ostringstream os;
    copy(elements.begin(), elements.end() - 1, ostream_iterator<string>(os, separator));
    os << *elements.rbegin();
    return os.str();
  }
}
