#include <iostream>

template<typename T>
class Container {
  T t;

  public : 
  explicit Container(T t) : t(t) {

  }

  friend std::ostream& operator<<(std::ostream& os, const Container<T>& c) {
    return (os << "Container holding: " << c.t);
  }
};

template<typename X>
bool isGreator(X x1, X x2) {
  return x1 > x2;
}

//Specialization of template
template<>
bool isGreator(int x1, int x2) {
  std::cout << "Specialized int\n";
  return x1 > x2;
}

using namespace std;

int main() {

  cout << std::boolalpha;

  //Use some templated classes
  Container<int> c(100);
  Container<string> s("Some string");
  cout << c << "\n";
  cout << s << "\n";

  //use our templated function
  
  cout << isGreator<int>(5, 10) << "\n";
  cout << isGreator(45.827, 12.0) << "\n";
  cout << isGreator("ZZZ", "AAAA") << "\n";
  cout << isGreator('c', 'r') << "\n";

  //C++20, use a templated lambda
  auto f = [] <typename T> (T t1, T t2) {
    return t1 == t2;
  }; 

  cout << "Lambda returns : " << f(10, 10) << "\n";

  [] <typename X> (X x) {
    cout << x << endl;
  }("Hello");

  return 0;
}
