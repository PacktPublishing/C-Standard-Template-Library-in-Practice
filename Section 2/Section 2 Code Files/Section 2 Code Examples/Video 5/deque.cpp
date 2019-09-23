#include <deque>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {

  //Deque
  deque<int> transactions {1, 2, 3, 4};

  transactions.push_front(100);
  transactions.push_front(300);
  transactions.push_back(500);
  transactions.push_back(800);

  int* i = &transactions[0];
  cout << *(i + 2) << endl;

  for (unsigned int i = 0; i < transactions.size(); i++) {
    cout << transactions[i] << " ";
  }

  cout << "\n";

  //Stack
  stack<int> stack;

  stack.push(100);
  stack.push(200);
  stack.push(300);
  stack.push(400);

  while(!stack.empty()) {
    cout << stack.top() << " ";
    stack.pop();
  }

  cout << "\n";


  //Queue
  queue<int> queue;
  queue.push(100);
  queue.push(200);
  queue.push(300);
  queue.push(400);

  while(!queue.empty()) {
    cout << queue.front() << " ";
    queue.pop();
  }

  cout << "\n";

  //Priority Queue
  priority_queue<int> pqueue;
  pqueue.push(200);
  pqueue.push(600);
  pqueue.push(100);
  pqueue.push(400);
  pqueue.push(40);
  pqueue.push(3000);

  while(!pqueue.empty()) {
    cout << pqueue.top() << " ";
    pqueue.pop();
  }

  cout << "\n";


  return 0;
}
