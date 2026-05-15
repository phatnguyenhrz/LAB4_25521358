#ifndef CVECTOR_H
#define CVECTOR_H
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

        friend istream& operator>>(istream& in, CVector& vt);
        friend ostream& operator<<(ostream& out, const CVector& vt);

        double& operator[](int i);
        const double& operator[](int i) const;
        int Size() const;
};

#endif // CVECTOR_H
