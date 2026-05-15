#include "SoPhuc.h"
#include <cmath>

// Constructor mặc định
SoPhuc::SoPhuc()
{
    thuc = 0;
    ao = 0;
}

// Constructor có tham số
SoPhuc::SoPhuc(double t, double a)
{
    thuc = t;
    ao = a;
}

// Copy constructor
SoPhuc::SoPhuc(const SoPhuc& sp)
{
    thuc = sp.thuc;
    ao = sp.ao;
}

// Destructor
SoPhuc::~SoPhuc()
{
}

// Phép cộng
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const
{
    return SoPhuc(thuc + sp.thuc, ao + sp.ao);
}

// Phép trừ
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const
{
    return SoPhuc(thuc - sp.thuc, ao - sp.ao);
}

// Phép nhân
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const
{
    return SoPhuc(
        thuc * sp.thuc - ao * sp.ao,
        thuc * sp.ao + ao * sp.thuc
    );
}

// Phép chia
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const
{
    double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;

    return SoPhuc(
        (thuc * sp.thuc + ao * sp.ao) / mau,
        (ao * sp.thuc - thuc * sp.ao) / mau
    );
}

// So sánh bằng
bool SoPhuc::operator==(const SoPhuc& sp) const
{
    return (thuc == sp.thuc && ao == sp.ao);
}

// So sánh khác
bool SoPhuc::operator!=(const SoPhuc& sp) const
{
    return (thuc != sp.thuc || ao != sp.ao);
}

// Nhập
istream& operator>>(istream& in, SoPhuc& sp)
{
    cout << "Nhap phan thuc: ";
    in >> sp.thuc;

    cout << "Nhap phan ao: ";
    in >> sp.ao;

    return in;
}
// Xuất
ostream& operator<<(ostream& out, const SoPhuc& sp)
{
    out << sp.thuc;

    if (sp.ao > 0)
        out << " + " << sp.ao << "i";
    else if(sp.ao < 0)
        out << " - " << abs(sp.ao) << "i";
    return out;
}
