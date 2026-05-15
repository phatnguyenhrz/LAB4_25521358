#include "CTime.h"
using namespace std;

// Constructor mặc định
// Khởi tạo thời gian 00:00:00
CTime::CTime()
{
    gio = 0;
    phut = 0;
    giay = 0;
}

// Constructor có tham số
CTime::CTime(int h, int m, int s){
    gio = h;
    phut = m;
    giay = s;

    // Chuẩn hóa lại thời gian
    ChuanHoa();
}

// Copy constructor
CTime::CTime(const CTime &ct){
    gio = ct.gio;
    phut = ct.phut;
    giay = ct.giay;
}

// Destructor
CTime::~CTime()
{
}

// Hàm chuẩn hóa thời gian
// Đưa thời gian về đúng định dạng:
// 0 <= giay < 60
// 0 <= phut < 60
// 0 <= gio < 24
void CTime::ChuanHoa(){

    // Xử lý khi giây >= 60
    while(giay >= 60){
        giay -= 60;
        phut += 1;
    }

    // Xử lý khi phút >= 60
    while(phut >= 60){
        phut -= 60;
        gio += 1;
    }

    // Xử lý khi giờ >= 24
    while(gio >= 24){
        gio -= 24;
    }

    // Xử lý khi giây âm
    while(giay < 0){
        giay += 60;
        phut -= 1;
    }

    // Xử lý khi phút âm
    while(phut < 0){
        phut += 60;
        gio -= 1;
    }

    // Xử lý khi giờ âm
    while(gio < 0){
        gio += 24;
    }
}

// Cộng thêm x giây
CTime CTime::operator+(int x) const{
    return CTime(gio, phut, giay + x);
}

// Trừ đi x giây
CTime CTime::operator-(int x) const{
    return CTime(gio, phut, giay - x);
}

// Prefix ++
// Tăng trước 1 giây
CTime& CTime::operator++() {

    giay++;

    ChuanHoa();

    return *this;
}

// Postfix ++
// Tăng sau 1 giây
CTime CTime::operator++(int){

    CTime temp = *this;

    giay++;

    ChuanHoa();

    return temp;
}

// Prefix --
// Giảm trước 1 giây
CTime& CTime::operator--(){

    giay--;

    ChuanHoa();

    return *this;
}

// Postfix --
// Giảm sau 1 giây
CTime CTime::operator--(int){

    CTime ct = *this;

    giay--;

    ChuanHoa();

    return ct;
}

// Toán tử nhập
istream& operator>>(istream& in, CTime& ct){

    cout << "Nhap gio: ";
    in >> ct.gio;

    cout << "Nhap phut: ";
    in >> ct.phut;

    cout << "Nhap giay: ";
    in >> ct.giay;

    // Chuẩn hóa lại sau khi nhập
    ct.ChuanHoa();

    return in;
}

// Toán tử xuất
ostream& operator<<(ostream& out, const CTime& ct){

    // In giờ dạng 2 chữ số
    if(ct.gio < 10) out << "0";
    out << ct.gio << ":";

    // In phút dạng 2 chữ số
    if(ct.phut < 10) out << "0";
    out << ct.phut << ":";

    // In giây dạng 2 chữ số
    if(ct.giay < 10) out << "0";
    out << ct.giay;

    return out;
}
