#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

/**
 * Yêu cầu: Khởi tạo 1 Node mới với data = data input
 *  Input:
 *         + int data;
 *  Output:
 *         + Node *pNode;
 */
Node *initNode(int data)
{
    Node *pNode = new Node;
    pNode->data = data;
    pNode->pNext = nullptr;
    return pNode;
}

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

/**
 * Yêu cầu: Khởi tạo 1 Bucket rỗng
 *  Input:
 *         + Bucket &bucket;
 *  Output:
 *        + Bucket &bucket;
 */
void initBucket(Bucket &bucket)
{
    bucket.pHead = nullptr;
    bucket.pTail = nullptr;
};

struct HashTable
{
    Bucket *buckets;
    int size;
};

/**
 * Yêu cầu: Khởi tạo 1 HashTable với size bucket
 *  Input:
 *         + HashTable &hashTable;
 *         + int size;
 *  Output:
 *         + HashTable &hashTable;
 */
void initHashTable(HashTable &hashTable, int size)
{
    hashTable.size = size;
    hashTable.buckets = new Bucket[size];
    for (int i = 0; i < size; i++)
    {
        initBucket(hashTable.buckets[i]);
    }
}

/**
 * Yêu cầu: Hàm băm
 *  Input:
 *         + int value;
 *         + int size;
 *  Output:
 *         + int index;
 */
int hashFunction(int value, int size)
{
    return value % size;
}

/**
 * Yêu cầu: Thêm 1 Node vào cuối Bucket
 *  Input:
 *         + Bucket &bucket;
 *         + int value;
 *  Output:
 *         + Bucket &bucket;
 */
void push(Bucket &bucket, int value)
{
    Node *newNode = initNode(value);
    if (bucket.pHead == nullptr)
    {
        bucket.pHead = newNode;
        bucket.pTail = newNode;
    }
    else
    {
        bucket.pTail->pNext = newNode;
        bucket.pTail = newNode;
    }
}

/**
 * Yêu cầu: Thêm dữ liệu vào HashTable
 *  Input:
 *         + HashTable &hashTable;
 *         + int value;
 *  Output:
 *         + HashTable &hashTable;
 */
void add(HashTable &hashTable, int value)
{
    int index = hashFunction(value, hashTable.size);
    push(hashTable.buckets[index], value);
}

/**
 * Yêu cầu: In HashTable
 *  Input:
 *         + HashTable &hashTable;
 *  Output:
 *         + cout;
 */
void printHashTable(HashTable &hashTable)
{
    for (int i = 0; i < hashTable.size; i++)
    {
        cout << "Bucket " << i << ": ";
        Node *temp = hashTable.buckets[i].pHead;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->pNext;
        }
        cout << endl;
    }
}

int main()
{
    HashTable hashTable;
    initHashTable(hashTable, 7);
    add(hashTable, 50);
    add(hashTable, 73);
    add(hashTable, 35);
    add(hashTable, 36);
    add(hashTable, 64);
    add(hashTable, 28);
    add(hashTable, 90);
    add(hashTable, 21);
    add(hashTable, 53);
    add(hashTable, 53);
    add(hashTable, 13);
    add(hashTable, 51);
    add(hashTable, 54);
    printHashTable(hashTable);
    return 0;
}