#include <thread>
#include <iostream>

#define TRANSACTIONS 100000

using namespace std;

void deposit(int& account) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    ++account;
  }
}

void widthdraw(int& account) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    --account;
  }
}

int main() {
  unsigned int threads = thread::hardware_concurrency();

  cout << threads << " Threads supported\n";

  int account = 0;
  thread t1 (deposit, std::ref(account));
  thread t2 (widthdraw, std::ref(account));

  t1.join();
  t2.join();

  cout << "After the threads, account value is: " << account << "\n";

  return 0;
}
