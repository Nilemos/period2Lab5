#pragma once
#include "Obj.h"


template <class T> class TCollection
{
  protected:
    TVector<TObj<T>*> arr;
  public:
    void Print();
    TObj<T>* operator[](TString& s);
    TVector<TString> GetNames();
    void Add(TObj<T>* o);
    void Del(TString& s);
    TCollection();
};

template<class T>
inline void TCollection<T>::Print()
{
  for (int i = 0; i < arr.GetLen(); i++)
  {
    arr[i]->Print();
  }
}

template<class T>
inline TObj<T>* TCollection<T>::operator[](TString& s)
{
  for (int i = 0; i < arr.GetLen(); i++)
  {
    if (arr[i]->GetName() == s)
    {
      return arr[i];
    }
  }
  return 0;
}

template<class T>
inline TVector<TString> TCollection<T>::GetNames()
{
  TVector<TString> res(arr.GetLen());
  for (int i = 0; i < arr.GetLen(); i++)
  {
    res[i] = arr[i]->GetName();
  }
  return res;
}

template<class T>
inline void TCollection<T>::Add(TObj<T>* o)
{
  if (o == 0)
  {
    throw "cant add 0";
  }
  arr.Resize(arr.GetLen() + 1);
  arr[arr.GetLen() - 1] = o;
}

template<class T>
inline void TCollection<T>::Del(TString& s)
{
  for (int i = 0; i < arr.GetLen(); i++)
  {
    if (arr[i]->GetName() == s)
    {
      for (int j = i + 1; j < arr.GetLen(); j++)
      {
        arr[j - 1] = arr[j];
      }
    }
  }
  arr.Resize(arr.GetLen() - 1);
}

template<class T>
inline TCollection<T>::TCollection()
{
}