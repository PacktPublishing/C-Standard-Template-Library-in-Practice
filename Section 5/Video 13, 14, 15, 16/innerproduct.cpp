#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

int main() {
  vector<int> set1(20);
  vector<int> set2(20);

  iota(begin(set1), end(set1), 1);
  iota(begin(set2), end(set2), 10);

  copy(begin(set1), end(set1), ostream_iterator<int>(cout, " "));
  cout << "\n";
  copy(begin(set2), end(set2), ostream_iterator<int>(cout, " "));
  cout << "\n";

  int v = inner_product(begin(set1), end(set1), begin(set2), 0);

  cout << "inner product is: " << v << endl;

  v = inner_product(begin(set1), end(set1), begin(set2), 1, 
      std::plus<int>(), std::plus<int>());

  cout << "sum of sums is: " << v << endl;

  vector<bool> bits1 {true, true, false, true, false, true, true, false};
  vector<bool> bits2 {false, false, true, false, true, false, false, true};

  bool allTrue = inner_product(begin(bits1), end(bits1), begin(bits2), true,
      std::bit_xor<bool>(), std::logical_or<bool>());

  cout << "Data parity: " << (allTrue ? "Good" : "BAD") << "\n";

  return 0;
}
