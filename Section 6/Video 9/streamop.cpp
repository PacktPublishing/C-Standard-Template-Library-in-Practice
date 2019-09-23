#include <iostream>

using namespace std;

class Student {
  private:
    int studentId;
    string first;
    string last;
    int age;

  public:
    Student() : studentId{}, first({}), last({}), age{} {}
    
    Student(int studentId, const string& first, const string& last, int age) :
      studentId(studentId), first(first), last(last), age(age) {}

    int getStudentId() {
      return this->studentId;
    }

    const string& getFirst() {
      return this->first;
    }

    const string& getLast() {
      return this->last;
    }

    int getAge() {
      return this->age;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
      os << "{\"student\" : {\"studentId\":" << s.studentId << ",";
      os << "\"first\":\"" << s.first << "\",";
      os << "\"last\":\"" << s.last << "\",";
      os << "\"age\":" << s.age << "}}";
      return os;
    }

    friend istream& operator>>(istream& is, Student& s) {
      is >> s.studentId;
      is >> s.first;
      is >> s.last;
      is >> s.age;
      return is;
    }
};

int main() {
  Student s{1, "James", "Slocum", 34};
  cout << s << endl;

  Student s2;
  cin >> s2;

  cout << s2 << endl;
  return 0;
}
