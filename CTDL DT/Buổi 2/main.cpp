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
  *(dsNhanVien + 9) = {1010, "Do Thi K", 4999999.0f, 19, 0};

  slNhanVien = 10;
}

/* Yêu cầu: Xuất 1 nhân viên
 *  Input:
        + NV* nhanVien;
 *  Output:
        + cout;
 */

void xuatMotNhanVien(NV *nhanVien)
{
  printf("Mã NV: %d, Họ tên: %s, Lương cơ bản: %9.1f, Số ngày làm: %d, Lương "
         "tháng: %9.1f\n",
         nhanVien->MaNV, nhanVien->HoTen.c_str(),
         nhanVien->LCB, nhanVien->SoNgayLam,
         nhanVien->LuongThang);
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
    xuatMotNhanVien(dsNhanVien + i);
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
/* Yêu cầu: Tính tổng lương hàng tháng mà công ty phải trả cho nhân viên
  *  Input:
         + NV* dsNhanVien;
         + int slNhanVien;
  *  Output:
         + double: Tổng lương hàng tháng;
  */
double tinhTongLuong(NV *dsNhanVien, int slNhanVien)
{
  double tongLuong = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    tongLuong += (dsNhanVien + i)->LuongThang;
  }
  return tongLuong;
}
/**Yêu cầu: Tìm danh sách nhân viên có LCB  nhỏ hơn 1 số nào đó
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
         + NV*& dsNhanVienHopLe
         + double lcbCanTim;
 * Output:
         + NV* dsNhanVienHopLe;
         + int& slNhanVienHopLe;
 *
 */
void timNhanVienCoLuongNhoHon(NV *dsNhanVien, int slNhanVien, double lcbCanTim,
                              NV *&dsNhanVienHopLe, int &slNhanVienHopLe)
{
  slNhanVienHopLe = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LCB < lcbCanTim)
    {
      slNhanVienHopLe++;
    }
  }

  dsNhanVienHopLe = new NV[slNhanVienHopLe];

  int index = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LCB < lcbCanTim)
    {
      *(dsNhanVienHopLe + index) = *(dsNhanVien + i);
      index++;
    }
  }
}
/**Yêu cầu: Tính tổng lương của các nhân viên có LCB nhỏ hơn 1 số nào đó
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
         + double lcbCanTim;
 * Output:
         + double;
 *
 */
double tinhTongLuongHangThangCacNhanVienCoLCBNhoHon(NV *dsNhanVien,
                                                    int slNhanVien,
                                                    double lcbCanTim)
{
  int *slNhanVienHopLe = new int(0);
  NV *dsNhanVienHopLe = nullptr;
  timNhanVienCoLuongNhoHon(dsNhanVien, slNhanVien, lcbCanTim,
                           dsNhanVienHopLe, *slNhanVienHopLe);

  double tongLuong = tinhTongLuong(dsNhanVienHopLe, *slNhanVienHopLe);

  delete[] dsNhanVienHopLe;
  delete slNhanVienHopLe;

  return tongLuong;
}

/**Yêu cầu: Tìm nhân viên theo mã nhân viên
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
         + int maNhanVienCanTim;
 * Output:
         + NV*;
 *
 */
NV *timNhanVienTheoMa(NV *dsNhanVien, int slNhanVien, int maNhanVienCanTim)
{
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->MaNV == maNhanVienCanTim)
    {
      return dsNhanVien + i;
    }
  }

  return nullptr;
}
/**Yêu cầu: Lương tháng thấp nhất trong danh sách
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
 * Output:
         + double*;
 *
 */
double *timLuongThangThapNhat(NV *dsNhanVien, int slNhanVien)
{
  if (slNhanVien <= 0)
  {
    return nullptr;
  }
  double *min = new double(dsNhanVien->LuongThang);
  for (int i = 1; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LuongThang < *min)
    {
      *min = (dsNhanVien + i)->LuongThang;
    }
  }

  return min;
}

/**Yêu cầu: Tìm danh sách nhân viên có cùng mức lương thấp nhất
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
         + NV*& dsNhanVienHopLe
         + int& slNhanVienHopLe;
 * Output:
         + NV*& dsNhanVienHopLe;
         + int& slNhanVienHopLe;
 *
 */
void timDSNhanVienCoLuongThangThapNhat(NV *dsNhanVien, int slNhanVien, NV *&dsNhanVienHopLe, int &slNhanVienHopLe)
{
  double *min = timLuongThangThapNhat(dsNhanVien, slNhanVien);
  if (min == nullptr)
  {
    slNhanVienHopLe = 0;
    return;
  }
  slNhanVienHopLe = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LuongThang == *min)
    {
      slNhanVienHopLe++;
    }
  }
  dsNhanVienHopLe = new NV[slNhanVienHopLe];
  int index = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LuongThang == *min)
    {
      dsNhanVienHopLe[index] = *(dsNhanVien + i);
      index++;
    }
  }
  delete min;
}

