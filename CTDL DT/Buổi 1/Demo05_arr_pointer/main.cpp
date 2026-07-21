#include <iostream>

using namespace std;

int main()
{
    int a[10] = {2, 6, 9, 4, 6, 8};
    int n = 6;

    cout << "a = " << a << endl;
    for (int i = 0; i < n; i++)
    {
        cout << &a[i] << " = " << a[i] << endl;
    }
    return 0;
}