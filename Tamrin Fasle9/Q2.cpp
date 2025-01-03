#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void morrisInOrderTraversal(TreeNode* root) {
    TreeNode* current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == nullptr) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

TreeNode* createTree() {
    cout << "Enter the root node value (or -1 for no node): ";
    int rootValue;
    cin >> rootValue;

    if (rootValue == -1) return nullptr;

    TreeNode* root = new TreeNode(rootValue);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << " (or -1 for no node): ";
        int leftValue;
        cin >> leftValue;
        if (leftValue != -1) {
            current->left = new TreeNode(leftValue);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (or -1 for no node): ";
        int rightValue;
        cin >> rightValue;
        if (rightValue != -1) {
            current->right = new TreeNode(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    cout << "Create your binary tree:" << endl;
    TreeNode* root = createTree();

    cout << "In-Order Traversal of the tree: ";
    morrisInOrderTraversal(root);
    cout << endl;

    return 0;
}
