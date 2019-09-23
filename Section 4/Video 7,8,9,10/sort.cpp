#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string toLowerCase(const string& s) {
  string temp;
  std::transform(begin(s), end(s), back_insert_iterator<string>(temp),  
      [](unsigned char c){return tolower(c);});

  return temp;
}

int main() {
  vector<int> numbers{1, 2, 6, 12, 48, 1, 4, 2, 10, 54, 12};
  vector<string> words{"Hello", "hello", "zebra", "x-ray", "apple", "123", "Apple"};

  auto it = is_sorted_until(begin(numbers), end(numbers));
  cout << "Numbers is sorted for " << distance(begin(numbers), it) << " elements\n";

  cout << std::boolalpha;
  cout << "numbers is sorted: " << is_sorted(begin(numbers), end(numbers)) << "\n";

  sort(begin(numbers), end(numbers));
  sort(begin(words), end(words));

  cout << "numbers is sorted: " << is_sorted(begin(numbers), end(numbers)) << "\n";

  for_each(begin(numbers), end(numbers), [](int i) {cout << i << " ";});
  cout << "\n";

  for_each(begin(words), end(words), [](auto s){cout << s << " ";});
  cout << "\n";

  //Note: I did not modify the contents duing sort, only sorted on 
  //copied values
  sort(begin(words), end(words), [](const auto& s1, const auto& s2) {
    return toLowerCase(s1) < toLowerCase(s2);
  });
 
  for_each(begin(words), end(words), [](auto s){cout << s << " ";});
  cout << "\n";

  return 0;

}
