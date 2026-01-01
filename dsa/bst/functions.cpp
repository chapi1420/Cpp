#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int findMin(Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int findHeight(Node* root) {
    if (root == NULL)
        return -1;   

    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);

    return 1 + (leftH > rightH ? leftH : rightH);
}

// In-order traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(root, 100) ? "Found" : "Not Found") << endl;

    cout << "Minimum value: " << findMin(root) << endl;
    cout << "Maximum value: " << findMax(root) << endl;
    cout << "Height of tree: " << findHeight(root) << endl;

    return 0;
}
