#pragma once

#include "List.h"

template <class T>
class TStackList
{
protected:
  TList<T> list;
public:
  TStackList();
  TStackList(const TStackList<T>& s);
  ~TStackList();

  TStackList<T>& operator=(const TStackList<T>& s);

  void Push(T n);
  void Pop();
  T Get();

  bool IsEmpty();
  bool IsFull();

  int Length();

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TStackList<T1>& S);
  template <class T1>
  friend istream& operator>>(istream& istr, TStackList<T1>& S);

  T GetMaxElem();
  T GetMinElem();

  void WriteToFile(string name);

  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, TStackList<T1>& S);
};

template<class T>
inline TStackList<T>::TStackList()
{
}

template<class T>
inline TStackList<T>::TStackList(const TStackList<T>& s)
{
  this->list = s.list;
}

template<class T>
inline TStackList<T>::~TStackList()
{
}

template<class T>
inline TStackList<T>& TStackList<T>::operator=(const TStackList<T>& s)
{
  if (this == &s)
    return *this;

  this->list = s.list;

  return *this;
}

template<class T>
inline void TStackList<T>::Push(T n)
{
  list.InsLast(n);
}

template<class T>
inline void TStackList<T>::Pop()
{
  list.DelLast();
}

template<class T>
inline T TStackList<T>::Get()
{
  if (list.IsEmpty())
    throw - 1;
  return list.GetLast()->GetData();
}

template<class T>
inline bool TStackList<T>::IsEmpty()
{
  return list.IsEmpty();
}

template<class T>
inline bool TStackList<T>::IsFull()
{
  return list.IsFull();
}

template<class T>
inline int TStackList<T>::Length()
{
  return list.GetCount();
}

template <class T1>
ostream& operator<<(ostream& ostr, const TStackList<T1>& S)
{
  return ostr << S.list;
}

template <class T1>
istream& operator>>(istream& istr, TStackList<T1>& S)
{
  return istr >> S.list;
}

template<class T>
inline T TStackList<T>::GetMaxElem()
{
  if (IsEmpty())
    throw - 1;

  TListIterator<T> itr = list.begin();
  int ans = *itr;
  ++itr;

  for (; !itr.IsEmpty(); ++itr)
    if (*itr > ans)
      ans = *itr;;

  return ans;
}

template<class T>
inline T TStackList<T>::GetMinElem()
{
  if (IsEmpty())
    throw - 1;

  TListIterator<T> itr = list.begin();
  int ans = *itr;
  ++itr;

  for (; !itr.IsEmpty(); ++itr)
    if (*itr < ans)
      ans = *itr;;

  return ans;
}

template<class T>
inline void TStackList<T>::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, TStackList<T1>& S)
{
  return ofstr << S.list;
}
