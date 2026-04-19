#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    
    node(int value){
        data = value;
        next = nullptr;
    }
};

void inseratBegin(node*&head , int value){
    node* newNode = new node(value);
    newNode->next =head;
    head = newNode;
    
}

void insertEnd(node*&head , int value){
    node* newNode = new node(value);
    
    if( head == nullptr){
        head = newNode;
        return ;
    }
    
    node* temp = head;
    while(temp->next != nullptr ){
        temp=temp->next;
    }
    temp->next = newNode;
    
}

void printAll( node* head){
    node* temp = head;
    while( temp!= nullptr){
        cout<<temp->data<<" ->";
        temp=temp->next ;
    }
    
}

int main(){
    
 node* head = nullptr;
 inseratBegin(head , 10);
 inseratBegin(head , 20);
 inseratBegin(head , 30);
 insertEnd(head , 50);
 
    
    cout<<" Node " ;
    printAll(head) ;
    return 0;
    
}