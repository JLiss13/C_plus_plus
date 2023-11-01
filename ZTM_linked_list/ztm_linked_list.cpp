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
    Node* tail;
    int length;
};

int main() 
{
    LinkedList myList;

    myList.append(1);
    myList.append(99);
    myList.append(3);
    myList.prepend(100);
    
    myList.display();

    return 0;
}