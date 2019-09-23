#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;

int main() {
  vector<int> numbers {10, 3, -5, 12, 5, 35, 11, -19};

  int sum = accumulate(begin(numbers), end(numbers), 0);
  long product = accumulate(begin(numbers), end(numbers), 1, std::multiplies<long>());

  cout << "Sum: " << sum << "\n";
  cout << "Product: " << product << "\n";

  sum = reduce(begin(numbers), end(numbers), 0);
  product = reduce(begin(numbers), end(numbers), 1, std::multiplies<long>());

  cout << "Sum: " << sum << "\n";
  cout << "Product: " << product << "\n";

  return 0;
}
