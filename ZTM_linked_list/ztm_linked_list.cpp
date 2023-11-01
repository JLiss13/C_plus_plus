// Make a linked_list using a C++
//

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) , tail(nullptr)
    {
        length=1;
    }

    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
        } 
        else
        {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
            tail = newNode;
            length++;
        }
    }

    void prepend(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertion(int index, int value) // O(n)
    {
        // First while loop through the node list and adjust the pointers at the index section
        Node* current  = head;
        Node* insertionNode = new Node(value);
        int index_cnt=0;
        while(current)
        {
            if (index == index_cnt)
            {
                insertionNode-> next = current; // Current node is the insertionNode
                prev_node->next = insertionNode; // Set the previous node next pointer to the insertionNode
            }
            else
            {
                prev_node = current; // Save the previous node 
                current = current->next;
            }

            index_cnt++;
            
        }
    }

    Node* lookup(int index) // O(n)
    {
        if (!head)
        {
            return nullptr;
        }

        Node* current  = head;
        int index_cnt=0;
        while(current)
        {
            if (index == index_cnt)
            {
                break;
            }
            else
            {
                current = current->next;
            }
            index_cnt++;
        }

        return current;
    }

    void deletion(int index) //O(n)
    {
        // First while loop through the node list and adjust the pointers at the index section
        Node* current  = head;
        Node* deletionNode = nullptr;
        int index_cnt=0;
        while(current)
        {
            if (index == index_cnt)
            {
                prev_node->next = current->next; // Set the previous node next pointer to the insertionNode
            }
            else
            {
                prev_node = current; // Save the previous node 
                current = current->next;
            }
            index_cnt++;
        }
    }

    void display() 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

private:
    Node* head;
    Node* prev_node;
    Node* tail;
    int length;
};

int main() 
{
    LinkedList myList;

    myList.append(1);
    myList.append(99);
    myList.append(300);
    myList.prepend(100);
    myList.insertion(2,22);
    myList.display();
    
    myList.deletion(3);
    myList.display();

    return 0;
}