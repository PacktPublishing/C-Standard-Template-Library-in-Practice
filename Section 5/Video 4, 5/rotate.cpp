#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main() {

  vector<int> i {0, 1, 2, 3, 4, 5, 6, 7};
  for_each(begin(i), end(i), [](const auto& i){cout << i << " ";});
  cout << "\n";


  rotate(begin(i), begin(i) + 2, end(i));

  for_each(begin(i), end(i), [](const auto& i){cout << i << " ";});
  cout << "\n";

  rotate_copy(rbegin(i), rbegin(i) + 5, rend(i), ostream_iterator<int>(cout, " "));
  cout << "\n";

  return 0;
}
