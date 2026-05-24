#include <iostream>
using namespace std;

class node {
public:
    int data;     // node ki value
    node* left;   // left pointer choti values k liye
    node* right;  // right pointer bari values k liye

    // constructor jo new node banaye ga
    node(int val) {
        data = val;
        left = null;
        right = null;
    }
};

// bst main naya node insert karne ka function
node* insert(node* root, int val) {
    // agar tree khali hy ya end agaya hy to naya node bana kar wapis bhej do
    if (root == null) {
        return new node(val);
    }

    // agar value current node sy choti hy to left side par jao
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // agar value current node sy bari hy to right side par jao
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    // data insert karne k baad root pointer return karo
    return root;
}

// in-order traversal jo bst ka data hamesha barhte hue order main dikhata hy
void printinorder(node* root) {
    // agar pointer khali hy to ruk jao
    if (root == null) {
        return;
    }

    // pehle left side par recursion chalao
    printinorder(root->left);
    
    // beech wali current value print karo
    cout << root->data << " ";
    
    // phir right side par recursion chalao
    printinorder(root->right);
}

int main() {
    node* root = null;

    // insertion function ko use kar k values insert kar rahay hain
    // bst property k mutabiq 50 center main hoga, choti values left par aur bari right par jayen gi
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // in-order chalane sy sara data sorted shakal main print hoga
    cout << "bst ka in-order traversal sorted order main: ";
    printinorder(root);
    cout << endl;

    return 0;
}