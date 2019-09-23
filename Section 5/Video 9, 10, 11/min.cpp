#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

int main() {

  cout << min("Hello", "world") << " is smaller\n";
  cout << min(45, 51) << " is smaller\n";

  cout << min("AAAA"s, "XX"s, [](const string& s1, const string& s2){
      return s1.size() < s2.size();
  }) << " is shorter\n";

  cout << min({ 42, 5, 63, 14, 0, 41}) << " is smaller\n";

  vector<double> d {1.3, 6.12, 0.54353, 1.000, -5.0, 0.001};

  auto it = min_element(begin(d), end(d));

  cout << *it << " is the smallest\n";

  it = min_element(begin(d), end(d), [](const double& a, const double& b) {
      return abs(a) < abs(b);
    });


  cout << *it << " is the smallest absolute value\n";

  return 0;
}
