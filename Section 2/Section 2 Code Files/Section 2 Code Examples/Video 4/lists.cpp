#include <list>
#include <iostream>

using namespace std;

int main() {
  list<int> mylist {10, 20, 25, 30, 40, 50};
  list<int> other {15, 25, 35, 45, 50, 55};

  mylist.merge(other);

  cout << "list size = " << mylist.size() << "\n";

  for (auto i = mylist.begin(); i != mylist.end(); ++i){
    cout << *i << " ";
  }

  cout << "\n";

  //Only hold unique elements
  mylist.unique();
  for (auto i = mylist.begin(); i != mylist.end(); ++i){
    cout << *i << " ";
  }

  cout << "\n";

  return 0;
}
