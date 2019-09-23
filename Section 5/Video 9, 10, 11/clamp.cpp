#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <cstdint>

using namespace std;

int main() {
  int counter = 0;

  mt19937 rng{random_device{}()};
  uniform_int_distribution<> dist(-400, 400);

  for (int i = 0; i < 100; i++){
    int v = dist(rng);
    cout << 
      counter++ << "," <<
      v << "," <<
      clamp(v, INT8_MIN, INT8_MAX) << "," <<
      clamp(v, 0, UINT8_MAX) << "," <<
      clamp(v, -30, 30) << "\n";
  }

  string s = "Hello, World! I am pleased to be here!";
  string out;

  transform(begin(s), end(s), back_inserter<string>(out), [](const char& c) {
        return clamp(c, 'd', 'o');
      });

  cout << s << "\n";
  cout << out << "\n";

  return 0;
}
