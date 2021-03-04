#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
};

struct Stack {
    Node *pHead = nullptr;

    void Push(int value) {
        Node *node = new Node;
        node->value = value;
        node->next = pHead;
        pHead = node;
    }

    int Pop() {
        int temp = pHead->value;
        pHead = pHead->next;
        return temp;
    }

    int Peek() {
        return pHead->value;

    }

    void printAll() {
        while (pHead != pHead->next->next->next) {
            cout << pHead->value;
            pHead = pHead->next;
        }
    }
};


int main() {
    Stack *pStack = new Stack;
    pStack->Push(5);
    pStack->Push(10);
    pStack->Push(15);
    pStack->Push(20);
    pStack->printAll();
    return 0;
}
