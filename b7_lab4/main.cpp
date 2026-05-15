#include "CMatrix.h"

using namespace std;

int main()
{
    CMatrix a,b;
    cout<< "Nhap ma tran A:\n";
    cin>>a;
    cout<< "Nhap ma tran B:\n";
    cin>>b;

    CVector v;
    cout<< "\nA + B =\n" << a + b <<endl;
    cout<< "A - B =\n" << a - b <<endl;
    cout<< "A * B =\n" << a * b <<endl;

    cout<< "Nhap vector v\n";
    cin>>v;
    cout<< "\nA * v =\n" << a * v << endl;

    return 0;
}
