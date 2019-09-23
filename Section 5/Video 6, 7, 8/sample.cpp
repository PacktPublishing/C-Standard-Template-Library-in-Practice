#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
  
  string pop = "abcdefghijklmnopqrstuvwxyz";
  string select;

  mt19937 rng {random_device{}()};
  
  sample(begin(pop), end(pop), back_inserter<string>(select), 5, rng);

  cout << "Selected: " << select << "\n";

  return 0;
}
