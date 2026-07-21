#include <iostream>

using namespace std;

int main()
{
    int x;
    int *p1;
    int *p2 = nullptr;
    int n = 36;
    int *p3 = &n;
    cout << *p3 << endl;
    return 0;
}