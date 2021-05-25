#include "QueueList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TQueueList, can_create_queue_list)
{
  ASSERT_NO_THROW(TQueueList<int>());
}

TEST(TQueueList, can_push_any_elements)
{
  TQueueList<int> Q;
  Q.Push(1);
  Q.Push(2);
  EXPECT_EQ(1, Q.Get());
}

TEST(TQueueList, can_pop_any_elements)
{
  TQueueList<int> Q;
  Q.Push(1);
  Q.Push(2);
  Q.Push(3);
  Q.Push(4);
  Q.Pop();
  Q.Pop();
  Q.Push(5);
  Q.Pop();
  EXPECT_EQ(4, Q.Get());
}

//доп задачи

TEST(TQueueList, can_find_max_element)
{
  TQueueList<int> Q;
  Q.Push(1);
  Q.Push(2);
  Q.Push(-1);
  EXPECT_EQ(2, Q.GetMaxElem());
}

TEST(TQueueList, can_find_min_element)
{
  TQueueList<int> Q;
  Q.Push(1);
  Q.Push(2);
  Q.Push(-1);
  EXPECT_EQ(-1, Q.GetMinElem());
}

TEST(TQueueList, can_write_queue_list_to_file)
{
  const int size = 9;
  TQueueList<int> Q;
  for (int i = 0; i < size / 2; i++)
    Q.Push(i);
  Q.WriteToFile("output_q.txt");
  string expS = "0123";
  string Queue = "";
  ifstream fin("output_q.txt");
  fin >> Queue;
  fin.close();
  EXPECT_EQ(expS, Queue);
}