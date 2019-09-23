#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  stringstream ss;

  ss << 25 << " " << 50 << " " << 75 << " ";

  cout << ss.str() << "\n";

  int i = 0;
  ss >> i;

  cout << i << "\n";

  ss << 100;

  cout << ss.str() << "\n";

  while(!ss.eof()) {
    ss >> i;
    cout << i << "\n";
  }

  ss.clear(); //Remove the EOF state

  vector<int> v(10);
  iota(begin(v), end(v), 1);

  copy(begin(v), end(v), ostream_iterator<int>(ss, " "));

  cout << ss.str() << "\n";

  cout << "Reading again\n";
  while(!ss.eof()) {
    ss >> i;
    cout << i << "\n";
  }

  return 0;
}
