#include <iostream>
#include "StackList.h"
#include "QueueList.h"

int main()
{
  TStackList<int> s;
  TQueueList<int> q;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Pop();
  cout << s << endl;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Pop();
  q.Push(4);
  cout << q;

  return 0;
}
