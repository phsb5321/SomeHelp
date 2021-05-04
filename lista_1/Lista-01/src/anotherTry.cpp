#include <cstdio>
#include <iostream>

#include <fstream>

using namespace std;

template <typename T>
class Link
{
public:
    T element;  // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const T &elemval, Link *nextval = nullptr)
    {
        element = elemval;
        next = nextval;
    }
};

template <typename E>
class Stack
{

public:
    Link<E> *top;
    int size;

    Stack()
    {
        top = nullptr;
        size = 0;
    }

    void push(const E &it)
    {
        top = new Link<E>(it, top);
        size++;
    }

    E pop()
    {
        E it = top->element;
        Link<E> *ltemp = top->next;
        delete top;
        top = ltemp;
        size--;
        return it;
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
            return false;
    }
};

int main(int argc, char const *argv[])
{
    ofstream myfile;
    myfile.open("CPP.txt");

    int count, i;

    string line;
    Stack<char> storage;

    scanf("%d\n", &count);

    while (count--)
    {

        while (storage.size > 0)
        {
            storage.pop();
        }

        getline(cin, line);

        for (i = 0; i < line.size(); i++)
        {

            if (line[i] == '(' || line[i] == '[')
            {
                storage.push(line[i]);
            }
            else if (storage.empty())
            {
                storage.push('E');
                break;
            }
            else if (line[i] == ')' && storage.top->element == '(')
            {
                storage.pop();
            }
            else if (line[i] == ']' && storage.top->element == '[')
            {
                storage.pop();
            }
            else
            {
                storage.push('E');
                break;
            }
        }

        if (storage.size == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
