#pragma once
#include <iostream>

class TString
{
public:
	TString();
	~TString();
	int GetLen();
	TString copy_n_times(int n); // доп 1 задание
	TString(const char* s);
	TString(int n, char c = 0);
	TString(const TString& p);
	TString operator+ (TString& p);
	TString& operator= (const TString& p);
	TString& operator+= (const TString& p);
	TString operator+ (char* s);
	TString& operator= (char* s);
	TString& operator+= (char* s);
	bool operator== (TString& p);
	bool operator< (TString& p);
	bool operator!= (TString& p);
	bool operator> (TString& p);
	char& operator[] (int i);
	friend std::ostream& operator<<(std::ostream& B, TString& A);
	friend std::istream& operator>>(std::istream& a, TString& b);
	int Find(char c);
	int Find(TString& p);
	TString* split(char c, int& z);

private:
	int len;
	char* str;
};
