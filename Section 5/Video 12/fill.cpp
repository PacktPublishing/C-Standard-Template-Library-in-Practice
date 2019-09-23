#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

struct FibGenerator {
  FibGenerator() {
    n = 1;
    n_1 = 1;
  }

  int operator()() {
    int out = n_1;
    int next = n + n_1;
    n_1 = n;
    n = next;
    return out;
  }

  private :
    int n;
    int n_1;
};

int main() {
  int values[10];

  fill(begin(values), end(values), 0);

  values[2] = 55;

  copy(begin(values), end(values), ostream_iterator<int>(cout, " "));
  cout << "\n";

  generate(begin(values), end(values), FibGenerator());

  copy(begin(values), end(values), ostream_iterator<int>(cout, " "));
  cout << "\n";

  return 0;
}
