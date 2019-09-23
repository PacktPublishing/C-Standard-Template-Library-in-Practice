#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <vector>

using namespace std;

int main() {

  // I want to show that if the seed is known, so is every "random" number
  mt19937 rng1(100);
  mt19937 rng2(100);

  for (int i = 0; i < 10; ++i) {
    cout << "RNG1: " << rng1() << ", ";
    cout << "RNG2: " << rng2() << "\n";
  }


  // Now lets re-seed with random entropy 
  rng1.seed(random_device{}());
  rng2.seed(random_device{}());

  for (int i = 0; i < 10; ++i) {
    cout << "RNG1: " << rng1() << ", ";
    cout << "RNG2: " << rng2() << "\n";
  }


  vector<int> n {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for_each(begin(n), end(n), [](auto& i){cout << i << " ";});
  cout << "\n";

  shuffle(begin(n), end(n), rng1);

  for_each(begin(n), end(n), [](auto& i){cout << i << " ";});
  cout << "\n";

  return 0;
}
