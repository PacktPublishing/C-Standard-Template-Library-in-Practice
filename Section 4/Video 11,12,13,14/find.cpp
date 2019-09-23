#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  string s = "This is some text, with some characters. Not every character is a letter, some, like this one '3' are numbers.";

  vector<int> num(100);
  iota(begin(num), end(num), 1);

  auto it = find(begin(s), end(s), ',');

  cout << "Found ',' at position: " << distance(begin(s), it) << "\n";

  auto number = find_if(begin(num), end(num), [](int i) {
      return (i % 3 == 0 && i % 5 == 0);
  });

  cout << "Found first number divisable by 3 and 5 at positon: " << 
    distance(begin(num), number) << " (" << *number << ")\n";

  number = begin(num);
  while(number != end(num)){
    number = find_if(number, end(num), [](int i ) {
        return (i % 3 == 0 && i % 5 == 0);
    });

    if (number != end(num)) {
      cout << *number << " ";
      advance(number, 1);
    }
  }

  cout << "\n";

  return 0;

}
