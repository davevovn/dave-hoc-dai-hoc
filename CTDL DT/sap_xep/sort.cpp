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

/** Yêu cầu: Sắp xếp chọn
 * Input:
 *    + int*a;
 *    + int m;
 * Output:
 *    + int *a;
 */
void selectionSort(int *a, int n) {

  for (int i = 0; i < n - 1; i++) {
    int m = i;
    for (int j = i + 1; j < n; j++) {
      if (*(a + j) < *(a + m)) {
        m = j;
      }
    }
    swap(*(a + i), *(a + m));
  }
}

/** Yêu cầu: Sắp xếp chèn
 * Input:
 *    + int*a;
 *    + int m;
 * Output:
 *    + int*a;
 */
void insertionSort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int value = *(a + i);
    int j;
    for (j = i - 1; j >= 0; j--) {
      if (*(a + j) < value) {
        break;
      }
      *(a + j + 1) = *(a + j);
    }
    *(a + j + 1) = value;
  }
}

int main() {

  int *a = new int[100]{23, 67, 32, 12, 65, 89, 12, 65, 22, 45};
  int n = 10;

  inMang(a, n);

  selectionSort(a, n);

  inMang(a, n);

  int *b = new int[100]{23, 67, 32, 12, 65, 89, 12, 65, 22, 45};
  inMang(b, n);
  insertionSort(b, n);
  inMang(b, n);

  return 0;
}