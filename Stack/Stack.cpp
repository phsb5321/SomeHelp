#include "iostream"

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        this->size = 0;
        top = nullptr;
    }

    void push(int value)
    {
        top = new Node(value, top);
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }
        else
        {
            Node helper_node = *top;
            top = top->next;
            size--;
            return helper_node.value;
        }
    }

    int length()
    {
        return size;
    }
};

int main(int argc, char const *argv[])
{
    Stack storage;
    storage.push(1);
    storage.push(2);
    storage.push(3);
    cout << storage.pop() << endl;
    cout << storage.pop() << endl;
    cout << storage.pop() << endl;
    cout << storage.pop() << endl;
    return 0;
}
