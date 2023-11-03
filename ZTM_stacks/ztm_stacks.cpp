// Make a queue from stacks using C++
//

#include <iostream>
#include <stack>
class QueuesUsingStacks
{
    public:
        void ClearQueue()
        {
            while(!queueStack.empty())
            {
                queueStack.pop();
            }
        }
        int Dequeue()
        {
            std::stack<int> dequeueStack;
            // Removes from the front of the queue
            if (queueStack.size() ==1 &&  
                !queueStack.empty())
            {
                dequeueStack = queueStack;
                int frontElement = dequeueStack.top();
                dequeueStack.pop();
                return frontElement;
            }
            else
            {
                // walk through and remove the last plate on the stack
                // aka front element of the queue
                // then push all the other elements forward in the queue
                int frontElement = -999;
                while(!queueStack.empty())
                {
                    dequeueStack.push(queueStack.top());
                    if (queueStack.size()==1)
                    {
                        int frontElement = dequeueStack.top();
                        dequeueStack.pop();
                        Display(dequeueStack);
                    }
                    queueStack.pop();
                }

                // Now reassemnble the queue from the dequeueStack
                while(!dequeueStack.empty())
                {
                    queueStack.push(dequeueStack.top());
                    dequeueStack.pop();
                }
                return frontElement;
            }
        }
        void Enqueue(int value)
        {
            // Adds to the back of the queue
            queueStack.push(value);
        }
        int Peek()
        {
            // Looks at the front of the queue
            return queueStack.top();
        }
        int Lookup(int index)
        {
            // Tranverse through the queue to find the item in question
            if (queueStack.size() ==1 && 
                !queueStack.empty())
            {
                return queueStack.top();
            }
            else
            {
                std::stack<int> lookupStack;
                lookupStack = queueStack;
                for(int i=0;i<queueStack.size();i++)
                {
                    lookupStack.pop();
                    if(i==index)
                    {
                        return lookupStack.top();
                    }
                }
                std::cout<<"index out of range of the stack"<<std::endl;
                return -1;
            }
        }

        bool IsEmpty()
        {
            if(queueStack.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void Display()
        {
            std::stack<int>  displayStack;
            displayStack = queueStack;
            std::cout<<"back of the line--";
            for (int i=0;i<queueStack.size();i++)
            {
                std::cout << displayStack.top()<< "--";
                displayStack.pop();
            }
            std::cout<<"front of line"<<std::endl;
        }
        void Display(std::stack<int>  tempStack)
        {
            std::stack<int>  displayStack;
            displayStack = tempStack;
            std::cout<<"back of the line--";
            for (int i=0;i<tempStack.size();i++)
            {
                std::cout << displayStack.top()<< "--";
                displayStack.pop();
            }
            std::cout<<"front of line"<<std::endl;
        }
    private:
        std::stack<int> queueStack;
};


int main() 
{
    // Let's create the queue
    QueuesUsingStacks* stack = new QueuesUsingStacks();
    stack->Enqueue(1);
    stack->Enqueue(2);
    stack->Enqueue(3);
    stack->Enqueue(4);
    stack->Display();
    stack->Dequeue();
    stack->Display();
    return 0;
}