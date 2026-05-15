#include "CDate.h"
using namespace std;

// Constructor mặc định
// Khởi tạo ngày 1/1/1
CDate::CDate()
{
    ngay = 1;
    thang = 1;
    nam = 1;
}

// Constructor có tham số
CDate::CDate(int n, int t, int nm){
   ngay = n;
   thang = t;
   nam = nm;
}

// Copy constructor
CDate::CDate(const CDate& d){
   ngay = d.ngay;
   thang = d.thang;
   nam = d.nam;
}

// Destructor
CDate::~CDate()
{
}

// Kiểm tra ngày hợp lệ
bool CDate::check() {

    // Năm phải >= 1
    if(nam < 1)
        return false;

    // Tháng phải từ 1 -> 12
    if(thang < 1 || thang > 12)
        return false;

    // Ngày phải phù hợp với tháng
    if(ngay < 1 || ngay > ngaytrongthang(thang, nam))
        return false;

    return true;
}

// Kiểm tra năm nhuận
bool CDate::namnhuan(int y) const{

    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

// Trả về số ngày trong tháng
int CDate::ngaytrongthang(int m, int y) const{

    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // Nếu là tháng 2 năm nhuận
    if(m == 2 && namnhuan(y))
        return 29;

    return days[m];
}

// Tính tổng số ngày từ 1/1/1 đến ngày hiện tại
int CDate::tongngay() const{

    int tong = 0;

    // Cộng số ngày của các năm trước
    for(int y = 1; y < nam; y++){
        tong += namnhuan(y) ? 366 : 365;
    }

    // Cộng số ngày của các tháng trước
    for(int m = 1; m < thang; m++){
        tong += ngaytrongthang(m, nam);
    }

    // Cộng thêm số ngày hiện tại
    tong += ngay;

    return tong;
}

// Toán tử nhập
istream& operator>>(istream& in, CDate& cd){

    do{
        cout << "Nhap ngay: ";
        in >> cd.ngay;

        cout << "Nhap thang: ";
        in >> cd.thang;

        cout << "Nhap nam: ";
        in >> cd.nam;

        // Báo lỗi nếu ngày không hợp lệ
        if(!cd.check())
            cout << "Ngay khong hop le! Nhap lai!\n";

    }while(!cd.check());

    return in;
}

// Toán tử xuất
ostream& operator<< (ostream& out, const CDate& cd){

   out << cd.ngay << "/" << cd.thang << "/" << cd.nam;

   return out;
}

// Prefix ++
// Tăng trước 1 ngày
CDate& CDate::operator++(){

   *this = *this + 1;

   return *this;
}

// Postfix ++
// Tăng sau 1 ngày
CDate CDate::operator++(int){

   CDate temp = *this;

   *this = *this + 1;

   return temp;
}

// Prefix --
// Giảm trước 1 ngày
CDate& CDate::operator--(){

   *this = *this - 1;

   return *this;
}

// Postfix --
// Giảm sau 1 ngày
CDate CDate::operator--(int){

   CDate temp = *this;

   *this = *this - 1;

   return temp;
}

// Cộng thêm x ngày
CDate CDate::operator+(int x) const{

   CDate temp = *this;

   while(x--){

      temp.ngay++;

      // Nếu vượt số ngày trong tháng
      if(temp.ngay > temp.ngaytrongthang(temp.thang, temp.nam)){

        temp.ngay = 1;

        temp.thang++;

        // Nếu vượt tháng 12
        if(temp.thang > 12){

            temp.thang = 1;

            temp.nam++;
        }
      }
   }

   return temp;
}

// Trừ đi x ngày
CDate CDate::operator-(int x) const {

    CDate temp = *this;

    while(x--){

        temp.ngay--;

        // Nếu ngày nhỏ hơn 1
        if(temp.ngay < 1){

            temp.thang--;

            // Nếu tháng nhỏ hơn 1
            if(temp.thang < 1){

                temp.thang = 12;

                temp.nam--;
            }

            // Lấy ngày cuối tháng trước
            temp.ngay = temp.ngaytrongthang(temp.thang, temp.nam);
        }
    }

    return temp;
}

// Tính khoảng cách giữa hai ngày
int CDate::operator-(const CDate& d) const {

    return this->tongngay() - d.tongngay();
}
