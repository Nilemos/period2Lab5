#pragma once
#include "Point.h"

template <class T> class TPolygon : public TObj<T>
{
protected:
  TString name;
  TVector<TPoint<T>> points;
  int dim;
  int colVertexes;
public:
  TPolygon(int _dim, int _colV);
  virtual void Print();
  virtual int GetDim();
  virtual TString GetName();
  virtual void SetName(TString& s);
  virtual TVector<T>& operator[](int i);
};

template<class T>
inline TPolygon<T>::TPolygon(int _dim, int _colV)
{
  dim = _dim;
  colVertexes = _colV;
  for (int i = 0; i < colVertexes; i++)
  {
    TPoint<T> pop(dim);
    points[i] = pop;
  }
}

template<class T>
inline void TPolygon<T>::Print()
{
  std::cout << "polygon " << name << "\n";
  for (int i = 0; i < colVertexes; i++)
  {
    std::cout << points[i][0] << "\n";
  }
}

template<class T>
inline int TPolygon<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString TPolygon<T>::GetName()
{
  return name;
}

template<class T>
inline void TPolygon<T>::SetName(TString& s)
{
  name = s;
}

template<class T>
inline TVector<T>& TPolygon<T>::operator[](int i)
{
  return points[i][0];
}