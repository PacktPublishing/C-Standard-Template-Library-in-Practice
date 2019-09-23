#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <functional>

using namespace std;

auto searchString(const string& ref, const string& s, 
    function<bool(unsigned char, unsigned char)> pred = 
      std::equal_to<unsigned char>()) {

  return search(begin(ref), end(ref), begin(s), end(s), pred);
}

std::function<bool(unsigned char, unsigned char)> equal_ignore_case = 
  [](unsigned char rc, unsigned char sc) -> bool {
    return tolower(rc) == tolower(sc);
  };

int main() {
  string dna = "GATATATACAGGTACCCAATTTACAGATACAAATTTTAAGGAAGAGATATACACACA";
  string text = "Can i match my name JaMeS?";

  auto it = searchString(dna, "GATACA");
  if (it != end(dna)) {
    cout << "Found GATACA at position: " << distance(cbegin(dna), it) << "\n";
  }

  it = searchString(text, "james", equal_ignore_case);
  if (it != end(text)) {
    cout << "Found james at position: " << distance(cbegin(text), it) << "\n";
  }

  return 0;
}
