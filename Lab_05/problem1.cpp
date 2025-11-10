#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

/*
BST Operation Time Complexities:
-----------------------------------
Insert       → O(h)
Find Min/Max → O(h)
Successor    → O(h)
Predecessor  → O(h)
Delete       → O(h)
Traversal    → O(n)
where h = height of BST
*/

// ----------------------------------------------------
// INSERT - O(h)
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// ----------------------------------------------------
// FIND MINIMUM - O(h)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// FIND MAXIMUM - O(h)
Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// ----------------------------------------------------
// SUCCESSOR - O(h)
Node* successor(Node* root, int val) {
    Node* succ = NULL;
    while (root) {
        if (val < root->data) {
            succ = root;
            root = root->left;
        } else if (val > root->data)
            root = root->right;
        else
            break;
    }
    if (root && root->right)
        succ = findMin(root->right);
    return succ;
}

// ----------------------------------------------------
// PREDECESSOR - O(h)
Node* predecessor(Node* root, int val) {
    Node* pred = NULL;
    while (root) {
        if (val > root->data) {
            pred = root;
            root = root->right;
        } else if (val < root->data)
            root = root->left;
        else
            break;
    }
    if (root && root->left)
        pred = findMax(root->left);
    return pred;
}

// ----------------------------------------------------
// DELETE - O(h)
Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;
    if (val < root->data)
        root->left = deleteNode(root->left, val);
    else if (val > root->data)
        root->right = deleteNode(root->right, val);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ----------------------------------------------------
// INORDER - O(n)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ----------------------------------------------------
// MAIN
int main() {
    Node* root = NULL;
    vector<int> values = {50, 30, 20, 40, 70, 60, 80};

    // Measure Insert Time
    auto start = high_resolution_clock::now();
    for (int val : values)
        root = insert(root, val);
    auto end = high_resolution_clock::now();
    auto insert_time = duration_cast<microseconds>(end - start).count();

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Find Min
    start = high_resolution_clock::now();
    Node* minNode = findMin(root);
    end = high_resolution_clock::now();
    auto min_time = duration_cast<microseconds>(end - start).count();

    // Find Max
    start = high_resolution_clock::now();
    Node* maxNode = findMax(root);
    end = high_resolution_clock::now();
    auto max_time = duration_cast<microseconds>(end - start).count();

    // Successor
    int key = 50;
    start = high_resolution_clock::now();
    Node* succ = successor(root, key);
    end = high_resolution_clock::now();
    auto succ_time = duration_cast<microseconds>(end - start).count();

    // Predecessor
    start = high_resolution_clock::now();
    Node* pred = predecessor(root, key);
    end = high_resolution_clock::now();
    auto pred_time = duration_cast<microseconds>(end - start).count();

    // Insert new node
    start = high_resolution_clock::now();
    root = insert(root, 25);
    end = high_resolution_clock::now();
    auto single_insert_time = duration_cast<microseconds>(end - start).count();

    // Delete node
    start = high_resolution_clock::now();
    root = deleteNode(root, 70);
    end = high_resolution_clock::now();
    auto delete_time = duration_cast<microseconds>(end - start).count();

    // Display results
    
    
    cout << "Insert (all)      " << insert_time << " µs\n";
    cout << "Find Minimum      " << min_time << " µs\n";
    cout << "Find Maximum      " << max_time << " µs\n";
    cout << "Successor         " << succ_time << " µs\n";
    cout << "Predecessor       " << pred_time << " µs\n";
    cout << "Insert (single)   " << single_insert_time << " µs\n";
    cout << "Delete            " << delete_time << " µs\n";
    
    cout << "\nFinal Inorder Traversal after insertion & deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
