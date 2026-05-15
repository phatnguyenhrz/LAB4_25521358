#include "CVector.h"

CVector::CVector()
{
    n = 0;
    a =NULL;
}

CVector::CVector(int x){
    n = x;
    a = new double[n];
    for(int i=0; i<n; i++) a[i]=0;
}

CVector::CVector(const CVector& vt){
    n = vt.n;
    a = new double[n];
    for(int i=0;i<n;i++) a[i] = vt.a[i];
}

CVector::~CVector()
{
    delete [] a;
}

istream& operator>> (istream& in, CVector& vt){
    cout<< "Nhap so chieu: ";
    in>> vt.n;

    delete [] vt.a;
    vt.a = new double[vt.n];
    for(int i=0;i<vt.n;i++){
        cout<< "a[" << i << "] = ";
        in>>vt.a[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const CVector& v){
    out << "(";
    for(int i = 0; i < v.n; i++){
        out << v.a[i];
        if(i != v.n - 1)
            out << ", ";
    }
    out << ")";
    return out;
}

double& CVector::operator[](int i){
    return a[i];
}

int CVector::Size() const{
    return n;
}
const double& CVector::operator[](int i) const{
    return a[i];
}
