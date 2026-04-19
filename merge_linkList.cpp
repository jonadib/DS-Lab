#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
public:
    node *head;
    node *tail;
    LinkedList()
    {
        head = tail = nullptr;
    }

    void insertAtBegin(int x)
    {
        node *begin = new node(x);
        if (head == nullptr)
        {
            head = tail = begin;
            return;
        }
        begin->next = head;
        head = begin;
    }

    void insertAtEnd(int value)
    {
        node *newnode = new node(value);

        if (head == nullptr)
        {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void merge(LinkedList &other)
    {
        if (other.head == nullptr)
            return;

        if (head == nullptr)
        {
            tail = other.tail;
            head = other.head;
            return;
        }

        tail->next = other.head;
        tail = other.tail;
    }

    void commonElements(LinkedList &other){
        node* temp1 = head;
        node* temp2 = other.head;
        cout <<"Common ELements : ";
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->data == temp2->data){
                cout<<temp1->data<<" ";

                temp1= temp1->next;
                temp2= temp2->next;
            }
            if(temp1->data < temp2->data){
                temp1 = temp1->next;
            }
            else{
                temp2 = temp2->next;

            }
        }
        cout<<endl;
    }

    void print()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{

    LinkedList list1, list2;
    list1.insertAtBegin(5);
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    list2.insertAtBegin(35);
    list2.insertAtEnd(40);
    list2.insertAtEnd(50);
    list2.insertAtEnd(60);

    cout << "List 1 : ";
    list1.print();
    cout << "List 2 : ";
    list2.print();

    list1.commonElements(list2);

    list1.merge(list2);
    cout << "Merged List : ";
    list1.print();
   



    return 0;
}