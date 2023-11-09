// Make a tree using a C++
//         9
//      4         10
// 1       7   8        25
//

#include <iostream>
#include <cmath>
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
        Node* newNode = new Node(value);
        parent = root;
        int output = -999;
        while(parent->right || parent->left)
        {
            if (value > parent->data)
            {
                if (parent->right->data == value)
                {
                    output = parent->right->data;
                    std::cout << "Find the value:" << output<<std::endl;
                    break;
                }
                else
                {
                    current=parent->right;
                }            
            }
            else
            {
                if (parent->left->data == value)
                {
                    output = parent->left->data;
                    std::cout << "Find the value: " << output<<std::endl;
                    break;
                }
                else
                {
                    current=parent->left;
                }
            }
            parent = current;
        }
        if (output==-999)
        {
            std::cout << "Could not find value:" << value <<std::endl;
        }
        return output;
    }
    void Remove(int value)
    {
        // To hold onto the parent node logic the next highest value (meaning the value to the right) gets put in place of the removed node

        // Have three nodes to keep track of: prevNode, newReplacementNode and take the next highest value and replace the removed node with the next highest value node. Move associated pointers along with it
        Node* removedNode = new Node();
        Node* prevNode = new Node();
        Node* newNode = new Node();
        Node* newReplacementNode = new Node();
        parent = root;
        int output = -999;

        // First find the node to be removed
        while(!removedNode->right && !removedNode->left)
        {
            if (value > parent->data)
            {
                current=parent->right;        
            }
            else if (value < parent->data)
            {
                current=parent->left;
            }
            else if ((value == parent->data))
            {
                removedNode = parent;
            }
            parent = current;
        }

        // Setup the replacement node
        int prevDist = std::abs(current->data - removedNode->data);
        while(!parent->right)
        {
            current=parent->right;
            int newDist = std::abs(current->data - removedNode->data);
            // Find the closest to the value in the right side of tree to the parent
            if (newDist < prevDist) 
            {
                newReplacementNode = current;
            }
            parent = current;
        }

        // Now reassign the pointers [TODO]
        // 3 Scenarios
        // 1) parent->right == nullptr
        // 2) parent->right
        // 3) parent->right == nullptr && parent->left
        // where parent == newReplacementnode
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
    tree.Lookup(5);
    tree.Lookup(1222);
    return 0;
}