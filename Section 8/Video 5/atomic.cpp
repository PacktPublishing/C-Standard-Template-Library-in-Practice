#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>

using namespace std;

void deposit(std::atomic<int>& account) {
  account++;
}

void withdraw(std::atomic<int>& account) {
  account--;
}

int main() {

  atomic<int> account(1000);
  
  cout << "Starting amount: " << account.load() << "\n";

  for (int i = 0; i < 100; i++) {
    thread t(&deposit, std::ref(account));
    t.detach();
  }

  for (int i = 0; i < 250; i++) {
    thread t(&withdraw, std::ref(account));
    t.detach();
  }

  this_thread::sleep_for(2s);

  cout << "Final amount: " << account.load() << "\n";

  return 0;
}
