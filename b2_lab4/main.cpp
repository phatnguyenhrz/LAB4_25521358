#include "PhanSo.h"

using namespace std;

int main()
{
    PhanSo a,b;
    cout<< "Phan so a\n";
    cin>>a;

    cout<< "Phan so b\n";
    cin>>b;

    cout<< "\nPhan so a: "<< a <<endl;
    cout<< "Phan so b: " << b <<endl;

    cout<< "\nTong: " << a + b <<endl;
    cout<< "Hieu: " << a - b<<endl;
    cout<< "Tich: " << a * b << endl;
    cout<< "Thuong: " << a / b <<endl;

    if(a==b) cout << "\nPhan so a bang phan so b";
    else if(a>b) cout<< "\nPhan so a lon hon phan so b";
    else cout<< "\nPhan so a nho hon phan so b";

    return 0;
}
