#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers {2, 4, 6, 8, 10, 12, 14};
  int arr[]{1, 3, 5, 7, 9, 11, 13};

  for (auto it = begin(numbers); it != end(numbers); ++it) {
    cout << *it << " ";   
  }

  cout << "\n";

  for (auto it = begin(arr); it != end(arr); ++it) {
    cout << *it << " ";
  }

  cout << "\n";


  auto thirdElm = next(next(begin(numbers)));
  cout << "Third element of numbers is: " << *thirdElm << "\n";

  cout << "Third element of arr is: " << *(next(next(begin(arr))))<< "\n";

  cout << "There are " << distance(begin(numbers), end(numbers)) << " numbers\n";
  cout << "and " << distance(begin(arr), end(arr)) << " array numbers\n";

  return 0;
}
