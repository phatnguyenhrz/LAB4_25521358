#include "CTime.h"
using namespace std;

int main()
{
    CTime t;
    cout<< "Nhap thoi gian\n";
    cin>>t;

    cout<< "\nThoi gian hien tai: ";
    cout<<t;

    int x;
    cout<<endl;
    cout<< "\nThem so nguyen giay: ";
    cin>>x;
    cout<< "Sau khi cong them "<< x << " giay thi thoi gian hien tai la: " << t + x << endl;

    cout<< "\nBot so nguyen giay: ";
    cin>>x;
    cout<< "Sau khi tru di " << x << " giay thi thoi gian hien tai la: " << t - x<<endl;

    cout<< "\nThem mot giay: " << ++t << endl;
    t--; //quay tro lai thoi gian goc
    cout<< "Bot mot giay: " << --t << endl;

    return 0;
}
