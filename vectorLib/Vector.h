#pragma once
#include <iostream>

template <class T>
class TVector
{
protected:
  T* data;
  int len;
public:
  TVector();
  TVector(int n);
  TVector(const TVector<T>& p);
  ~TVector();
  TVector<T> operator+(const TVector<T>& p);
  TVector<T> operator-(const TVector<T>& p);
  TVector<T> operator*(const TVector<T>& p);
  TVector<T> operator/(const TVector<T>& p);
  TVector<T> operator=(const TVector<T>& p);
  bool operator==(const TVector<T>& p);
  bool operator!=(const TVector<T>& p);
  T& operator[](int i);
  int GetLen();
  void Resize(int newLen);
  friend std::ostream& operator<<(std::ostream& a, TVector<T>& p) {
    for (int i = 0; i < p.GetLen(); i++) a << p[i] << " ";
    a << "\n";
    return a;
  }
  friend std::istream& operator>>(std::istream& a, TVector<T>& p) {
    int l = 0;
    a >> l;
    p.Resize(l);
    for (int i = 0; i < l; i++) a >> p[i];
    return a;
  }
};

template<class T>
inline TVector<T>::TVector()
{
  len = 0;
  data = 0;
}

template<class T>
inline TVector<T>::TVector(int n)
{
  if (n > 0) {
    data = new T[n];
    len = n;
  }
  else
  {
    throw "Err";
  }
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
  if (p.data == 0) {
    data = 0;
    len = 0;
  }
  else {
    len = p.len;
    data = new T[len];
    for (int i = 0; i < len; i++)
      data[i] = p.data[i];
  }
}

template<class T>
inline TVector<T>::~TVector()
{
  if (data != 0) {
    delete[]data;
    data = 0;
  }
  len = 0;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
  if (len == 0) throw "Err";
  if (len != p.len) throw "Err";
  TVector<T> A(len);
  for (int i = 0; i < len; i++)
    A[i] = data[i] + p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
  if (len == 0) throw "Err";
  if (len != p.len) throw "Err";
  TVector<T> A(*this);
  for (int i = 0; i < len; i++)
    A.data[i] -= p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
  if (len == 0) throw "Err";
  if (len != p.len) throw "Err";
  TVector<T> A(*this);
  for (int i = 0; i < len; i++)
    A.data[i] *= p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
  if (len == 0) throw "Err";
  if (len != p.len) throw "Err";
  TVector<T> A(len);
  for (int i = 0; i < len; i++)
    A[i] = data[i] / p.data[i];
  return A;
}

template<class T>
inline TVector<T> TVector<T>::operator=(const TVector<T>& p)
{
  if (this == &p)
    return p;
  if (data != 0)
    delete[]data;
  if (p.data == 0)
    data = 0;
  else
    data = new T[p.len];
  len = p.len;
  for (int i = 0; i < len; i++)
    data[i] = p.data[i];
  return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
  if (len != p.len) return false;
  for (int i = 0; i < len; i++)
    if (data[i] != p.data[i])
      return false;
  return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
  if (len != p.len) return true;
  for (int i = 0; i < len; i++)
    if (data[i] != p.data[i])
      return true;
  return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
  if (data == 0) throw "Err";
  if ((i < 0) && (i > len)) throw "Err";
  return data[i];
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline void TVector<T>::Resize(int newLen)
{
  if (newLen <= 0) throw "Err";
  T* mass = new T[newLen];
  for (int i = 0; i < fmin(len, newLen); i++)
    mass[i] = data[i];
  delete[]data;
  len = newLen;
  data = mass;
}
