#ifndef CDATHUC_H
#define CDATHUC_H

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class CDaThuc {
private:
    int bac;
    double *heso;

public:
    CDaThuc();
    CDaThuc(int x);
    CDaThuc(const CDaThuc& dt);
    ~CDaThuc();

    friend istream& operator>>(istream& in, CDaThuc& dt);
    friend ostream& operator<<(ostream& out, const CDaThuc& dt);

    CDaThuc operator+(const CDaThuc& dt) const;
    CDaThuc operator-(const CDaThuc& dt) const;

    double TinhGiaTri(double x) const;
};

#endif
