#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

struct Student {
  const int id;
  const string first;
  const string last;

  Student(int id, string first, string last) : id(id), first(first), last(last) {}
};

int main() {
  vector<int> numbers {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 8};
  vector<Student> students;

  students.emplace_back(0, "James", "Slocum");
  students.emplace_back(1, "John", "Smith");
  students.emplace_back(2, "Brian", "Richards");
  students.emplace_back(3, "Tina", "Blake");

  cout << "There are " << count(begin(numbers), end(numbers), 5) << " 5s in the vector\n";

  int sCount = count_if(begin(students), end(students), [](const Student& s) {
      return (tolower(s.last.c_str()[0]) == 's');
  });

  cout << sCount << " Students have a last name with 'S'\n";

  return 0;
}
