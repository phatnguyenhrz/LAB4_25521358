#include "CDate.h"
#include <iomanip>

int main() {

    CDate d;
    cout<< "Nhap ngay, thang, nam\n";
    cin>>d;
    cout<< "Date: ";
    cout<<d;
    int x;
    cout<<endl;
    cout<< "\nThem ngay: ";
    cin>>x;
    cout<< "Sau khi them " << x << " ngay thi date hien tai: " << d + x << endl;

    cout<< "Bot ngay: ";
    cin>>x;
    cout<< "Sau khi bot " << x << " ngay thi date hien tai: " << d - x << endl;

    cout<< "\nThem mot ngay: "<< ++d <<endl;
    d--;
    cout<< "Bot mot ngay: " << --d <<endl;

    CDate d1;
    cout<< "\nNhap ngay, thang, nam moi\n";
    cin>>d1;
    cout<< "Date: ";
    cout<< d1;
    cout<< "\nKhoang cach giua hai ngay la: " << abs(d1-d);

    return 0;
}
