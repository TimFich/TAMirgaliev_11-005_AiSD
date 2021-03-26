#include <iostream>

using namespace std;
struct Node {
    int value;
    Node *next = nullptr;
    Node *previous = nullptr;
};

struct SortedList {
    Node *pHead = nullptr;


    void add(int item) {
        int count = 0;
        Node *node = new Node;
        node->value = item;
        if (pHead == nullptr) {
            pHead = node;
            return;
        }
        Node *tempHead = pHead;
        while (tempHead->next != nullptr) {
            if (node->value > tempHead->value) {
                tempHead = tempHead->next;
                count++;
            } else break;
        }
        if (node->value <= tempHead->value) {
            if (count == 0) {
                node->next = pHead;
                pHead = node;
            } else {
                tempHead->previous->next = node;
                node->previous = tempHead->previous;
                tempHead->previous = node;
                node->next = tempHead;
            }
        } else {
            tempHead->next = node;
            node->previous = tempHead;
            count = 0;
        }
    }

    int get(int id) {
        int count = 0;
        int value;
        Node *tempHead = pHead;
        while (count != id) {
            count++;
            tempHead = tempHead->next;
            value = tempHead->value;
        }
        return value;
    }

    int size() {
        Node *tempHead = pHead;
        int count = 1;
        while (tempHead->next != nullptr) {
            tempHead = tempHead->next;
            count++;
        }
        return count;
    }


    void remove(int id) {
        Node *tempHead = pHead;
        int count = 0;
        while (tempHead != nullptr && id != count) {
            count++;
            tempHead = tempHead->next;
        }
        if (id == 0) {
            pHead->next->previous = nullptr;
            pHead = pHead->next;
        } else if (id == size() - 1) {
            tempHead->previous->next = nullptr;
            tempHead = tempHead->previous;

        } else {
            tempHead->previous->next = tempHead->next;
            tempHead->next->previous = tempHead->previous;
        }
    }


    void UniqueAdd(int item) {
        int count = 0;
        Node *node2 = new Node;
        node2->value = item;
        if (pHead == nullptr) {
            pHead = node2;
            return;
        }
        Node *tempHead = pHead;

        while (tempHead->next != nullptr) {
            if (node2->value > tempHead->value) {
                tempHead = tempHead->next;
                count++;
            } else break;
        }
        if (node2->value < tempHead->value) {
            if (count == 0) {
                node2->next = pHead;
                pHead = node2;
            } else {
                tempHead->previous->next = node2;
                node2->previous = tempHead->previous;
                tempHead->previous = node2;
                node2->next = tempHead;
            }
        } else if (node2->value != tempHead->value) {
            tempHead->next = node2;
            node2->previous = tempHead;
            count = 0;
        }

    }
};

SortedList *Union(SortedList *a, SortedList *b) {
    SortedList *unionList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value < temp2->value) {
            unionList->add(temp->value);
            temp = temp->next;
        } else if (temp->value == temp2->value) {
            unionList->add(temp2->value);
            temp2 = temp2->next;
            temp = temp->next;
        } else {
            unionList->add(temp2->value);
            temp2 = temp2->next;
        }

    }
    return unionList;
}

SortedList *Intersect(SortedList *a, SortedList *b) {
    SortedList *intersectList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value == temp2->value) {
            intersectList->add(temp->value);
            temp2 = temp2->next;

        } else if (temp->value < temp2->value)
            temp = temp->next;
        else temp2 = temp2->next;

    }
    return intersectList;

}

SortedList *Difference(SortedList *a, SortedList *b) {
    SortedList *differenceList = new SortedList;
    Node *temp = a->pHead;
    Node *temp2 = b->pHead;
    while (temp != nullptr && temp2 != nullptr) {
        if (temp->value == temp2->value) {
            temp = temp->next;

        } else if (temp->value > temp2->value)
            temp2 = temp2->next;
        else {
            differenceList->add(temp->value);
            temp = temp->next;
        }
    }
    return differenceList;
}

void printAll(SortedList *a) {
    Node *tempHead = a->pHead;
    while (tempHead != nullptr) {
        cout << tempHead->value << " ";
        tempHead = tempHead->next;
    }
}

int main() {
    SortedList *sortedList =new SortedList;
    sortedList->add(15);
    sortedList->add(30);
    sortedList->add(25);
    sortedList->add(5);
    sortedList->add(2);
    printAll(sortedList);
    cout<< endl;

    SortedList *uniqueSortedList = new SortedList;

    uniqueSortedList->UniqueAdd(5);
    uniqueSortedList->UniqueAdd(6);
    uniqueSortedList->UniqueAdd(5);
    uniqueSortedList->UniqueAdd(6);
    uniqueSortedList->UniqueAdd(20);
    uniqueSortedList->UniqueAdd(21);
    printAll(uniqueSortedList);
    cout<<endl;

    SortedList *uniqueSortedList1 = new SortedList;
    uniqueSortedList1->UniqueAdd(3);
    uniqueSortedList1->UniqueAdd(36);
    uniqueSortedList1->UniqueAdd(36);
    uniqueSortedList1->UniqueAdd(21);
    uniqueSortedList1->UniqueAdd(25);
    printAll(uniqueSortedList1);
    cout<<endl;

    printAll(Union(uniqueSortedList,uniqueSortedList1));
    cout<<endl;
    printAll(Intersect(uniqueSortedList,uniqueSortedList1));
    cout<<endl;
    printAll(Difference(uniqueSortedList,uniqueSortedList1));
    return 0;
}