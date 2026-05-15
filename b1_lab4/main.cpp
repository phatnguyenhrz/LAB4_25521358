#include "SoPhuc.h"

int main()
{
    SoPhuc a, b;

    cout << "Nhap so phuc a:\n";
    cin >> a;

    cout << "\nNhap so phuc b:\n";
    cin >> b;

    cout << "\nSo phuc a: " << a << endl;
    cout << "So phuc b: " << b << endl;

    cout << "\nTong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;
    cout << "Thuong: " << a / b << endl;

    if (a == b)
        cout << "\na bang b\n";
    else
        cout << "\na khac b\n";


    return 0;
}
