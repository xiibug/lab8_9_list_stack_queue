#include "StackList.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TStackList, can_create_stack_list)
{
  ASSERT_NO_THROW(TStackList<int>());
}

TEST(TStackList, can_push_any_elements)
{
  TStackList<int> S;
  S.Push(1);
  S.Push(2);
  EXPECT_EQ(2, S.Get());
}

TEST(TStackList, can_pop_any_elements)
{
  TStackList<int> S;
  S.Push(1);
  S.Push(2);
  S.Push(3);
  S.Pop();
  S.Pop();
  EXPECT_EQ(1, S.Get());
}

//доп задания

TEST(TStackList, can_find_max_element)
{
  TStackList<int> S;
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(2, S.GetMaxElem());
}

TEST(TStackList, can_find_min_element)
{
  TStackList<int> S;
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(-1, S.GetMinElem());
}

TEST(TStackList, can_write_stack_list_to_file)
{
  const int size = 9;
  TStackList<int> S;
  for (int i = 0; i < size / 2; i++)
    S.Push(i);
  S.WriteToFile("output_s.txt");
  string expS = "0123";
  string Stack = "";
  ifstream fin("output_s.txt");
  fin >> Stack;
  fin.close();
  EXPECT_EQ(expS, Stack);
}


