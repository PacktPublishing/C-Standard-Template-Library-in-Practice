#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

  //string vowels = "uoeia"; //This gets cut short
  string vowels = "aeiou";

  string test = "iuoea";
  string test2 = "iuoe";

  cout << std::boolalpha;

  cout << is_permutation(begin(test), end(test), begin(vowels)) << "\n";
  cout << is_permutation(begin(test2), end(test2), begin(vowels)) << "\n";

  while(next_permutation(begin(vowels), end(vowels))){
    cout << vowels << "\n";
  }

  cout << vowels << "\n";

  return 0;
}
