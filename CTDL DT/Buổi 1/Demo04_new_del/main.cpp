#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int *p = new int(10);

    cout << "Chua" << endl;
    cout << p << endl;
    cout << *p << endl;

    delete p;
    cout << "Sau thu hồi " << endl;
    cout << p << endl;
    p = nullptr;
    cout << "In thủ p ra sau khi thu hồi" << p << endl;
    return 0;
}