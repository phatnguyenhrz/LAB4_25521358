#include "CVector.h"
using namespace std;

// Constructor mặc định
// Vector rỗng
CVector::CVector()
{
    n = 0;
    a = NULL;
}

// Constructor theo số chiều
// Khởi tạo vector n chiều, tất cả phần tử = 0
CVector::CVector(int x){
    n = x;
    a = new double[n];

    for(int i = 0; i < n; i++)
        a[i] = 0;
}

// Copy constructor
// Sao chép dữ liệu sang vùng nhớ mới
CVector::CVector(const CVector& vt){
    n = vt.n;
    a = new double[n];

    for(int i = 0; i < n; i++)
        a[i] = vt.a[i];
}

// Destructor
// Giải phóng bộ nhớ động
CVector::~CVector()
{
    delete [] a;
}

// Cộng vector
CVector CVector::operator+(const CVector& vt) const{

    CVector temp(n);

    for(int i = 0; i < n; i++){
        temp.a[i] = a[i] + vt.a[i];
    }

    return temp;
}

// Trừ vector
CVector CVector::operator-(const CVector& vt) const{

    CVector temp(n);

    for(int i = 0; i < n; i++){
        temp.a[i] = a[i] - vt.a[i];
    }

    return temp;
}

// Tích vô hướng (dot product)
double CVector::operator*(const CVector& vt) const{

    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += a[i] * vt.a[i];
    }

    return sum;
}

// Nhân vector với số thực
CVector CVector::operator*(double x) const{

    CVector temp(n);

    for(int i = 0; i < n; i++){
        temp.a[i] = a[i] * x;
    }

    return temp;
}

// Chia vector cho số thực
CVector CVector::operator/(double x) const{

    CVector temp(n);

    for(int i = 0; i < n; i++){
        temp.a[i] = a[i] / x;
    }

    return temp;
}

// Tính khoảng cách giữa 2 vector
double CVector::DoDai(const CVector& vt) const{

    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += pow(a[i] - vt.a[i], 2);
    }

    return sqrt(sum);
}

// Nhập vector
istream& operator>>(istream& in, CVector& vt){

    cout << "Nhap so chieu: ";
    in >> vt.n;

    delete [] vt.a;

    vt.a = new double[vt.n];

    for(int i = 0; i < vt.n; i++){
        cout << "a[" << i << "] = ";
        in >> vt.a[i];
    }

    return in;
}

// Xuất vector
ostream& operator<<(ostream& out, const CVector& vt){

    out << "(";

    for(int i = 0; i < vt.n; i++){
        out << vt.a[i];

        if(i != vt.n - 1)
            out << ", ";
    }

    out << ")";

    return out;
}
