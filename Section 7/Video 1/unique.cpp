#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
  private : 
    int id;
    string first;
    string last;

  public: 
    Student(int id, const string& first, const string& last) :
      id(id), first(first), last(last) {}

    Student() :
      id{}, first({}), last({}) {}

    int getId() {
      return id;
    }

    const string& getFirst() const {
      return first;
    }

    const string& getLast() const {
      return last;
    }
};

class StudentDeleter {
  public :
    void operator()(Student* s) const {
      cout << "StudentDeleter: deleting " << s->getFirst() 
        << " " << s->getLast() << "\n";
      delete s;
    }
};

int main() {
 
  unique_ptr<Student> s1(new Student(1, "John", "Smith"));
  unique_ptr<Student> s2 = make_unique<Student>(2, "Mike", "Richards");
  unique_ptr<Student> s3 = make_unique<Student>();

  StudentDeleter d;
  Student* james = new Student(3, "James", "Slocum");

  unique_ptr<Student, StudentDeleter> j (james, d);

  unique_ptr<Student> n = nullptr;

}
