#include <iostream>
using namespace std;

// STRUCTURE OF TREE NODE
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// FUNCTION TO CREATE A NEW NODE
Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// FUNCTION TO INSERT NODE IN BST
Node* insertBST(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertBST(root->right, value);
    }
    else
    {
        cout << "DUPLICATE VALUE NOT ALLOWED" << endl;
    }

    return root;
}

// INORDER TRAVERSAL
void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// PREORDER TRAVERSAL
void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER TRAVERSAL
void postorder(Node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node* root = NULL;
    int choice, value;

    do
    {
        cout <<"BINARY SEARCH TREE MENU" << endl;
        cout << "1. INSERT NODE" << endl;
        cout << "2. INORDER TRAVERSAL" << endl;
        cout << "3. PREORDER TRAVERSAL" << endl;
        cout << "4. POSTORDER TRAVERSAL" << endl;
        cout << "5. EXIT" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "ENTER VALUE TO INSERT: ";
            cin >> value;
            root = insertBST(root, value);
            break;

        case 2:
            if (root == NULL)
                cout << "TREE IS EMPTY" << endl;
            else
            {
                cout << "INORDER TRAVERSAL: ";
                inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)
                cout << "TREE IS EMPTY" << endl;
            else
            {
                cout << "PREORDER TRAVERSAL: ";
                preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
                cout << "TREE IS EMPTY" << endl;
            else
            {
                cout << "POSTORDER TRAVERSAL: ";
                postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "EXITING PROGRAM..." << endl;
            break;

        default:
            cout << "INVALID CHOICE" << endl;
        }

    } while (choice != 5);

    return 0;
}
