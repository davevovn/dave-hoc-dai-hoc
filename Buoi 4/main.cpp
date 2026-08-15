#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

typedef struct SinhVien
{
    int MaSV;
    string HoTen;
    float DiemTB;
} SV;

typedef struct NodeSV
{
    SV data;
    NodeSV *next;
} NodeSV;
typedef struct ListSV
{
    NodeSV *pHead;
    NodeSV *pTail;
} ListSV;

/**
 * Yêu cầu: Tạo 1 Node với giá trị là value
 *  Input:
         + SV value;
 *  Output:
         + NodeSV* node;
 */
NodeSV *initNodeSV(SV value)
{
    NodeSV *node = new NodeSV();
    node->data = value;
    node->next = nullptr;

    return node;
}

/**
 * Yêu cầu: Tạo 1 List rỗng
 *  Input:
 *  Output:
 *         + ListSV* list;
 */
ListSV *initListSV()
{
    ListSV *list = new ListSV();
    list->pHead = nullptr;
    list->pTail = nullptr;
    return list;
}

/*
* Yêu cầu: Thêm 1 Node vào đầu List
 *  Input:
         + ListSV* l;
         + SV value;
 *  Output:
         + ListSV* l;
*/
void addFirst(ListSV *l, SV value)
{
    NodeSV *newNode = initNodeSV(value);
    if (l->pHead == nullptr)
    {
        l->pHead = newNode;
        l->pTail = newNode;
    }
    else
    {
        newNode->next = l->pHead;
        l->pHead = newNode;
    }
}

/*
* Yêu cầu: Thêm 1 Node vào cuối List
 *  Input:
         + ListSV* l;
         + SV value;
 *  Output:
         + ListSV* l;
*/
void addLast(ListSV *l, SV value)
{
    NodeSV *newNode = initNodeSV(value);
    if (l->pHead == nullptr)
    {
        l->pHead = newNode;
        l->pTail = newNode;
    }
    else
    {
        l->pTail->next = newNode;
        l->pTail = newNode;
    }
}

/*
 * Yêu cầu: Thêm dữ liệu mẫu vào List
 *  Input:
 *         + ListSV* l;
 *  Output:
 *         + ListSV* l;
 */
void seedTestDataToList(ListSV *l)
{
    addLast(l, {123, "Nguyen Van A", 9.1});
    addLast(l, {124, "Nguyen Van B", 8.8});
    addLast(l, {125, "Nguyen Van C", 9.1});
    addLast(l, {126, "Nguyen Van D", 2.1});
    addLast(l, {127, "Nguyen Van F", 9.7});
    addLast(l, {128, "Nguyen Van G", 4.1});
    addLast(l, {129, "Nguyen Van H", 8.3});
    addLast(l, {130, "Nguyen Van K", 7.9});
}

/**
 * Yêu cầu: In danh sách liên kết đơn
 *  Input:
        + ListSV* l;
 *  Output:
        + cout;
 */
void printListSV(ListSV *l)
{
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        cout << "MaSV: " << temp->data.MaSV << ", HoTen: " << temp->data.HoTen << ", DiemTB: " << temp->data.DiemTB << endl;
        temp = temp->next;
    }
}

/*
 * Yêu cầu: Tìm điểm cao nhất trong danh sách
 *  Input:
 *         + ListSV* l;
 *  Output:
 *         + float maxScore;
 */
float findMaxScore(ListSV *l)
{
    float maxScore = 0;
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        if (temp->data.DiemTB > maxScore)
        {
            maxScore = temp->data.DiemTB;
        }
        temp = temp->next;
    }
    return maxScore;
}

/**
 * Yêu cầu: Tìm tất cả sinh viên có điểm cao nhất
 *  Input:
 *         + ListSV* l;
 *  Output:
 *         + ListSV* maxScoreList;
 */
ListSV *findAllMaxScore(ListSV *l)
{
    float maxScore = findMaxScore(l);
    ListSV *maxScoreList = initListSV();
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        if (temp->data.DiemTB == maxScore)
        {
            addLast(maxScoreList, temp->data);
        }
        temp = temp->next;
    }
    return maxScoreList;
}
/**
 * Yêu cầu: Tìm điểm thấp nhất trong danh sách
 *  Input:
 *         + ListSV* l;
 *  Output:
 *         + float minScore;
 */
float findMinScore(ListSV *l)
{
    float minScore = 10;
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        if (temp->data.DiemTB < minScore)
        {
            minScore = temp->data.DiemTB;
        }
        temp = temp->next;
    }
    return minScore;
}

/**
 * Yêu cầu: Tìm tất cả sinh viên có điểm thấp nhất
 *  Input:
 *         + ListSV* l;
 *  Output:
 *         + ListSV* minScoreList;
 */
ListSV *findAllMinScore(ListSV *l)
{
    float minScore = findMinScore(l);
    ListSV *minScoreList = initListSV();
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        if (temp->data.DiemTB == minScore)
        {
            addLast(minScoreList, temp->data);
        }
        temp = temp->next;
    }
    return minScoreList;
}

/**
 * Yêu cầu: Xóa danh sách liên kết đơn
 *  Input:
        + ListSV* l;
 *  Output:
        + void;
 */
void deleteListSV(ListSV *l)
{
    NodeSV *temp = l->pHead;
    while (temp != nullptr)
    {
        NodeSV *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    l->pHead = nullptr;
    l->pTail = nullptr;
}

int main()
{

    ListSV *l = initListSV();
    seedTestDataToList(l);
    cout << "Test: Danh sach sinh vien: " << endl;
    printListSV(l);

    cout << "Test add first with score 9.7 to test maxscore later:" << endl;
    addFirst(l, {131, "Nguyen Van Z", 9.7});
    printListSV(l);

    cout << "Test add last with score 2.1 to test minscore later:" << endl;
    addLast(l, {132, "Nguyen Van Y", 2.1});
    printListSV(l);

    cout << "Test: Diem cao nhat: " << findMaxScore(l) << endl;
    cout << "Test: Danh sach sinh vien co diem cao nhat: " << endl;
    ListSV *maxScoreList = findAllMaxScore(l);
    printListSV(maxScoreList);
    cout << "Test: Diem thap nhat: " << findMinScore(l) << endl;
    cout << "Test: Danh sach sinh vien co diem thap nhat: " << endl;
    ListSV *minScoreList = findAllMinScore(l);
    printListSV(minScoreList);

    deleteListSV(l);
    deleteListSV(maxScoreList);
    deleteListSV(minScoreList);

    return 0;
}