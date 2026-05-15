#ifndef CMATRIX_H
#define CMATRIX_H
#include <bits/stdc++.h>
#include "CVector.h"
using namespace std;
class CMatrix
{
    private:
       int dong,cot;
       double **a;
    public:
        CMatrix();
        CMatrix(int d, int c);
        CMatrix(const CMatrix& mt);
        ~CMatrix();

        CMatrix operator+(const CMatrix& mt) const;
        CMatrix operator-(const CMatrix& mt) const;
        CMatrix operator*(const CMatrix& mt) const;

        CVector operator*(const CVector& vt) const;

        friend istream& operator>>(istream& in, CMatrix& mt);
        friend ostream& operator<<(ostream& out, const CMatrix& mt);
};

#endif // CMATRIX_H
