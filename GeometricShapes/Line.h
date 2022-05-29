#pragma once
#include "Obj.h"

template <class T> class TLine : public TObj<T>
{
protected:
	TString name;
	TVector<T> Point1, Point2;
	int dim;
public:
	TLine(int _dim);
	virtual void Print();
	virtual int GetDim();
	virtual TString GetName();
	virtual void SetName(TString& s);
	virtual TVector<T>& operator[](int i);
};

template<class T>
inline TLine<T>::TLine(int _dim)
{
	dim = _dim;
	Point1.Resize(dim);
	Point2.Resize(dim);
}

template<class T>
inline void TLine<T>::Print()
{
	std::cout << "line " << name;
	std::cout << "(" << Point1 << "; " << Point2 << ")" << std::endl;
}

template<class T>
inline int TLine<T>::GetDim()
{
	return dim;
}

template<class T>
inline TString TLine<T>::GetName()
{
	return name;
}

template<class T>
inline void TLine<T>::SetName(TString& s)
{
	name = s;
}

template<class T>
inline TVector<T>& TLine<T>::operator[](int i)
{
	if (i == 0) return Point1;
	if (i == 1) return Point2;
}
