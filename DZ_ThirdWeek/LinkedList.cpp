#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
};

struct linkedList {

    Node *pHead = nullptr;

    void add(int item) {
        Node *node = new Node;
        node->value = item;
        if (pHead == nullptr) {
            pHead = node;
            return;
        }
        Node *temp = pHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }

    int get(int id) {
        int count = 0;
        Node *temp = pHead;
        while (count != id) {
            count++;
            temp = temp->next;
        }
        return temp->value;
    }

    int size() {
        Node *temp = pHead;
        int count = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    void printAll() {
        Node *temp = pHead;
        while (temp != nullptr) {
            cout << pHead->value << " ";
            temp = temp->next;
        }
    }


};

int main() {
    linkedList *plist = new linkedList;
    plist->add(5);
    plist->add(10);
    plist->add(15);
    plist->add(20);
    cout << plist->get(0) << endl;
    cout << plist->size() << endl;
    return 0;
}