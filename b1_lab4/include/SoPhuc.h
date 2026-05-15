#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc
{
private:
    double thuc;
    double ao;

public:
    // Constructor
    SoPhuc();
    SoPhuc(double t, double a = 0);
    SoPhuc(const SoPhuc& sp);

    // Destructor
    ~SoPhuc();

    // Toán tử
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;

    bool operator==(const SoPhuc& sp) const;
    bool operator!=(const SoPhuc& sp) const;

    // Nhập xuất
    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};

#endif
