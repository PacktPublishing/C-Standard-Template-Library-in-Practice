#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
  string s = "This is some string";
  vector<int> n {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << s << "\n";
  replace(begin(s), end(s), 's', 'B');
  cout << s << "\n";

  for_each(begin(n), end(n), [](int i) {cout << i << " ";});
  cout << "\n";
  
  replace_if(begin(n), end(n), [](int i) -> bool { return i >= 7; }, 6);

  for_each(begin(n), end(n), [](int i) {cout << i << " ";});
  cout << "\n";

  return 0;
}
