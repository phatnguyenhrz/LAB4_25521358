#include "CMatrix.h"
using namespace std;

// Constructor mặc định
// Ma trận rỗng
CMatrix::CMatrix()
{
    dong = 0;
    cot = 0;
    a = NULL;
}

// Constructor có kích thước
// Tạo ma trận d x c và gán 0
CMatrix::CMatrix(int d,int c){
    dong = d;
    cot = c;

    a = new double*[dong];

    for(int i = 0; i < dong; i++){
        a[i] = new double[cot];

        for(int j = 0; j < cot; j++){
            a[i][j] = 0;
        }
    }
}

// Copy constructor
CMatrix::CMatrix(const CMatrix& mt){
    dong = mt.dong;
    cot = mt.cot;

    a = new double*[dong];

    for(int i = 0; i < dong; i++){
        a[i] = new double[cot];

        for(int j = 0; j < cot; j++){
            a[i][j] = mt.a[i][j];
        }
    }
}

// Destructor
// Giải phóng bộ nhớ 2 chiều
CMatrix::~CMatrix()
{
    for(int i = 0; i < dong; i++){
        delete [] a[i];
    }
    delete [] a;
}

// Nhập ma trận
istream& operator>>(istream& in, CMatrix& mt){
    // Xóa dữ liệu cũ
    for(int i = 0; i < mt.dong; i++){
        delete[] mt.a[i];
    }
    delete[] mt.a;

    cout << "Nhap dong = ";
    in >> mt.dong;

    cout << "Nhap cot = ";
    in >> mt.cot;

    mt.a = new double*[mt.dong];

    for(int i = 0; i < mt.dong; i++){

        mt.a[i] = new double[mt.cot];

        for(int j = 0; j < mt.cot; j++){
            in >> mt.a[i][j];
        }
    }

    return in;
}
// Xuất ma trận
ostream& operator<< (ostream& out, const CMatrix& mt){

    for(int i = 0; i < mt.dong; i++){

        for(int j = 0; j < mt.cot; j++){
            out << mt.a[i][j] << " ";
        }

        cout << endl;
    }

    return out;
}

// Cộng hai ma trận
CMatrix CMatrix::operator+(const CMatrix& mt) const{

    CMatrix temp(dong, cot);

    for(int i = 0; i < dong; i++){
        for(int j = 0; j < cot; j++){
            temp.a[i][j] = a[i][j] + mt.a[i][j];
        }
    }

    return temp;
}

// Trừ hai ma trận
CMatrix CMatrix::operator-(const CMatrix& mt) const{

    CMatrix temp(dong, cot);

    for(int i = 0; i < dong; i++){
        for(int j = 0; j < cot; j++){
            temp.a[i][j] = a[i][j] - mt.a[i][j];
        }
    }

    return temp;
}

// Nhân hai ma trận
CMatrix CMatrix::operator*(const CMatrix& mt) const{

    CMatrix temp(dong, mt.cot);

    for(int i = 0; i < dong; i++){
        for(int j = 0; j < mt.cot; j++){

            temp.a[i][j] = 0;

            for(int k = 0; k < cot; k++){
                temp.a[i][j] += a[i][k] * mt.a[k][j];
            }
        }
    }

    return temp;
}

// Nhân ma trận với vector
CVector CMatrix::operator*(const CVector& vt) const{

    CVector temp(dong);

    for(int i = 0; i < dong; i++){

        temp[i] = 0;

        for(int j = 0; j < cot; j++){

            temp[i] += a[i][j] * vt[j];
        }
    }

    return temp;
}
