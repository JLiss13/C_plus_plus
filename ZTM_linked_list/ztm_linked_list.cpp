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
    LinkedList() : head(nullptr) {}

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
};

int main() 
{
    LinkedList myList;

    myList.append(1);
    myList.append(99);
    myList.append(3);

    myList.display();

    return 0;
}