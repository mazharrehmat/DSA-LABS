#include <iostream>
using namespace std;

class node {
public:
    int data;     // dabba main integer value rakhnay k liye
    node* left;   // left side ka address store krnay wala pointer
    node* right;  // right side ka address store krnay wala pointer

    // constructor jo har naye node ko memory main jagah dega
    node(int val) {
        data = val;
        left = null;
        right = null;
    }
};

// tree main bst k rules k mutabiq entry krnay wala function
node* insert(node* root, int val) {
    // agar koi khaali spot milay to wahan naya node fix krdo
    if (root == null) {
        return new node(val);
    }

    // value choti hy to left side pr tracking shuru krdo
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // value bari hy to right track pr nikal jao
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// bst main recursive search chalane wala function
bool search(node* root, int key) {
    // end tak pohonch gaye aur kuch nahi mila to false bhejdo
    if (root == null) {
        return