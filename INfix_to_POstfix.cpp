#include <iostream>
#include <string>
#include <cctype>
using namespace std;
struct Node{
    char c;
    Node *next;
};
Node *top=NULL;

void print_(){
    Node *top1=top;
    while(top1!=NULL){
        cout<<top1->c<<" ";
        top1=top1->next;
    }
}

void push_(char ch){
    Node *newnode =new Node;
    newnode->c=ch;
    newnode->next=top;
    top=newnode;
}
void pop_(){
    top=top->next;
}
int prec(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/'||c=='%')return 2;
    if(c=='+'||c=='-')return 1;
    return 0;
}
int main(){
    string s,ans="";
    cin>>s;
    s="("+s+")";
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            ans+=s[i];
        }
        else if(s[i]=='('){
            push_(s[i]);
        }
        else if (s[i]==')'){
            while(top and top->c!='('){
                ans+=top->c;
                pop_();
            }
            pop_();
        }
        else{
            while(top and prec(top->c)>=prec(s[i])){
                ans+=top->c;
                pop_();
            }
            push_(s[i]);
        }
        cout<<s[i]<<"\t";
        print_();
        cout<<"\t"<<ans<<endl;
    }
    cout<<endl;
    cout<<ans<<endl;

    return 0;
}