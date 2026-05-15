#ifndef PHANSO_H
#define PHANSO_H

#include <bits/stdc++.h>
using namespace std;
class PhanSo
{
   private:
      int tu;
      int mau;

   public:
      void RutGon();

      PhanSo();
      PhanSo(int t, int m = 1);
      PhanSo(const PhanSo &ps);

      ~PhanSo();

      PhanSo operator+(const PhanSo &ps) const;
      PhanSo operator-(const PhanSo &ps) const;
      PhanSo operator*(const PhanSo &ps) const;
      PhanSo operator/ (const PhanSo &ps) const;

      bool operator== (const PhanSo &ps) const;
      bool operator> (const PhanSo &ps) const;
      bool operator< (const PhanSo &ps) const;

      friend istream& operator>> (istream& in, PhanSo &ps);
      friend ostream& operator<< (ostream& out, const PhanSo &ps);
};

#endif // PHANSO_H
