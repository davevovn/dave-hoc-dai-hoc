#include <iostream>

using namespace std;

void loadArr(int *a, int &n)
{
    cout << "Mình sẽ init 3 phần từ cho a" << endl;
    *a = 2;
    *(a + 1) = 77;
    *(a + 2) = 99;
    n = 3;
}
void printArr(int *a, int &n)
{
    cout << "Các phần từ của a là:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << endl;
    }
}
int main()
{
    int *a = new int[10];
    int n = 0;
    loadArr(a, n);
    printArr(a, n);
    delete[] a;
    a = nullptr;

    return 0;
}