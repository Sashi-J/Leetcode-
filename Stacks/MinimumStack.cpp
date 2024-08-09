#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> mStack;
    stack<int> mins;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        // Pushing val
        mStack.push(val);
        // Checking whether there is a new minimum number
        val = min(val, mins.empty() ? val : mins.top());
        // Pushing number to stack so we have two stacks in order to know which minimum number whether there are duplicates or not.
        mins.push(val);
    }

    void pop()
    {
        // We can pop both since we are always adding a minimum which one can think of as a dictionary; So for each element within the mStack there is a correlated element with a minimum (doesn't matter if the minimum is the same number)
        mStack.pop();
        mins.pop();
    }

    int top()
    {
        return mStack.top();
    }

    int getMin()
    {
        // Top element will always be the minimum
        return mins.top();
    }
};
/**
This solution explores the concept of using a linked list to solve it instead of a stack format
**/
class customStack
{
private:
    struct node
    {
        int value;
        int min;
        node *next;
        node *back;
    };
    node *tail;
    node *front;

public:
    customStack()
    {
        front = tail = nullptr;
    };
    void push(int val)
    {
        // New Node
        node *newNode = new node;
        if (front && tail)
        {
            // New node and reassigning tail
            tail->next = newNode;
            newNode->back = tail;
            newNode->min = min(val, tail->min);
            tail = newNode;
        }
        else
        {
            newNode->value = val;
            newNode->min = val;
            newNode->next = nullptr;
            newNode->back = nullptr;
            tail = front = newNode;
        }
    }
    void pop()
    {
        if (front == nullptr)
        {
        }
        else if (front == tail)
        {
            delete front;
            front = nullptr;
            tail = nullptr;
        }
        else
        {
            node *temp = tail;
            tail = tail->back;
            tail->next = nullptr;
            delete temp;
        }
    }
    int top()
    {
        if (tail)
        {
            return tail->value;
        }
    }
    int getMin()
    {
        return tail->min;
    }
};
int main()
{
    // Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

    // Output: [null,null,null,null,0,null,2,1]
    customStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    int min = minStack.getMin(); // return 0
    cout << "min: " << min << endl;
    minStack.pop();
    minStack.push(3);
    int top = minStack.top(); // return 3
    minStack.push(-1);
    min = minStack.getMin();
    cout << "MINIMUM VALUE:" << min << endl;
    cout << "TOP VALUE: " << top;
}