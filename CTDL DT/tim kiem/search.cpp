#include <iostream>

using namespace std;

/** Yêu cầu: In mảng
 * Input:
 *    + int*a;
 *    + int n;
 * Output:
 *    + cout;
 */
void inMang(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << *(a + i) << " ";
  }
  cout << endl;
}

/** Yêu cầu: Tìm kiếm tuyến tính
 * Input:
 *    + int*a;
 *    + int n;
 *    + int value;
 * Output:
 *    + bool;
 */
bool linearSearch(int *a, int n, int value) {
  for (int i = 0; i < n; i++) {
    if (*(a + i) == value) {
      return true;
    }
  }
  return false;
}

/** Yêu cầu: Tìm kiếm nhị phân
 * Input:
 *    + int*a;
 *    + int n;
 *    + int value;
 * Output:
 *    + bool;
 */
bool binarySearch(int *a, int n, int value) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int m = (left + right) / 2;
    if (*(a + m) == value) {
      return true;
    }
    if (*(a + m) > value) {
      right = m - 1;
    } else {
      left = m + 1;
    }
  }
  return false;
}

/** Yêu cầu: Tìm kiếm nội suy
 * Input:
 *    + int*a;
 *    + int n;
 *    + int value;
 * Output:
 *    + bool;
 */
bool interpolationSearch(int *a, int n, int value) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int m = left + ((right - left) / (a[right] - a[left])) * (value - a[left]);
    if (*(a + m) == value) {
      return true;
    }
    if (*(a + m) > value) {
      right = m - 1;
    } else {
      left = m + 1;
    }
  }
  return false;
}

int main() {

  srand(time(NULL));

  int *a = new int[100]{23, 67, 32, 12, 65, 89, 12, 65, 22, 45};
  int n = 10;

  inMang(a, n);
  int value = 200;
  cout << "tìm số 200:(0)" << linearSearch(a, n, value) << endl;
  value = 65;
  cout << "tìm số 65:(1)" << linearSearch(a, n, value) << endl;

  int *b = new int[100]{11, 33, 55, 45, 65, 83, 99, 114, 345, 675};
  n = 10;

  inMang(b, n);

  cout << "tìm số 200:(0)" << binarySearch(b, n, 200) << endl;
  cout << "tìm số 99:(1)" << binarySearch(b, n, 99) << endl;

  cout << "tìm số 200:(0)" << interpolationSearch(b, n, 200) << endl;
  cout << "tìm số 99:(1)" << interpolationSearch(b, n, 99) << endl;

  return 0;
}