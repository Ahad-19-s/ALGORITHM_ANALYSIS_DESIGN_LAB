#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        color = RED; // new nodes are always RED
    }
};

class RedBlackTree {
private:
    Node* root;

    // Utility function for left rotation
    void rotateLeft(Node* &root, Node* &x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != NULL)
            y->left->parent = x;

        y->parent = x->parent;

        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // Utility function for right rotation
    void rotateRight(Node* &root, Node* &y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != NULL)
            x->right->parent = y;

        x->parent = y->parent;

        if (y->parent == NULL)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    // Fix violation after insertion
    void fixInsert(Node* &root, Node* &pt) {
        Node* parent = NULL;
        Node* grandparent = NULL;

        while ((pt != root) && (pt->color == RED) &&
               (pt->parent->color == RED)) {

            parent = pt->parent;
            grandparent = parent->parent;

            // Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED
                if (uncle != NULL && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    // Case 2: pt is right child
                    if (pt == parent->right) {
                        rotateLeft(root, parent);
                        pt = parent;
                        parent = pt->parent;
                    }
                    // Case 3: pt is left child
                    rotateRight(root, grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            } else { // Parent is right child of grandparent
                Node* uncle = grandparent->left;

                if (uncle != NULL && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    pt = grandparent;
                } else {
                    if (pt == parent->left) {
                        rotateRight(root, parent);
                        pt = parent;
                        parent = pt->parent;
                    }

                    rotateLeft(root, grandparent);
                    swap(parent->color, grandparent->color);
                    pt = parent;
                }
            }
        }
        root->color = BLACK;
    }

    // Inorder traversal
    void inorderHelper(Node* root) {
        if (root == NULL)
            return;

        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

    // Search in RBT
    Node* searchHelper(Node* root, int key) {
        if (root == NULL || root->data == key)
            return root;

        if (key < root->data)
            return searchHelper(root->left, key);

        return searchHelper(root->right, key);
    }

    // Find minimum node
    Node* minimum(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    // Replace nodes during deletion
    void transplant(Node* &root, Node* u, Node* v) {
        if (u->parent == NULL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;

        if (v != NULL)
            v->parent = u->parent;
    }

    // Fix deletion
    void fixDelete(Node* &root, Node* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node* w = x->parent->right;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(root, x->parent);
                    w = x->parent->right;
                }

                if ((w->left == NULL ||
                     w->left->color == BLACK) &&
                    (w->right == NULL ||
                     w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right == NULL ||
                        w->right->color == BLACK) {
                        if (w->left != NULL)
                            w->left->color = BLACK;

                        w->color = RED;
                        rotateRight(root, w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->right != NULL)
                        w->right->color = BLACK;

                    rotateLeft(root, x->parent);
                    x = root;
                }
            } else {
                Node* w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(root, x->parent);
                    w = x->parent->left;
                }

                if ((w->left == NULL ||
                     w->left->color == BLACK) &&
                    (w->right == NULL ||
                     w->right->color == BLACK)) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left == NULL ||
                        w->left->color == BLACK) {
                        if (w->right != NULL)
                            w->right->color = BLACK;

                        w->color = RED;
                        rotateLeft(root, w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    if (w->left != NULL)
                        w->left->color = BLACK;

                    rotateRight(root, x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    RedBlackTree() { root = NULL; }

    // Insert
    void insert(int data) {
        Node* pt = new Node(data);

        Node* parent = NULL;
        Node* temp = root;

        while (temp != NULL) {
            parent = temp;
            if (pt->data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        pt->parent = parent;

        if (parent == NULL)
            root = pt;
        else if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;

        fixInsert(root, pt);
    }

    // Delete
    void deleteKey(int key) {
        Node* z = searchHelper(root, key);
        if (z == NULL) {
            cout << "Key not found!\n";
            return;
        }

        Node* y = z;
        Node* x;
        bool yOriginalColor = y->color;

        if (z->left == NULL) {
            x = z->right;
            transplant(root, z, z->right);
        } else if (z->right == NULL) {
            x = z->left;
            transplant(root, z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z) {
                if (x != NULL)
                    x->parent = y;
            } else {
                transplant(root, y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(root, z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if (yOriginalColor == BLACK && x != NULL)
            fixDelete(root, x);
    }

    // Search
    bool search(int key) {
        return searchHelper(root, key) != NULL;
    }

    // Print inorder
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};

// ===================== MAIN ==========================

int main() {
    RedBlackTree tree;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Print (Inorder)\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
        }
        else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteKey(value);
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) cout << "Found!\n";
            else cout << "Not Found!\n";
        }
        else if (choice == 4) {
            cout << "Inorder: ";
            tree.inorder();
        }
        else break;
    }

    return 0;
}
