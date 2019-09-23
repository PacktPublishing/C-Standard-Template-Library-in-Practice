#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>

using namespace std;

void partialSum(vector<int>::iterator start, 
    vector<int>::iterator end, promise<int> promise) {

  int x = 0;
  x = accumulate(start, end, x);
  promise.set_value(x);
}

// Note: Show running with htop 
int main() {
  cout << "Generatring vector\n";
  vector<int> numbers(900'000'000, 2);

  int numberOfThreads = thread::hardware_concurrency();
  vector<future<int>> futures;

  int offset = 0;
  int chunk = numbers.size() / numberOfThreads;

  cout << "Running sum on " << numberOfThreads << " threads\n";
  for (int i = 0; i < numberOfThreads; i++) {
    promise<int> p;
    futures.push_back(p.get_future());
    cout << "Summing " << offset << " to " << offset + chunk << "\n";
    thread t (partialSum, numbers.begin() + offset, numbers.begin() + offset + chunk, 
        std::move(p));
    t.detach();
    offset += chunk;
  }

  int sum = 0;

  for (future<int>& f : futures) {
    f.wait();
    sum += f.get();
  }

  cout << "Sum of numbers is: " << sum << "\n";

  return 0;
}
