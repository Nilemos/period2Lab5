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
    return a;
  }
  friend std::istream& operator>>(std::istream& a, TVector<T>& p) {
    int l = 0;
    a >> l;
    p.Resize(l);
    for (int i = 0; i < l; i++) a >> p[i];
    return a;
  }
  void bubbleSort();
  void quickSort();
  void function(T* mas, long left, long right);
  void insertionSort();
  int findCol(T p);
  int* Find(T p);
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

template<class T>
inline void TVector<T>::bubbleSort()
{
  int tmp = 0;

  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        tmp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = tmp;
      }
    }
  }
}

template<class T>
inline void TVector<T>::quickSort()
{
  function(data, 0, len - 1);
}

template<class T>
inline void TVector<T>::function(T* mas, long left, long right)
{
  long tmp = 0;
  long pivot = mas[(left + right) / 2];
  long l = left;
  long r = right;
  while (l <= r)
  {
    while (mas[r] > pivot)
      r--;
    while (mas[l] < pivot)
      l++;
    if (l <= r)
    {
      tmp = mas[l];
      mas[l] = mas[r];
      mas[r] = tmp;
      l++;
      r--;
    }
  }
  if (left < r)
    function(mas, left, r);
  if (right > l)
    function(mas, l, right);
}

template<class T>
inline void TVector<T>::insertionSort()
{
  long i = 0, j = 0, tmp = 0;

  for (int i = 1; i < len; i++) {
    for (int j = i; j > 0 && data[j - 1] > data[j]; j--) {
      tmp = data[j - 1];
      data[j - 1] = data[j];
      data[j] = tmp;
    }
  }
}

template<class T>
inline int TVector<T>::findCol(T p)
{
  int col = 0;
  for (int i = 0; i < len; i++) 
    if (p == data[i]) col++;
  return col;
}

template<class T>
inline int* TVector<T>::Find(T p)
{
  int* mas = new int[findCol(p)];
  int j = 0;
  for (int i = 0; i < len; i++)
    if (p == data[i]) {
      mas[j] = i;
      j++;
    }
  return mas;
}
