#include "PhanSo.h"
using namespace std;

// Constructor mặc định
// Khởi tạo phân số 0/1
PhanSo::PhanSo()
{
    tu = 0;
    mau = 1;
}

// Constructor có tham số
// Cho phép tạo phân số với tử và mẫu
PhanSo::PhanSo(int t, int m){
    tu = t;
    mau = m;

    // Rút gọn phân số sau khi tạo
    RutGon();
}

// Copy constructor
// Sao chép dữ liệu từ phân số khác
PhanSo::PhanSo(const PhanSo &ps){
    tu = ps.tu;
    mau = ps.mau;
}

// Destructor
PhanSo::~PhanSo()
{
}

// Phép cộng hai phân số
PhanSo PhanSo::operator+(const PhanSo &ps) const{
    return PhanSo(tu * ps.mau + ps.tu * mau,
                  mau * ps.mau);
}

// Phép trừ hai phân số
PhanSo PhanSo::operator-(const PhanSo &ps) const{
    return PhanSo(tu * ps.mau - ps.tu * mau,
                  mau * ps.mau);
}

// Phép nhân hai phân số
PhanSo PhanSo::operator*(const PhanSo &ps) const{
    return PhanSo(tu * ps.tu,
                  mau * ps.mau);
}

// Phép chia hai phân số
PhanSo PhanSo::operator/(const PhanSo &ps) const{
    return PhanSo(tu * ps.mau,
                  mau * ps.tu);
}

// So sánh bằng
bool PhanSo::operator==(const PhanSo &ps) const{
    return (tu == ps.tu && mau == ps.mau);
}

// So sánh lớn hơn
bool PhanSo::operator>(const PhanSo &ps) const{
    return (tu * ps.mau > ps.tu * mau);
}

// So sánh nhỏ hơn
bool PhanSo::operator<(const PhanSo &ps) const{
    return (tu * ps.mau < ps.tu * mau);
}

// Hàm tìm UCLN bằng đệ quy
int UCLN(int a, int b){
   a = abs(a);
   b = abs(b);

   if(b == 0) return a;

   return UCLN(b, a % b);
}

// Hàm rút gọn phân số
void PhanSo::RutGon(){

   // Tìm UCLN của tử và mẫu
   int i = UCLN(tu, mau);

   // Chia tử và mẫu cho UCLN
   tu /= i;
   mau /= i;

   // Đưa dấu âm lên tử số
   if(mau < 0){
      tu = -tu;
      mau = -mau;
   }
}

// Toán tử nhập
istream& operator>>(istream& in, PhanSo &ps){

    cout << "Nhap tu: ";
    in >> ps.tu;

    cout << "Nhap mau: ";
    in >> ps.mau;

    // Rút gọn sau khi nhập
    ps.RutGon();

    return in;
}

// Toán tử xuất
ostream& operator<< (ostream& out, const PhanSo &ps){

    // Nếu mẫu bằng 1 thì chỉ in tử
    if(ps.mau == 1){
        out << ps.tu;
    }
    else{
        out << ps.tu << "/" << ps.mau;
    }

    return out;
}
