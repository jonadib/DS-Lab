#include<bits/stdc++.h>
using namespace std;

// Node structure for stack
struct Node{
    int val;
    Node *next;
};

// Top pointer
Node *top = NULL;

// Push function
void push_(int x){
    Node *newnode = new Node;
    newnode->val = x;
    newnode->next = top;
    top = newnode;
}

// Pop function
void pop_(){
    if(top != NULL){
        top = top->next; N
    }
}

// Get top value
int peek(){
    return top->val;
}

// Function to evaluate postfix  
int evaluatePostfix(string exp){

    map<char, int> values;

    for(int i = 0; i < exp.size(); i++){
        char ch = exp[i];

        // If operand
        if(isalnum(ch)){

            // If variable, take input
            if(isalpha(ch) && values.find(ch) == values.end()){
                cout << "Enter value of " << ch << ": ";
                cin >> values[ch];
            }

            int val;

            // Normal if-else (no ternary)
            if(isalpha(ch)){
                val = values[ch];
            } else {
                val = ch - '0';
            }

            push_(val);
        }

        // If operator
        else{

            int val2 = peek(); pop_();
            int val1 = peek(); pop_();

            if(ch == '+') push_(val1 + val2);
            else if(ch == '-') push_(val1 - val2);
            else if(ch == '*') push_(val1 * val2);
            else if(ch == '/') push_(val1 / val2);
            else if(ch == '^') push_(pow(val1, val2));
        }
    }

    return peek();
}

int main(){
    string input = "ab2*c3^/-";

    int result = evaluatePostfix(input);

    cout << "\nResult = " << result << endl;

    return 0;
}