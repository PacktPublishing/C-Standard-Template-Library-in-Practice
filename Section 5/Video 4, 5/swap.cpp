#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {

  int a = 10, b = 30;

  cout << "Before: " << a << " " << b << "\n";

  swap(a,b);

  cout << "After: " << a << " " << b << "\n";


  vector<string> s1 {"a", "b", "c", "d", "e", "f", "g"};
  vector<string> s2 {"h", "i", "j", "k", "l", "m", "n", "o", "p"};

  swap_ranges(begin(s1), begin(s1) + 4, begin(s2));

  for_each(begin(s1), end(s1), [](const string& s){cout << s << " ";});
  cout << "\n";

  for_each(begin(s2), end(s2), [](const string& s){cout << s << " ";});
  cout << "\n";

  auto s1_last = end(s1) - 1;
  auto s2_last = end(s2) - 1;

  iter_swap(s1_last, s2_last);

  for_each(begin(s1), end(s1), [](const string& s){cout << s << " ";});
  cout << "\n";

  for_each(begin(s2), end(s2), [](const string& s){cout << s << " ";});
  cout << "\n";


  return 0;
}
