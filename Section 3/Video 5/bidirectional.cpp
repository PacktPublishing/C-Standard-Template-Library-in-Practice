#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//Note: show with gdb debugger if needed
int main() {
  
  vector<int> numbers {1, 2, 3, 4, 5};

  //Note that numbers.end() points to 1 past the end, and 
  //that we use ++it because it++ is the same as 
  //temp a = it; ++it; return a;
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    *it *= 10;
  }

  for (auto it = std::prev(numbers.end()); it >= numbers.begin(); --it) {
    *it -= 5;
  }

  for (int i : numbers) {
    cout << i << " ";
  }

  cout << "\n";

  return 0;
}
