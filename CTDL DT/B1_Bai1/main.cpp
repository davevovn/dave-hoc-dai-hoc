#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
float getRandomFloatNumber(float min, float max)
{
    return getRandomNumber(min * 100, max * 100) / 100.0f;
}

void seedRandomFloatData(float *arr, int n, float min, float max)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = getRandomFloatNumber(min, max);
    }
}
void printArr(float *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}
float sumFloatArr(float *arr, int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}
void sumAndMultiply(float *arr, int n, float &sum, float &multiply)
{
    sum = 0.0f;
    multiply = 1.0f;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        multiply *= arr[i];
    }
}
int countAppearance(float *arr, int n, float value)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            count++;
        }
    }
    return count;
}

void printEvenOdd(float *arr, int n, bool isEven)
{
    cout << "Các giá trị " << (isEven ? "chẵn" : "lẻ") << " trong mảng là: " << endl;
    for (int i = 0; i < n; i++)
    {
        bool theNumberIsEven = static_cast<int>(arr[i]) % 2 == 0;
        if (isEven == theNumberIsEven)
        {
            cout << arr[i] << endl;
        }
    }
    cout << endl;
}
float findMin(float *arr, int n)
{
    float min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
float *reverseArr(float *arr, int n)
{
    float *reverseArr = new float[n];
    for (int i = 0; i < n; i++)
    {
        reverseArr[i] = arr[n - 1 - i];
    }
    return reverseArr;
}

int countInRange(float *arr, int n, float min, float max)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= min && arr[i] <= max)
        {
            count++;
        }
    }
    return count;
}
float *filterInRange(float *arr, int n, float min, float max, int &newSize)
{
    newSize = countInRange(arr, n, min, max);
    float *filteredArr = new float[newSize];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= min && arr[i] <= max)
        {
            filteredArr[index++] = arr[i];
        }
    }
    return filteredArr;
}
float *filterNegative(float *arr, int n, int &newSize)
{
    newSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            newSize++;
        }
    }
    float *filteredArr = new float[newSize];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            filteredArr[index++] = arr[i];
        }
    }
    return filteredArr;
}

int main()
{
    srand(time(NULL));

    int n = getRandomNumber(10, 20);
    float *arr = new float[n];
    // 1
    seedRandomFloatData(arr, n, -268.0f, 339.0f);

    // 2
    printArr(arr, n);
    // 3
    cout << "Tổng của mảng là: " << sumFloatArr(arr, n) << endl;

    // 4
    float sum, multiply;
    sumAndMultiply(arr, n, sum, multiply);
    cout << "Tổng của mảng là: " << sum << "Tích của mảng là: " << multiply << endl;

    // 5
    cout << "Số lần xuất hiện của giá trị 0 là: " << countAppearance(arr, n, 0.0f) << endl;
    cout << "Số lần xuất hiện của giá trị arr[0] là: " << countAppearance(arr, n, *(arr)) << endl;

    // 6
    printEvenOdd(arr, n, true);
    printEvenOdd(arr, n, false);

    // 7
    cout << "Phần tử có giá trị nhỏ nhất: " << findMin(arr, n) << endl;

    // 8

    float *reversedArr = reverseArr(arr, n);

    printArr(reversedArr, n);

    // 9

    int negativeSize = 0;
    float *negativeArr = filterNegative(arr, n, negativeSize);
    cout << "Các phần tử âm trong mảng là: " << endl;
    printArr(negativeArr, negativeSize);

    // 10
    cout << "Số lượng phần từ trong phạm vi -100 đến 100 là: " << countInRange(arr, n, -100.0f, 100.0f) << endl;

    // 11

    int newSize;
    float *filteredArr = filterInRange(arr, n, -100.0f, 100.0f, newSize);
    cout << "Các phần tử trong phạm vi -100 đến 100 là: " << endl;
    printArr(filteredArr, newSize);

    delete[] arr;
    delete[] reversedArr;
    delete[] filteredArr;
    return 0;
}