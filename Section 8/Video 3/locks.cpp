#include <thread>
#include <iostream>
#include <mutex>

#define TRANSACTIONS 100000

using namespace std;

void deposit(int& account, mutex& m) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    {
      lock_guard<mutex> lock(m);
      ++account;
    }
  }
}

void withdraw(int& account, mutex& m) {
  for (int i = 0; i < TRANSACTIONS; i++) {
    {
      lock_guard<mutex> lock(m);
      --account;
    }
  }
}

int main() {
  unsigned int threads = thread::hardware_concurrency();

  cout << threads << " Threads supported\n";

  int account = 0;
  mutex m;

  thread t1 (deposit, std::ref(account), std::ref(m));
  thread t2 (withdraw, std::ref(account), std::ref(m));

  t1.join();
  t2.join();

  cout << "After the threads, account value is: " << account << "\n";

  return 0;
}
