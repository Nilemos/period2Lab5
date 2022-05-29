#pragma once
#include "Point.h"

template <class T> class TQuadrate : public TObj<T>
{
private:
  T distSq(TVector<T> p, TVector<T> q);
  bool isSquare(TVector<T> p1, TVector<T> p2, TVector<T> p3, TVector<T> p4);
protected:
  TString name;
  TVector<T> P1, P2, P3, P4;
  int dim;
public:
  TQuadrate();
  TQuadrate(int _dim);
  //TQuadrate(TPoint<T> _p1, TPoint<T> _p2, TPoint<T> _p3, TPoint<T> _p4);
  virtual void Print();
  virtual int GetDim(); 
  virtual TString GetName();
  virtual void SetName(TString& s);
  virtual TVector<T>& operator[](int i);
};

template<class T>
inline T TQuadrate<T>::distSq(TVector<T> p, TVector<T> q)
{
  return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
}

template<class T>
inline bool TQuadrate<T>::isSquare(TVector<T> p1, TVector<T> p2, TVector<T> p3, TVector<T> p4)
{
  T d2 = distSq(p1, p2);
  T d3 = distSq(p1, p3);
  T d4 = distSq(p1, p4);
  if (d2 == d3 && 2 * d2 == d4 && 2 * distSq(p2, p4) == distSq(p2, p3)) {
    return true;
  }
  if (d3 == d4 && 2 * d3 == d2 && 2 * distSq(p3, p2) == distSq(p3, p4)) {
    return true;
  }
  if (d2 == d4 && 2 * d2 == d3 && 2 * distSq(p2, p3) == distSq(p2, p4)) {
    return true;
  }
  return false;
}

template<class T>
inline TQuadrate<T>::TQuadrate()
{
  dim = 2;
  P1 = 0; P2 = 0; P3 = 0; P4 = 0;
}

template<class T>
inline TQuadrate<T>::TQuadrate(int _dim)
{
 //if (isSquare(P1,P2,P3,P4) == false) throw "Err";
  
  dim = _dim;
  P1.Resize(dim);
  P2.Resize(dim);
  P3.Resize(dim);
  P4.Resize(dim);
  if (isSquare(P1, P2, P3, P4) == false) std::cout << "Quadrate govno";
}

//template<class T>
//inline TQuadrate<T>::TQuadrate(TPoint<T> _p1, TPoint<T> _p2, TPoint<T> _p3, TPoint<T> _p4)
//{
//  if (isSquare == false) throw "Err";
//
//}

template<class T>
inline void TQuadrate<T>::Print()
{
  std::cout << "quadrate " << name;
  std::cout << "(" << P1 << "; " << P2 << "; " << P3 << "; " << P4 << ")" << std::endl;
}

template<class T>
inline int TQuadrate<T>::GetDim()
{
  return dim;
}

template<class T>
inline TString TQuadrate<T>::GetName()
{
  return name;
}

template<class T>
inline void TQuadrate<T>::SetName(TString& s)
{
  name = s;
}

template<class T>
inline TVector<T>& TQuadrate<T>::operator[](int i)
{
  if (i == 0) return P1;
  if (i == 1) return P2;
  if (i == 2) return P3;
  if (i == 3) return P4;
}
