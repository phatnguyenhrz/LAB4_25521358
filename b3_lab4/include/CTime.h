#ifndef CTIME_H
#define CTIME_H

#include <bits/stdc++.h>
using namespace std;

class CTime
{
   private:
       int gio;
       int phut;
       int giay;

       void ChuanHoa();

   public:
    CTime();
    CTime(int h,int m,int s);
    CTime(const CTime& ct);

    ~CTime();

    CTime operator+(int x) const;
    CTime operator-(int x) const;

    CTime& operator++();
    CTime operator++(int);

    CTime& operator--();
    CTime operator--(int);

    friend istream& operator>>(istream& in, CTime& ct);
    friend ostream& operator<< (ostream& out, const CTime& ct);
};

#endif // CTIME_H
