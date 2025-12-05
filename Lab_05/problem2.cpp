#include <bits/stdc++.h>
using namespace std;

// Node structure for AVL Tree
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        key = data;
        left = right = NULL;
        height = 1;
    }
};

// Get height of a node
int height(Node* n) {
    return n ? n->height : 0;
}

// Get balance factor
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotation (LL)
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation (RR)
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert into AVL Tree
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root; // duplicates not allowed

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rotateRight(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Find minimum value node
Node* minValueNode(Node* root) {
    Node* current = root;
    while (current->left)
        current = current->left;
    return current;
}

// Delete from AVL Tree
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    // LR Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    // RL Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert values
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 10);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    // Delete value
    root = deleteNode(root, 20);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
