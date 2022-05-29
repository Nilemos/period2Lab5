#pragma once
#include <Vector.h>

template <class T>
class TMatrix : public TVector<TVector<T>>
{
protected:
  int width;
public:
  TMatrix();
  TMatrix(int l);
  TMatrix(int l, int w);
  int GetWidth();
  TMatrix(const TMatrix<T>& p);
  TMatrix(TVector<TVector<T>>& p);
  ~TMatrix();
  TMatrix<T> operator+(const TMatrix<T>& p);
  TMatrix<T> operator-(const TMatrix<T>& p);
  TMatrix<T> operator*(const TMatrix<T>& p);
  TVector<T> operator*(TVector<T>& p);
  friend TVector<T> operator*(TVector<T>& m, TMatrix<T>& p) {
    int w = p.GetWidth();
    if (m.GetLen() != w) throw "error";
    TVector<T> res(p.GetLen());
    for (int i = 0; i < p.GetLen(); i++) {
      res[i] = 0;
      for (int j = 0; j < w; j++) {
        res[i] += (m[j] * p[j][i]);
      }
    }
    return res;
  }

  TMatrix<T> operator/(const TMatrix<T>& p);
  TMatrix<T>& operator=(const TMatrix<T>& p);
  TMatrix<T>& operator=(const TVector<TVector<T>>& p);
  bool operator==(const TMatrix<T>& p);
  bool operator!=(const TMatrix<T>& p);
  TVector<T>& operator[](int i);
  void Resize(int l, int w);
  friend std::ostream& operator<<(std::ostream& a, TMatrix<T>& p) {
    for (int i = 0; i < p.GetWidth(); i++) {
      for (int j = 0; j < p.GetLen(); j++)
        a << p[i][j] << " ";
      a << "\n";
    }
    return a;
  }
  friend std::istream& operator>>(std::istream& a, TMatrix<T>& p) {
    int l = 0, w = 0;
    a >> l; a >> w;
    p.Resize(l, w);
    for (int i = 0; i < w; i++)
      for (int j = 0; j < l; j++)
        a >> p[i][j];
    return a;
  }
};

template<class T>
inline TMatrix<T>::TMatrix()
{
  width = 0;
  this->len = 0;
  this->data = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int l)
{
  if (l < 0)throw "Err";
  this->len = l;
  width = l;
  this->data = new TVector<T>[width];
  for (int i = 0; i < width; i++)
    this->data[i].Resize(this->len);
}

template<class T>
inline TMatrix<T>::TMatrix(int l, int w)
{
  if ((l < 0) || (w < 0)) throw"Err";
  this->len = l;
  width = w;
  this->data = new TVector<T>[width];
  for (int i = 0; i < width; i++)
    this->data[i].Resize(this->len);
}

template<class T>
inline int TMatrix<T>::GetWidth()
{
  return width;
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
  this->len = p.len;
  width = p.width;
  if (p.data == 0)
    this->data = 0;
  else {
    this->data = new TVector<T>[width];
    for (int i = 0; i < width; i++)
      this->data[i] = p.data[i];
  }
}

template<class T>
inline TMatrix<T>::TMatrix(TVector<TVector<T>>& p) :TVector<TVector<T>>(p)
{
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
  if (this->data != 0) {
    delete[]this->data;
    this->data = 0;
  }
  this->len = 0;
  width = 0;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p)
{
  TMatrix<T> res(this->len, width);
  if ((this->len != p.len) || (width != p.width)) throw "Err";
  for (int j = 0; j < p.len; j++)
    for (int i = 0; i < width; i++)
      res.data[j][i] = this->data[j][i] + p.data[j][i];
  return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p)
{
  TMatrix<T> res(this->len, width);
  if ((this->len != p.len) || (width != p.width)) throw "Err";
  for (int j = 0; j < p.len; j++)
    for (int i = 0; i < width; i++)
      res.data[j][i] = this->data[j][i] - p.data[j][i];
  return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
  if (this->len != p.width) throw "error";
  TMatrix<T> res(p.len, width);
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < p.len; j++) {
      res[i][j] = 0;
      for (int n = 0; n < this->len; n++) {
        res[i][j] += (this->data[i][n] * p.data[n][j]);
      }
    }
  }
  return res;
}

template<class T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& p)
{
  if (this->len != p.GetLen()) throw "error";
  TVector<T> res(width);
  for (int i = 0; i < width; i++) {
    res[i] = 0;
    for (int j = 0; j < p.GetLen(); j++) {
      res[i] += (this->data[i][j] * p[j]);
    }
  }
  return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator/(const TMatrix<T>& p)
{
  return TMatrix<T>();
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& p)
{
  this->len = p.len;
  if (this == &p) return*this;
  width = p.width;
  if (this->data != 0) delete[]this->data;
  if (p.data == 0) this->data = 0;
  else {
    this->data = new TVector<T>[p.width];
    for (int i = 0; i < p.width; i++)
      this->data[i] = p.data[i];
  }
  return*this;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TVector<TVector<T>>& p)
{
  // TODO: вставьте здесь оператор return
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
  if ((this->len != p.len) || (width != p.width)) return false;
  for (int i = 0; i < width; i++)
    for (int j = 0; j < this->len; j++)
      if (this->data[i][j] != p.data[i][j])
        return false;
  return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& p)
{
  return false;
}

template<class T>
inline TVector<T>& TMatrix<T>::operator[](int i)
{
  if (i<0 || i>width)
    throw"err";
  return data[i];
}

template<class T>
inline void TMatrix<T>::Resize(int l, int w)
{
  //T* data1 = new T[l];
  TVector<T>* data1 = new TVector<T>[w];
  for (int i = 0; i < w; i++)
    data1[i].Resize(l);
  for (int i = 0; i < fmin(w, width); i++)
    for (int j = 0; j < fmin(l, this->len); i++)
      data1[i][j] = this->data[i][j];
  delete[]this->data;
  this->data = data1;
  this->len = l;
  width = w;
}

