/**
 * Author: NJartist
 * Date: 2021/3/10
 * Description: Sequence List
 */
#include <iostream>

using namespace std;

#define MaxSize 10

//静态分配
typedef struct {
    int data[MaxSize];
    int length;
} SqList_static;

#define InitSize 100 //表长度的初始定义

//动态分配 分配语句为 L.data = new int[InitSize];
typedef struct {
    int *data;
    int length,maxsize; //数组的当前长度和最大容量
} SqList_dynamic;

bool InitData(SqList_static &L) {
    L.length = 0;
    return true;
}

bool ListInsert(SqList_static &L, int i, int e) {
    if (L.length == MaxSize) {
        return false;
    }
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    for (int j = L.length; j >= i ; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList_static &L, int i, int &e) {
    if (L.length == 0) {
        return false;
    }
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList_static L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    SqList_static L;
    InitData(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 6);
    int x = -1;
    ListDelete(L, 6, x);
    cout << LocateElem(L, 6) << endl;
    cout << LocateElem(L, 3) << endl;
}