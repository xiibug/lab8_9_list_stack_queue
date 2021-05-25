#pragma once

#include "List.h"

template <class T>
class TQueueList
{
protected:
  TList<T> list;
public:
  TQueueList();
  TQueueList(const TQueueList<T>& q);
  ~TQueueList();

  TQueueList<T>& operator=(const TQueueList<T>& q);

  void Push(T n);
  void Pop();
  T Get();

  bool IsEmpty();
  bool IsFull();

  int Length();

  template <class T1>
  friend ostream& operator<<(ostream& ostr, const TQueueList<T1>& Q);
  template <class T1>
  friend istream& operator>>(istream& istr, TQueueList<T1>& Q);

  T GetMaxElem();
  T GetMinElem();

  void WriteToFile(string name);

  template <class T1>
  friend ofstream& operator<<(ofstream& ofstr, TQueueList<T1>& Q);
};

template<class T>
inline TQueueList<T>::TQueueList()
{
}

template<class T>
inline TQueueList<T>::TQueueList(const TQueueList<T>& q)
{
  this->list = q.list;
}

template<class T>
inline TQueueList<T>::~TQueueList()
{
}

template<class T>
inline TQueueList<T>& TQueueList<T>::operator=(const TQueueList<T>& q)
{
  if (this == &q)
    return *this;

  this->list = q.list;

  return *this;
}

template<class T>
inline void TQueueList<T>::Push(T n)
{
  list.InsLast(n);
}

template<class T>
inline void TQueueList<T>::Pop()
{
  list.DelFirst();
}

template<class T>
inline T TQueueList<T>::Get()
{
  if (list.IsEmpty())
    throw - 1;
  return list.GetFirst()->GetData();
}

template<class T>
inline bool TQueueList<T>::IsEmpty()
{
  return list.IsEmpty();
}

template<class T>
inline bool TQueueList<T>::IsFull()
{
  return list.IsFull();
}

template<class T>
inline int TQueueList<T>::Length()
{
  return list.GetCount();
}

template <class T1>
ostream& operator<<(ostream& ostr, const TQueueList<T1>& Q)
{
  return ostr << Q.list;
}

template <class T1>
istream& operator>>(istream& istr, TQueueList<T1>& Q)
{
  return istr >> Q.list;
}


template<class T>
inline T TQueueList<T>::GetMaxElem()
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
inline T TQueueList<T>::GetMinElem()
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
inline void TQueueList<T>::WriteToFile(string name)
{
  ofstream fout(name.c_str());
  fout << *this;
  fout.close();
}

template<class T1>
inline ofstream& operator<<(ofstream& ofstr, TQueueList<T1>& Q)
{
  return ofstr << Q.list;
}

