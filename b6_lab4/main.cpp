#include "CVector.h"

using namespace std;

int main()
{
    CVector a,b;

    cout<< "Nhap a\n";
    cin>>a;

    cout<< "Nhap b\n";
    cin>>b;

    cout<< "Vector a = " << a <<endl;
    cout<< "Vector b = " << b << endl;

    cout<< "\nTong hai vector = " << a + b << endl;
    cout<< "Hieu hai vector = " << a- b << endl;
    cout<< "Tich vo huong = " << a*b << endl;
    cout<< "Do dai = " << a.DoDai(b) <<endl;

    double k;
    cout<< "\nNhap k = "; cin>>k;
    cout<< "ka = " << a*k << endl;
    cout<< "kb = " << b*k <<endl;

    cout<< "\nNhap i = "; cin>>k;
    cout<< "a/i = "<< a/k <<endl;
    cout<< "b/i = "<< b/k ;
    return 0;
}
