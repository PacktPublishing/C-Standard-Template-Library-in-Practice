#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << "Here is a double: " << 18.90d << "\n";
  cout << "Here is a char: " << 'J' << "\n";
  cout << "Here is an int: " << 101 << "\n";

  string val = "Here is a string from a variable,";
  double pi = 3.1415;
  cout << val << " it can be combined with other things like " << pi << "\n";
  cout << "Outputs to UTF-8, so it supports a huge character set, including emoji!\n";


  string face = "How about a \U0001f60a?";
  cout << face << "\n";
}
