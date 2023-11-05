// Make a tree using a C++
//         9
//      4         10
// 1       7   8        25
//

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
    Node(): left(nullptr), right(nullptr) {}
};

class BinarySearchTree 
{
public:
    BinarySearchTree(int value) : root(nullptr)
    {
        Node* temp = new Node(value);
        root = temp;
        parent = root;
        height=0;
    }
    void Insert(int value)
    {
        Node* newNode = new Node(value);
        parent = root;
        while(true)
        {
            if (value > parent->data)
            {
                if (parent->right==nullptr)
                {
                    parent->right = newNode;
                    break;
                }
                else
                {
                    current=parent->right;
                }            
            }
            else
            {
                if (parent->left==nullptr)
                {
                    parent->left = newNode;
                    break;
                }
                else
                {
                    current=parent->left;
                }
            }
            parent = current;
            DisplayParent();
        }
        DisplayParent();
    }
    int Lookup(int value)
    {
        return -999;
    }
    void DisplayParent()
    {
        int left_data; 
        if (parent->left!=nullptr)
        {
            left_data = parent->left->data;
        }
        int right_data;
        if (parent->right!=nullptr)
        {
            right_data = parent->right->data;
        }
        std::cout << "Parent: " << parent->data << " Parent(Left): " << left_data << " Parent(Right): " << right_data << std::endl;
    }
    void DisplayTranverse()
    {
        // Create tree that starts from the top and uses endl to create levels
        // Uses tabs to space out the siblings
        Node* current = new Node();
        parent = root;
        int tranverseStep = -1;
        while (height > tranverseStep)
        {
            current=parent->left;
            tranverseStep++;
            parent = current;
        }
    }
    // Print the BST using in-order traversal.
    void Print() {
        inorderRec(root);
    }
private:
    Node* root;
    Node* parent;
    Node* current;
    int height;

    // Helper function for in-order traversal.
    void inorderRec(Node* root) 
    {
        if (root != nullptr) 
        {
            inorderRec(root->left);
            std::cout << root->data << " ";
            inorderRec(root->right);
        }
    }
};

int main() 
{
    BinarySearchTree tree(6);
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(8);
    tree.Insert(2);
    tree.Insert(30);
    tree.Print();
    return 0;
}