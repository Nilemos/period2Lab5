#include "String.h"

TString::TString()
{
  len = 0;
  str = new char[len + 1];
  str[len] = 0;
}

TString::~TString()
{
  if (str != 0) delete[]str;
  str = 0;
}

int TString::GetLen()
{
  return len;
}

TString TString::copy_n_times(int n)
{
  TString ttr;
  for (int i = 0; i < n; i++) ttr += str;
  return ttr;
}

TString::TString(const char* s)
{
  if (s == 0) throw "vse slomalos";
  len = strlen(s);
  str = new char[len+1];
  for (int i = 0; i < len +1; i++)
    str[i] = s[i];
}

TString::TString(int n, char c)
{
  if (n <= 0) throw "!!!!!";
  len = n;
  str = new char[len+1];
  for (int i = 0; i < len; i++) str[i] = c;
  str[len] = 0;
}

TString::TString(const TString& p)
{
  len = p.len;
  str = new char[len +1];
  for (int i = 0; i < len+1; i++)
    str[i] = p.str[i];
}

TString TString::operator+(TString& p)
{
  TString res(len + p.len + 1);
  for (int i = 0; i < len; i++)
    res.str[i] = str[i];
  for (int k = len; k < len + p.len + 1; k++)
    res.str[k] = p.str[k - len];
  return res;
}

TString& TString::operator=(const TString& p)
{
  if (this == &p) return*this;
  delete[]str;
  len = p.len;
  str = new char[len + 1];
  for (int i = 0; i < len + 1; i++)
    str[i] = p.str[i];
  return*this;
}

TString& TString::operator+=(const TString& p)
{
  int l = p.len + len;
  char* c = new char[l + 1];
  for (int i = 0; i < len; i++)
    c[i] = str[i];
  for (int i = len; i < l+1; i++)
    c[i] = p.str[i - len];
  delete[]str;
  str = c;
  len = l;
  return *this;
}

TString TString::operator+(char* s)
{
  if (s == 0) throw "oshibka";
  int Strlen = strlen(s);
  TString tmp(len + Strlen + 1);
  for (int i = 0; i < len; i++)
    tmp[i] = str[i];
  for (int i = len; i < len + Strlen + 1; i++)
    tmp[i] = s[i - len];
  return tmp;
}

TString& TString::operator=(char* s)
{
  if (s == 0) throw "error"; 
  len = strlen(s);
  delete[]str;
  str = new char[len+1];
  for (int i = 0; i < len + 1; i++)
    str[i] = s[i];
  return *this;
}

TString& TString::operator+=(char* s)
{
  if (s == 0) throw "wr^o_o^ng !_!";
  int Strlen = strlen(s) + len;
  char* res = new char[Strlen + 1];
  for (int i = 0; i < len; i++)
    res[i] = str[i];
  for (int i = len; i < Strlen + 1; i++)
  {
    res[i] = s[i - len];
  }
  delete[] str;
  len = Strlen;
  str = res;
  return *this;
}

bool TString::operator==(TString& p)
{
  if (len != p.len) return false;
  for (int i = 0; i <= len; i++)
    if (str[i] != p.str[i])
      return false;
  return true;
}

bool TString::operator<(TString& p)
{
  int l = len > p.len ? p.len : len;
  for (int i = 0; i < l; i++) {
    if (str[i] < p.str[i])
      return true;
    else if (str[i] > p.str[i])
      return false;
  } 
  if (len >= p.len) return false;
  else return true;
}

bool TString::operator!=(TString& p)
{
  if (len != p.len) return true;
  for (int i = 0; i < len; i++)
    if (str[i] != p.str[i])
      return true;
  return false;
}

bool TString::operator>(TString& p)
{
  int l = len > p.len ? p.len : len;
  for (int i = 0; i < l; i++) {
    if (str[i] < p.str[i])
      return false;
    else if (str[i] > p.str[i])
      return true;
  }
  if (len > p.len) return true;
  else return false;
}

char& TString::operator[](int i)
{
  if (str == 0) throw "wrong answer";
  while (i <= 0)
  {
    i = i + len;
  }
  i = i % len;
  return str[i];
}

int TString::Find(char c)
{
  for (int i = 0; i < len; i++)
    if (str[i] == c) return i;
  return -1;
}

int TString::Find(TString& p)
{
  for (int i = 0; i < len - (p.len - 1); i++)
  {
    bool fl = true;
    for (int z = 0; z < (p.len - 1); z++)
    {
      if (str[i + z] != p.str[z])
      {
        fl = false;
        break;
      }
    }
    if (fl == true)
      return i;
  }
  return -1;
}

TString* TString::split(char c,int& z)
{
  int r = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
      r++;
  }
  if (r == 0)
    return 0;
  r++;
  z = r;
  TString* mas = new TString[r];
  int j = 0;
  int start = 0;
  for (int i = 0; i < len; i++)
  {
    if (str[i] == c)
    {
      mas[j].len = i - start;
      delete[] mas[j].str;
      mas[j].str = new char[mas[j].len + 1];
      for (int p = 0; p < mas[j].len; p++)
        mas[j].str[p] = str[p + start];
      mas[j].str[mas[j].len] = 0;
      j = j + 1;
      start = i + 1;
    }
  }
  mas[j].len = len - start;
  delete[] mas[j].str;
  mas[j].str = new char[mas[j].len + 1];
  for (int i = 0; i < mas[j].len + 1; i++)
  {
    mas[j].str[i] = str[i + start];
  }
  return mas;
}


std::ostream& operator<<(std::ostream& B, TString& A)
{
  B << A.str;
  return B;
}

std::istream& operator>>(std::istream& a,TString& b)
{
  char s[1000];
  int i = 0;
  a >> s;
  while (s[i] != 0)
  {
    i = i + 1;
  }
  b.len = i;
  delete[] b.str;
  b.str = new char[b.len + 1];
  for (i = 0; i < b.len; i++)
  {
    b.str[i] = s[i];
  }
  b.str[b.len] = 0;
  return a;
}
