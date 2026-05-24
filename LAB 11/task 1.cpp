#include <iostream>
using namespace std;

class node {
public:
    int data;     // Node ki value
    node* left;   // Left side  ka pointer
    node* right;  // Right sode ka pointer

    // Jab bhi new Node banayein gay, yeh automatic chala jaye ga
    node(int val) {
        data = val;
        left = null;  
        right = null; 
    }
};

// PRE-ORDER TRAVERSAL (
void printpreorder(node* root) {
    // Agar agay koi node nahi hai to yahin sy wapis chaly jao
    if (root == null) {
        return;
    }

    // Pehle root print karo
    cout << root->data << " ";
    
    //  left side ko check karo
    printpreorder(root->left);
    
    //  right side ko check karo
    printpreorder(root->right);
}

// 2. IN-ORDER TRAVERSAL 
void printinorder(node* root) {
    //  check karna k tree khatam to nahi ho gaya
    if (root == null) {
        return;
    }

    // Pehle left side par jay ga github jab tak end nahi aata
    printinorder(root->left);
    
    // Wapis aatay huay beech walay node ko print karo
    cout << root->data << " ";
    
    //right side par recursion chaly gi
    printinorder(root->right);
}

// 3. POST-ORDER TRAVERSAL 
void printpostorder(node* root) {
    if (root == null) {
        return;
    }

    //left subtree ko dekho
    printpostorder(root->left);
    
    // right subtree ko dekha
    printpostorder(root->right);
    
    // Sab sy aakhri main root ko print karo
    cout << root->data << " ";
}

int main() {
    

    // Sab sy pehla main node banaya class ka object use kar k
    node* root = new node(10);
    
    // Root ke neechay do mazeed nodes connect kiye
    root->left = new node(20);
    root->right = new node(30);
    
    // Ab 20 walay node ke agay do aur nodes laga diye
    root->left->left = new node(40);
    root->left->right = new node(50);
    
    // Hamara 5 nodes wala tree ready ho gaya hai!

    // Ab teeno functions ko baari baari check kartay hain
    cout << "    tree traversals    " << endl;

    cout << "pre-order traversal:  ";
    printpreorder(root);
    cout << endl;

    cout << "in-order traversal:   ";
    printinorder(root);
    cout << endl;

    cout << "post-order traversal: ";
    printpostorder(root);
    cout << endl;

    return 0;
}