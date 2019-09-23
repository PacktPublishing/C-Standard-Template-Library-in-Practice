#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers {1, 1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 7, 7, 7, 8, 9, 10, 10, 11};

  bool exists = binary_search(begin(numbers), end(numbers), 7);

  if (exists) {
    cout << "Found the number\n";
  }
  else {
    cout << "Number not found\n";
  }

  auto [lower, upper] = equal_range(begin(numbers), end(numbers), 3);

  cout << "Found 3 between [" << distance(begin(numbers), lower) << " and " <<
    distance(begin(numbers), upper) << ")\n";

  lower = lower_bound(begin(numbers), end(numbers), 10);
  upper = upper_bound(begin(numbers), end(numbers), 10);

  cout << "Found 10 between [" << distance(begin(numbers), lower) << " and " <<
    distance(begin(numbers), upper) << ")\n";



  return 0;
}
