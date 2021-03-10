#include <iostream>
using namespace std;

struct Node {
    int x;
    Node *next = nullptr;
    Node *prev = nullptr;
};
struct List {
    Node *head = nullptr;
    Node *tail = nullptr;

    void add(int x) {
        Node *node = new Node;
        node->x = x;
        if (!head){
            head = node;
            tail = node;
        } else {
            Node *temp = head;
            while (temp->next){
                temp = temp->next;
            }
            node->prev = temp;
            temp->next = node;
            tail = node;
        }
    }

    int size(){
        if (!head){
            return 0;
        } else{
            Node *temp = head;
            int size = 0;
            while (temp){
                size++;
                temp = temp->next;
            }
            return size;
        }

    }

    int get(int id){
        if (id == 0) {
            return head->x;
        } else {
            Node *temp = head;
            int count = 1;
            while (count < id){
                temp = temp->next;
                count++;
            }
            return temp->next->x;

        }
    }

    void printAllFromHead(){
        Node * temp = head;
        while (temp){
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void printAllFromTail(){
        Node * temp = tail;
        while (temp){
            cout << temp->x << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void insertAt(int x, int id){
        Node *node = new Node;
        node->x = x;
        if (id == 0) {
            node->next = head;
            head = node;
        } else if(id == size()) {
            tail->next = node;
            node->prev= tail;
            tail = node;
        } else {
            int count = 1;
            Node * temp = head;
            while (count <id){
                temp = temp->next;
                count++;
            }

            node->prev = temp;
            node->next = temp->next;
            temp->next = node;
            temp->next->prev = node;
        }

    }
    void removeAt(int id) {
        if (id == 0) {
            head = head->next;
            head->prev = nullptr;
        } else if(id == size()-1) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            int count = 1;
            Node * temp = head;
            while (count <=id){
                temp = temp->next;
                count++;
            }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
        }
    }

};

struct Queue{
    Node *head = nullptr;
    Node *tail = nullptr;
    void enqueue(int x) {
        Node *node = new Node;
        node->x = x;
        if (!head){
            head = node;
            tail = node;
        } else {
            Node *temp = head;
            while (temp->next){
                temp = temp->next;
            }
            node->prev = temp;
            temp->next = node;
            tail = node;
        }
    }
    void dequeue(){
        head = head->next;
        head->prev = nullptr;
    };
    void printAll(){
        Node * temp = tail;
        while (temp){
            cout << temp->x << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    List * list = new List;
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    list->printAllFromHead();
    list->printAllFromTail();
    cout << list->size() << endl;
    cout << list->get(0) << endl;
    list->insertAt(6,3);
    list->printAllFromHead();
    list->removeAt(2);
    list->printAllFromHead();
    cout << "---------" << endl;

    Queue *queue = new Queue;

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    queue->printAll();
    queue->dequeue();
    queue->enqueue(6);
    queue->printAll();


    return 0;
}
