#include <iostream>
using namespace std;

class node {
public:
    int data;     // is dabba main data save hoga
    node* left;   // choti value ko left py bhejnay k liye pointer
    node* right;  // bari value ko right py rakhnay k liye pointer

    // constructor jo new node ko initialize kray ga
    node(int val) {
        data = val;
        left = null;
        right = null;
    }
};

// naye numbers ko tree main set krnay wala function
node* insert(node* root, int val) {
    // jab koi jagah khali milay gi to wahan new node fit kr do
    if (root == null) {
        return new node(val);
    }

    // agar incoming value choti hy to left side main push krdo
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // value bari honay ki surat main right side main pheko
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    // recursion k baad updated tree ka pointer wapis krdo
    return root;
}

// recursive search jo bst k rules py chalti hy
bool search(node* root, int key) {
    // check kro agar end tak kuch nahi mila to false return krdo
    if (root == null) {
        return false;
    }

    // agar user wala number mil jaye to kahani khatam aur true bhej do
    if (root->data == key) {
        return true;
    }

    // dhoondnay wali value agar short hy to left track pr nikal jao
    if (key < root->data) {
        return search(root->left, key);
    }

    // warna simple si baat hy k right side pr hi check krna paray ga
    return search(root->right, key);
}

// data ko sequence wise chalanay k liye in-order function
void printinorder(node* root) {
    // base case lagaya hy taake memory crash na ho
    if (root == null) {
        return;
    }

    // sab sy pehle left subtree ko trace kro
    printinorder(root->left);
    
    // beech main kharay node ka data screen pr show kro
    cout << root->data << " ";
    
    // end main right side walay hissay ko print kro
    printinorder(root->right);
}

int main() {
    node* root = null;

    // tree main manual values bhej kr bst khara kr rahay hain
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // check krnay k liye output dikhatay hain
    cout << "bst ka data sorted order main: ";
    printinorder(root);
    cout << endl << endl;

    // user sy dhoondnay k liye value mangwao
    int searchvalue;
    cout << "dhoondnay k liye koi value enter karo: ";
    cin >> searchvalue;

    // final result check kr k output print kro
    if (search(root, searchvalue)) {
        cout << "value mil gayi hy tree main" << endl;
    } else {
        cout << "value nahi mili tree main" << endl;
    }

    return 0;
}