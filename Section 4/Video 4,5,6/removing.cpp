#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;

bool isValidChar(char c) {
  return !(isalpha(c));
}

int main() {
  string word = "h3ll0, h0w @re you?";
  string other;

  cout << word << "\n";

  auto it = remove_if(word.begin(), word.end(), &isValidChar);
  cout << word << "\n";

  word.erase(it, word.end());
  cout << word << "\n";

  word = "h3ll0, h0w @re you?";

  remove_copy_if(word.begin(), word.end(), back_inserter(other), &isValidChar);

  cout << word << "\n";
  cout << other << "\n";



  return 0;
}
