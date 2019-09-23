#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "circular_buffer.hpp"

using namespace std;

int main() {
  CircularBuffer<int, 7> buffer;
  cout << "Buffer size: " << buffer.size() << "\n";

  for (int i = 0; i < 13; i++) {
    cout << buffer << "\n";
    cout << "Pushing " << i*10 << "\n";
    buffer.push_back(i * 10);
  }

  cout << "Buffer size now: " << buffer.size() << "\n";

  for (auto i = buffer.begin(); i != buffer.end(); ++i) {
    cout << *i << " ";
  }

  cout << endl;

  while(!buffer.empty()) {
    cout << "popping: " << buffer.head() << "\n";
    buffer.pop();
    cout << buffer << "\n";
  }

  vector<string> words{"Hello", "There", "How", "Are", "You", "Doing", "Today"};
  CircularBuffer<string, 5> strings;

  copy(begin(words), end(words), back_insert_iterator<CircularBuffer<string, 5>>(strings));

  cout << "String size: " << strings.size() << "\n";

  for (auto i = begin(strings); i != end(strings); ++i) {
    cout << "(" << *i << ":" << i->size() << ") ";
  }

  cout << endl;
}
