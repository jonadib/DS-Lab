#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertAfterPrime(Node* head) {
    Node* temp = head;

    while (temp) {
        if (isPrime(temp->data)) {
            Node* newNode = new Node(100);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next; // skip inserted node
        } else {
            temp = temp->next;
        }
    }
}

void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    int arr[] = {4, 5, 10, 21, 23, 37, 64, 32};

    for (int x : arr)
        insertEnd(head, x);

    insertAfterPrime(head);

    print(head);
}