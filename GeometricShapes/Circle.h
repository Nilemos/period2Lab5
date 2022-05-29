#pragma once
#include "Obj.h"

template <class T> class TCircle : public TObj<T>
{
protected:
  TString name;
  TVector<T> point;
  T r;
  int dim;
public:
  TCircle(int _dim);
  virtual void Print();
  virtual int GetDim();
  virtual TString GetName();
  virtual void SetName(TString& s);
  virtual TVector<T>& operator[](int i);
  int GetR();
  void SetR(T _r);
};

template<class T>
inline TCircle<T>::TCircle(int _dim)
{
  r = 0;
  dim = _dim;
  point.Resize(dim);
}

template<class T>
inline void TCircle<T>::Print()
{
  std::cout << "circle " << name << " " << point << " with radius " << r << "\n";
}

template<class T>
inline int TCircle<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString TCircle<T>::GetName()
{
  return name;
}

template<class T>
inline void TCircle<T>::SetName(TString& s)
{
  name = s;
}

template<class T>
inline TVector<T>& TCircle<T>::operator[](int i)
{
  return point;
}

template<class T>
inline int TCircle<T>::GetR()
{
  return r;
}

template<class T>
inline void TCircle<T>::SetR(T _r)
{
  r = _r;
}