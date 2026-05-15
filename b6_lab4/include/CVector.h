#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class CVector
{
    private:
       int n;
       double *a;
    public:
        CVector();
        CVector(int x);
        CVector(const CVector& vt);
        ~CVector();

        double DoDai(const CVector& vt) const;

        CVector operator+(const CVector& vt) const;
        CVector operator-(const CVector& vt) const;
        double operator*(const CVector& vt) const;
        CVector operator*(double x) const;
        CVector operator/(double x) const;

        friend istream& operator>>(istream& in, CVector& vt);
        friend ostream& operator<<(ostream& out, const CVector& vt);
};

#endif // CVECTOR_H
