#ifndef CDATE_H
#define CDATE_H
#include <bits/stdc++.h>
using namespace std;

class CDate
{
    private:
       int ngay, thang, nam;
    public:
        CDate();
        CDate(int n, int t, int nm);
        CDate(const CDate& dt);

        ~CDate();

        CDate& operator++();
        CDate operator++(int);
        CDate& operator--();
        CDate operator--(int);

        CDate operator+(int x) const;
        CDate operator-(int x) const;
        int operator-(const CDate& d) const;

        friend istream& operator>>(istream& in, CDate& d);
        friend ostream& operator<<(ostream& out, const CDate& d);

        bool namnhuan(int y) const;
        int ngaytrongthang(int m, int y) const;
        int tongngay() const;
        bool check();
};

#endif // CDATE_H
