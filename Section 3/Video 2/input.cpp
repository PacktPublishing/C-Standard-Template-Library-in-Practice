#include <iostream>
#include <iterator>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

bool isValidChar(char c) {
  return !(isalpha(c));
}

int main() {
  istream_iterator<string> end;
  istream_iterator<string> ins(cin);

  map<string, int> wordFrequencies;

  while(ins != end) {
    string word = *ins++;
    word.erase(remove_if(word.begin(), word.end(), &isValidChar), word.end());

    if (wordFrequencies.find(word) != wordFrequencies.end()){
      wordFrequencies[word]++;
    }
    else {
      wordFrequencies[word] = 1;
    }
  }

  for (const auto& p : wordFrequencies) {
    cout << p.first << " : " << p.second << "\n";
  }

  cout << flush;

  return 0;
}