/**Yêu cầu: Tìm LCB cao nhất
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
 * Output:
         + double*;
 *
 */
double *timLCBCaoNhat(NV *dsNhanVien, int slNhanVien)
{
  if (slNhanVien <= 0)
  {
    return nullptr;
  }
  double *max = new double(dsNhanVien->LCB);
  for (int i = 1; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LCB > *max)
    {
      *max = (dsNhanVien + i)->LCB;
    }
  }

  return max;
}

/**Yêu cầu: Tìm danh sách nhân viên có cùng mức LCB cao nhất
 * Input:
 *       + NV* dsNhanVien;
         + int slNhanVien;
         + NV*& dsNhanVienHopLe
         + int& slNhanVienHopLe;
 * Output:
         + NV*& dsNhanVienHopLe;
         + int& slNhanVienHopLe;
 *
 */
void timDSNhanVienCoLCBCaoNhat(NV *dsNhanVien, int slNhanVien, NV *&dsNhanVienHopLe, int &slNhanVienHopLe)
{
  double *max = timLCBCaoNhat(dsNhanVien, slNhanVien);
  if (max == nullptr)
  {
    slNhanVienHopLe = 0;
    return;
  }
  slNhanVienHopLe = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LCB == *max)
    {
      slNhanVienHopLe++;
    }
  }
  dsNhanVienHopLe = new NV[slNhanVienHopLe];
  int index = 0;
  for (int i = 0; i < slNhanVien; i++)
  {
    if ((dsNhanVien + i)->LCB == *max)
    {
      dsNhanVienHopLe[index] = *(dsNhanVien + i);
      index++;
    }
  }
  delete max;
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

  cout << "Test: Tính tổng lương hàng tháng mà công ty phải trả cho nhân viên"
       << endl;
  double *tongLuong = new double();
  *tongLuong = tinhTongLuong(dsNhanVien, *slNhanVien);
  printf("Tổng lương: %9.1f\n", *tongLuong);

  cout << "Test: Tính tổng lương hàng tháng mà công ty phải trả cho nhân viên "
          "có lương cơ bản nhỏ hơn 5 triệu"
       << endl;
  double lcbCanTim = 5000000.0f;
  *tongLuong = tinhTongLuongHangThangCacNhanVienCoLCBNhoHon(
      dsNhanVien, *slNhanVien, lcbCanTim);
  printf("Tổng lương của các nhân viên có lương cơ bản nhỏ hơn %9.1f: %9.1f\n",
         lcbCanTim, *tongLuong);

  cout << "Test: Tìm nhân viên theo mã nhân viên" << endl;
  int *maNhanVienCanTim = new int(1005);
  NV *nhanVienCanTim = timNhanVienTheoMa(dsNhanVien, *slNhanVien, *maNhanVienCanTim);
  if (nhanVienCanTim != nullptr)
  {
    xuatMotNhanVien(nhanVienCanTim);
  }
  else
  {
    cout << "Không tìm thấy nhân viên có mã " << *maNhanVienCanTim << endl;
  }
  *maNhanVienCanTim = 9999;
  nhanVienCanTim = timNhanVienTheoMa(dsNhanVien, *slNhanVien, *maNhanVienCanTim);
  if (nhanVienCanTim != nullptr)
  {
    xuatMotNhanVien(nhanVienCanTim);
  }
  else
  {
    cout << "Không tìm thấy nhân viên có mã " << *maNhanVienCanTim << endl;
  }

  cout << "Test: Tìm danh sách nhân viên có cùng mức lương thấp nhất" << endl;
  NV *dsNhanVienHopLe = nullptr;
  int *slNhanVienHopLe = new int(0);
  timDSNhanVienCoLuongThangThapNhat(dsNhanVien, *slNhanVien, dsNhanVienHopLe, *slNhanVienHopLe);
  cout << "Danh sách nhân viên có cùng mức lương thấp nhất: " << endl;
  xuatNhanVien(dsNhanVienHopLe, *slNhanVienHopLe);

  cout << "Test: Tìm danh sách nhân viên có LCB cao nhất";

  *slNhanVienHopLe = 0;
  timDSNhanVienCoLCBCaoNhat(dsNhanVien, *slNhanVien, dsNhanVienHopLe, *slNhanVienHopLe);
  cout << "Danh sách nhân viên có cùng mức LCB cao nhất: " << endl;
  xuatNhanVien(dsNhanVienHopLe, *slNhanVienHopLe);

  delete[] dsNhanVien;
  delete slNhanVien;
  delete tongLuong;
  delete maNhanVienCanTim;

  return 0;
}