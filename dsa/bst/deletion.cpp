#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create node
Node* createNode(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert
Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

////////////////////////////////////////////////////
//  DELETION BY COPYING
////////////////////////////////////////////////////
Node* deleteByCopying(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteByCopying(root->left, key);

    else if (key > root->data)
        root->right = deleteByCopying(root->right, key);

    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;

            root->data = temp->data;
            root->left = deleteByCopying(root->left, temp->data);
        }
    }
    return root;
}

////////////////////////////////////////////////////
// DELETION BY MERGING
////////////////////////////////////////////////////
Node* deleteByMerging(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteByMerging(root->left, key);

    else if (key > root->data)
        root->right = deleteByMerging(root->right, key);

    else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            // Merge subtrees
            Node* temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;

            temp->right = root->right;
            Node* newRoot = root->left;
            delete root;
            return newRoot;
        }
    }
    return root;
}

////////////////////////////////////////////////////
// MAIN FUNCTION
////////////////////////////////////////////////////
int main() {
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    root = deleteByCopying(root, 50);
    cout << "After Deletion by Copying (50): ";
    inorder(root);
    cout << endl;

    root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    root = deleteByMerging(root, 50);
    cout << "After Deletion by Merging (50): ";
    inorder(root);
    cout << endl;

    return 0;
}
