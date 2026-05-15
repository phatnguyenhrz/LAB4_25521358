#include "CDaThuc.h"

using namespace std;

int main()
{
    CDaThuc a,b;
    cout<< "Nhap da thuc a\n";
    cin>>a;
    cout<< "\nNhap da thuc b\n";
    cin>>b;

    cout<< "\nDa thuc a = ";
    cout<< a;
    cout<< "\nDa thuc b = ";
    cout<< b;

    cout<< "\na + b = " << a + b <<endl;
    cout<< "a - b = " << a - b << endl;

    double x;
    cout<< "\nNhap x = "; cin >> x;
    cout<< "a = " << a.TinhGiaTri(x) << endl;
    cout<< "b = " << b.TinhGiaTri(x) <<endl;
    return 0;
}
