#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;

template<typename ForwardIt>
void print(ForwardIt begin, ForwardIt end) {
  for_each(begin, end, [](const auto& a) {
        cout << a << " ";
      });

  cout << "\n";
}

int main() {

  vector<int> num {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  vector<int> out;

  partial_sum(begin(num), end(num), back_inserter<vector<int>>(out));
  
  print(begin(out), end(out));
  out.clear();

  partial_sum(begin(num), end(num), back_inserter<vector<int>>(out), multiplies<int>());
  
  print(begin(out), end(out));

  vector<int> diff;
  
  adjacent_difference(begin(out), end(out), back_inserter<vector<int>>(diff));

  print(begin(diff), end(diff));

  vector<int> fib(15, 0);
  fib[0] = 1;

  adjacent_difference(begin(fib), prev(end(fib)), next(begin(fib)), plus<int>());

  print(begin(fib), end(fib));

  return 0;
}
