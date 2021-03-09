/**
 * Author: NJartist
 * Date: 2021/3/9
 * Description: Sequence Stack
 */
#include <iostream>
using namespace std;

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

void initStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack &S) {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

bool Push(SqStack &S, int x) {
    if (S.top == MaxSize - 1) {
        return false;
    } else {
        S.top++;
        S.data[S.top] = x;
        return true;
    }
}

bool Pop(SqStack &S, int &x) {
    if (S.top == -1) {
        return false;
    } else {
        x = S.data[S.top];
        S.top--;
        return true;
    }
}

bool GetPop(SqStack &S, int &x) {
    if (S.top == -1) {
        return false;
    } else {
        x = S.data[S.top];
        return true;
    }
}

int main() {
    SqStack S;
    initStack(S);
    cout << StackEmpty(S) << endl;
    Push(S, 1);
    cout << StackEmpty(S) << endl;
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    Push(S, 6);
    int x = -1;
    Pop(S, x);
    cout << x << endl;
    GetPop(S, x);
    cout << x << endl;
}