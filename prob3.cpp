#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Find location (like node count during traversal)
int findLocation(Node* root, int val, int pos = 1) {
    if (!root) return -1;

    if (root->data == val)
        return pos;

    if (val < root->data)
        return findLocation(root->left, val, pos * 2);
    else
        return findLocation(root->right, val, pos * 2 + 1);
}

void print(Node* root, int pos = 1) {
    if (!root) return;
    cout << root->data << "(" << pos << ") ";
    print(root->left, pos * 2);
    print(root->right, pos * 2 + 1);
}

int main() {
    int arr[] = {50, 20, 45, 70, 5};
    Node* root = NULL;

    for (int x : arr)
        root = insert(root, x);

    int x;
    while (true) {
        cout << "\nEnter value (-1 to exit): ";
        cin >> x;

        if (x == -1) break;

        int loc = findLocation(root, x);

        if (loc != -1) {
            cout << "Data found at location: " << loc << endl;
        } else {
            root = insert(root, x);
            cout << "Inserted.\n";
        }
    }

    cout << "\nBST (data(position)): ";
    print(root);
}