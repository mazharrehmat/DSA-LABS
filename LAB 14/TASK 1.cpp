#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* insertNode(Node* current, int value)
    {
        if (current == NULL)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insertNode(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insertNode(current->right, value);
        }

        return current;
    }

    Node* findMin(Node* current)
    {
        while (current->left != NULL)
        {
            current = current->left;
        }

        return current;
    }

    Node* deleteNode(Node* current, int value)
    {
        if (current == NULL)
        {
            return NULL;
        }

        if (value < current->data)
        {
            current->left = deleteNode(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = deleteNode(current->right, value);
        }
        else
        {
            if (current->left == NULL)
            {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == NULL)
            {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteNode(current->right, temp->data);
        }

        return current;
    }

    void inorderTraversal(Node* current)
    {
        if (current != NULL)
        {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
    }

    void displayInorder()
    {
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "After Insertion: ";
    tree.displayInorder();

    tree.remove(70);

    cout << "After Deletion: ";
    tree.displayInorder();

    return 0;
}