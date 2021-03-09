/**
 * Author: NJartist
 * Date: 2021/3/9
 * Description: Sequence Queue(Circular Queue)
 */
#include <iostream>

using namespace std;

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front,rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool IsEmpty(SqQueue &Q) {
    if (Q.front == Q.rear) {
        return true;
    } else {
        return false;
    }
}

bool EnQueue(SqQueue &Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front) {
        return false;
    } else {
        Q.data[Q.rear] = x;
        Q.rear = (Q.rear + 1) % MaxSize; // caution! : compare with Stack 
        return true;
    }
}

bool Dequeue(SqQueue &Q, int &x) {
    if (Q.front == Q.rear) {
        return false;
    } else {
        x = Q.data[Q.front];
        Q.front = (Q.front + 1) % MaxSize; // caution! compare with Stack
        return true;
    }
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    cout << IsEmpty(Q) << endl;
    EnQueue(Q, 1);
    cout << IsEmpty(Q) << endl;
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    int x = -1;
    Dequeue(Q, x);
    cout << x << endl;
    Dequeue(Q, x);
    cout << x << endl;
}