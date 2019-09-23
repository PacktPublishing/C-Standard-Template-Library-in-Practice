#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

int main() {
  string s = "This is some string of LETTERS and Numbers 1234565 21";
  vector<double> n1 {1.4, 0.3, -0.4, 5.6, 1.2};
  vector<double> n2 {2.4, -0.3, 1.87, 4.3, .8};
  
  string lower;
  transform(begin(s), end(s), back_inserter<string>(lower), [](unsigned char c) {
        return std::tolower(c);
      });

  cout << lower << "\n";

  vector<double> result;
  transform(begin(n1), end(n1), begin(n2), back_inserter<vector<double>>(result),
      [](const double& d1, const double& d2) { return d1 + d2; });

  for_each(begin(result), end(result), [](double& d) {cout << d << " "; });
  cout << "\n";

  return 0;
}
