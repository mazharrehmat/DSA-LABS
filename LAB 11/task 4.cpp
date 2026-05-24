#include <iostream>
using namespace std;

class node {
public:
    int data;     // node main data save krnay k liye variable
    node* left;   // left side ka link
    node* right;  // right side ka link

    // new node set krnay k liye constructor
    node(int val) {
        data = val;
        left = null;
        right = null;
    }
};

// tree main nodes dalnay wala function
node* insert(node* root, int val) {
    // agar tree khali hy to pehla node bana do
    if (root == null) {
        return new node(val);
    }

    // value choti ho to left track pr pheko
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // value bari ho to right side pr le jao
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

// recursive tariqay sy sab sy choti value nikalnay ka function
int findmin(node* root) {
    // agar tree poora khali hy to zero bhej do ya error handle kro
    if (root == null) {
        return -1; 
    }

    // agar left side pr mazeed koi node nahi hy to yahi sab sy chota hy
    if (root->left == null) {
        return root->data;
    }

    // warna mazeed left par recursion chalatay jao
    return findmin(root->left);
}

// recursive tariqay sy sab sy bari value dhoondnay ka function
int findmax(node* root) {
    // khali tree ki surat main -1 return krwa rahay hain
    if (root == null) {
        return -1;
    }

    // agar right side pr koi node nahi bacha to yahi sab sy bara hy
    if (root->right == null) {
        return root->data;
    }

    // warna aakhri right node tak recursion ko bhejte jao
    return findmax(root->right);
}

int main() {
    node* root = null;

    // tree main random values insert kr rahay hain
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 45);
    insert(root, 70);
    insert(root, 65);
    insert(root, 90);

    // dono recursive functions ko call kr k output check krtay hain
    cout << "--- bst ki minimum aur maximum values ---" << endl;

    int minval = findmin(root);
    if (minval != -1) {
        cout << "tree ki sab sy choti value hy: " << minval << endl;
    }

    int maxval = findmax(root);
    if (maxval != -1) {
        cout << "tree ki sab sy bari value hy: " << maxval << endl;
    }

    return 0;
}