#include <iostream>
#include <memory>

using namespace std;

int main() {
  // the deprecated way to access an allocator
  std::allocator<int> a1;
  std::allocator<double> a2;

  int* i = a1.allocate(1);
  cout << i << ": " << *i << "\n";
  a1.construct(i, 123);
  cout << i << ": " << *i << "\n";

  cout << "allocating 5 doubles\n";
  double* d = a2.allocate(5);

  for (int i = 0; i < 5; i++) {
    cout << &d[i] << ": " << d[i] << "\n";
  }

  cout << "constructing d and d[2] only\n";
  a2.construct(&d[2], 3.14159);
  a2.construct(d, 999.123);

  for (int i = 0; i < 5; i++) {
    cout << &d[i] << ": " << d[i] << "\n";
  }

  a1.destroy(i);
  a1.deallocate(i, 1);

  a2.destroy(d);
  a2.destroy(&d[2]);
  a2.deallocate(d, 5);

  // The correct way to access an allocator
  int* x = allocator_traits<std::allocator<int>>::allocate(a1, 1);
  allocator_traits<std::allocator<int>>::construct(a1, x, 9876);

  cout << "x addr="<< x << ": " << *x << "\n";
  allocator_traits<std::allocator<int>>::deallocate(a1, x, 1);
  return 0;
}
