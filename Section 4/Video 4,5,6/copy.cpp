#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7 ,8, 9, 10};
  vector<int> v_copy;

  copy(begin(v), end(v), back_inserter(v_copy));

  copy(begin(v_copy), end(v_copy), ostream_iterator<int>(cout, " "));
  cout << "\n";

  v_copy.clear();

  copy_if(begin(v), end(v), back_inserter(v_copy), [](int i) { return i%3 == 0;});

  copy(begin(v_copy), end(v_copy), ostream_iterator<int>(cout, " "));
  cout << "\n";


  auto it = begin(v);
  advance(it, 3);
  copy_n(it, 5, back_inserter(v_copy));

  copy(begin(v_copy), end(v_copy), ostream_iterator<int>(cout, " "));
  cout << "\n";

  return 0;
}
