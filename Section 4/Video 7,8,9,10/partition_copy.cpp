#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cctype>

using namespace std;

int main() {

  function<bool(unsigned char)> pred = [](unsigned char c) -> bool { 
    return isupper(c);
  };

  string s = "This Is Some String Of Text In Mixed Case";

  string s_true;
  string s_false;

  partition_copy(begin(s), end(s), back_inserter(s_true), back_inserter(s_false), pred);

  cout << s_true << "\n";
  cout << s_false << "\n";
   
  return 0;
}
