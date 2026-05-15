#include "CDaThuc.h"

// Constructor mặc định
// Khởi tạo đa thức bậc 0: P(x) = 0
CDaThuc::CDaThuc()
{
    bac = 0;
    heso = new double[1];
    heso[0] = 0;
}

// Constructor theo bậc
// Khởi tạo đa thức bậc x, tất cả hệ số = 0
CDaThuc::CDaThuc(int x){
    bac = x;
    heso = new double[x + 1];

    for(int i = 0; i <= bac; i++)
        heso[i] = 0;
}

// Copy constructor
// Sao chép toàn bộ hệ số sang vùng nhớ mới
CDaThuc::CDaThuc(const CDaThuc& dt){
    bac = dt.bac;
    heso = new double[bac + 1];

    for(int i = 0; i <= bac; i++)
        heso[i] = dt.heso[i];
}

// Destructor
// Giải phóng bộ nhớ động
CDaThuc::~CDaThuc()
{
    delete [] heso;
}

// Nhập đa thức
istream& operator>>(istream& in, CDaThuc& dt){

    cout << "Nhap bac da thuc: ";
    in >> dt.bac;

    // Xóa bộ nhớ cũ trước khi cấp phát lại
    delete [] dt.heso;

    dt.heso = new double[dt.bac + 1];

    // Nhập hệ số từ bậc cao xuống thấp
    for(int i = dt.bac; i >= 0; i--){
        cout << "He so bac " << i << ": ";
        in >> dt.heso[i];
    }

    return in;
}

// Xuất đa thức
ostream& operator<< (ostream& out, const CDaThuc& dt){

    int f = 0; // kiểm tra đã in số hạng nào chưa

    for(int i = dt.bac; i >= 0; i--){

        // bỏ qua hệ số 0
        if(dt.heso[i] == 0) continue;

        // thêm dấu + nếu cần
        if(i != dt.bac && dt.heso[i] > 0 && f != 0)
            out << "+";

        // xử lý hệ số = 1
        if(dt.heso[i] == 1){
            if(i == 0) out << 1;
            else if(i == 1) out << "x";
            else out << "x^" << i;   // sửa: phải là i, không phải bac
            f = 1;
            continue;
        }

        // xử lý hệ số = -1
        if(dt.heso[i] == -1){
            if(i == 0) out << -1;
            else if(i == 1) out << "-x";
            else out << "-x^" << i;  // sửa: dùng i
            f = 1;
            continue;
        }

        // các trường hợp còn lại
        if(i == 0) out << dt.heso[i];
        else if(i == 1) out << dt.heso[i] << "x";
        else out << dt.heso[i] << "x^" << i;  // sửa: dùng i

        f = 1;
    }

    // nếu toàn hệ số 0
    if(f == 0) out << 0;

    return out;
}

// Cộng hai đa thức
CDaThuc CDaThuc::operator+(const CDaThuc& dt) const {

    int maxbac = (bac > dt.bac) ? bac : dt.bac;
    CDaThuc temp(maxbac);

    for(int i = 0; i <= maxbac; i++){

        double a = (i <= bac) ? heso[i] : 0;
        double b = (i <= dt.bac) ? dt.heso[i] : 0;

        temp.heso[i] = a + b;
    }

    return temp;
}

// Trừ hai đa thức
CDaThuc CDaThuc::operator-(const CDaThuc& dt) const{

    int maxbac = (bac > dt.bac) ? bac : dt.bac;
    CDaThuc temp(maxbac);

    for(int i = 0; i <= maxbac; i++){

        double a = (i <= bac) ? heso[i] : 0;
        double b = (i <= dt.bac) ? dt.heso[i] : 0;

        temp.heso[i] = a - b;
    }

    return temp;
}

// Tính giá trị đa thức tại x
double CDaThuc::TinhGiaTri(double x) const {

    double sum = 0;
    double pow = 1; // x^0

    for(int i = 0; i <= bac; i++){
        sum += heso[i] * pow;
        pow *= x;
    }

    return sum;
}
