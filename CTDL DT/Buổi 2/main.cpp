#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

typedef struct NhanVien
{
    int MaNV;
    string HoTen;
    double LCB;
    int SoNgayLam;
    double LuongThang;
} NV;

/* Yêu cầu: Tạo dữ liệu các nhân viên dùng để kiểm thử (10 nhân viên)
 *  Input:
        + NV* dsNhanVien;
        + int& slNhanVien;
 *  Output:
        + NV* dsNhanVien;
        + int& slNhanVien:
 */

void taoNhanVien(NV *dsNhanVien, int &slNhanVien)
{
    *(dsNhanVien + 0) = {1001, "Nguyen Van A", 9500000.0f, 22, 0};
    *(dsNhanVien + 1) = {1002, "Tran Thi B", 9800000.0f, 20, 0};
    *(dsNhanVien + 2) = {1003, "Le Van C", 10200000.0f, 21, 0};
    *(dsNhanVien + 3) = {1004, "Pham Thi D", 11000000.0f, 23, 0};
    *(dsNhanVien + 4) = {1005, "Hoang Van E", 4500000.0f, 22, 0};
    *(dsNhanVien + 5) = {1006, "Do Thi F", 4999999.0f, 19, 0};
    *(dsNhanVien + 6) = {1007, "Vu Van G", 10500000.0f, 21, 0};
    *(dsNhanVien + 7) = {1008, "Ngo Thi H", 9900000.0f, 20, 0};
    *(dsNhanVien + 8) = {1009, "Bui Van I", 11800000.0f, 22, 0};
    *(dsNhanVien + 9) = {1010, "Dao Thi K", 11200000.0f, 23, 0};

    slNhanVien = 10;
}

/* Yêu cầu: Xuất danh sách nhân viên công ty
 *  Input:
        + NV* dsNhanVien;
        + int slNhanVien;
 *  Output:
        + cout;
 */
void xuatNhanVien(NV *dsNhanVien, int slNhanVien)
{
    printf("Danh sách nhân viên công ty: \n");
    for (int i = 0; i < slNhanVien; i++)
    {
        printf("Mã NV: %d, Họ tên: %s, Lương cơ bản: %9.1f, Số ngày làm: %d, Lương "
               "tháng: %9.1f\n",
               (dsNhanVien + i)->MaNV, (dsNhanVien + i)->HoTen.c_str(),
               (dsNhanVien + i)->LCB, (dsNhanVien + i)->SoNgayLam,
               (dsNhanVien + i)->LuongThang);
    }
}
/* Yêu cầu: Tính lương cho 1 nhân viên
  *  Input:
         + NV* nhanVien;
  *  Output:
         + double: Lương tháng của nhân viên;
  */
double tinhLuongMotNhanVien(NV *nhanVien)
{
    double *luongTamTinh = new double();

    *luongTamTinh = nhanVien->LCB + nhanVien->SoNgayLam * 180000;

    int *phanTramPhuCap = new int(0);

    if (*luongTamTinh > 8000000)
    {
        *phanTramPhuCap += 5;
    }
    if (nhanVien->LCB < 5000000)
    {
        *phanTramPhuCap += 10;
    }
    cout << *luongTamTinh << " " << (1 + *phanTramPhuCap / 100.0) << endl;
    return (double)(*luongTamTinh) * (1 + *phanTramPhuCap / 100.0);
}
/* Yêu cầu: Tính và cập nhật lương cho danh sách nhân viên
  *  Input:
         + NV* dsNhanVien;
         + int slNhanVien;
  *  Output:
         + NV* dsNhanVien;
  */
void tinhLuongNhanVien(NV *dsNhanVien, int slNhanVien)
{
    for (int i = 0; i < slNhanVien; i++)
    {
        (dsNhanVien + i)->LuongThang = tinhLuongMotNhanVien(dsNhanVien + i);
    }
}

int main()
{

    NV *dsNhanVien = new NV[10];
    int *slNhanVien = new int();

    cout << "Test: Tạo danh sách nhân viên" << endl;
    taoNhanVien(dsNhanVien, *slNhanVien);

    cout << "/t KQ: n: " << *slNhanVien << " phần tử" << endl;

    cout << "Test: Xuất danh sách nhân viên" << endl;
    xuatNhanVien(dsNhanVien, *slNhanVien);

    cout << "Test: Tính lương cho danh sách nhân viên" << endl;
    tinhLuongNhanVien(dsNhanVien, *slNhanVien);

    cout << "Test: Xuất danh sách nhân viên sau khi tính lương" << endl;
    xuatNhanVien(dsNhanVien, *slNhanVien);
    return 0;
}