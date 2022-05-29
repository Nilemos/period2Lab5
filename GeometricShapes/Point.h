#pragma once
#include "Obj.h"

template <class T> class TPoint : public TObj<T>
{
protected:
  TString name;
  TVector<T> point;
  int dim;
public:
  TPoint(int _dim);
  virtual void Print();
  virtual int GetDim();
  virtual TString GetName();
  virtual void SetName(TString& s);
  virtual TVector <T>& operator[](int i);
  TPoint<T> operator=(const TPoint<T>& p);
};

template<class T>
inline TPoint<T>::TPoint(int _dim)
{
  dim = _dim;
  point.Resize(dim);
}

template<class T>
inline void TPoint<T>::Print()
{
  std::cout << "point " << name << " " << point;
}

template<class T>
inline int TPoint<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString TPoint<T>::GetName()
{
  return name;
}

template<class T>
inline void TPoint<T>::SetName(TString& s)
{
  name = s;
}

template<class T>
inline TVector<T>& TPoint<T>::operator[](int i)
{
  return point;
}

template<class T>
inline TPoint<T> TPoint<T>::operator=(const TPoint<T>& p)
{
  TPoint<T> pop(p.dim);
  return pop;
}
