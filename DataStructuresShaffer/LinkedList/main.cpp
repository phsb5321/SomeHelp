#include <bits/stdc++.h>

// Singly linked list node
template <typename E>
class Link
{
public:
    E element;  // Value for this node
    Link *next; // Pointer to next node in list
                // Constructors
    Link(const E &elemval, Link *nextval = nullptr)
    {
        element = elemval;
        next = nextval;
    }

    Link(Link *nextval = nullptr) { next = nextval; }
};

// Linked list implementation
template <typename E>
class List
{
private:
    Link<E> *head; // Pointer to list header
    Link<E> *tail; // Pointer to last element
    Link<E> *curr; // Access to current element
    int cnt;       // Size of list
    void init()
    { // Intialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    void removeall()
    { // Return link nodes to free store
        while (head != nullptr)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    List(int size = 100001) { init(); } // Constructor

    void print() const; // Print list contents
    void clear()
    {
        removeall();
        init();
    } // Clear list
    // Insert "it" at current position
    void insert(const E &it)
    {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr)
            tail = curr->next; // New tail
        cnt++;
    }

    void append(const E &it)
    { // Append "it" to list
        tail = tail->next = new Link<E>(it, nullptr);
        cnt++;
    }

    // Remove and return current element
    E remove()
    {
        Assert(curr->next != nullptr, "No element");
        E it = curr->next->element;  // Remember value
        Link<E> *ltemp = curr->next; // Remember link node
        if (tail == curr->next)
            tail = curr;               // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement the count
        return it;
    }

    void moveToStart() // Place curr at list start
    {
        curr = head;
    }

    void moveToEnd() // Place curr at list end
    {
        curr = tail;
    }

    // Move curr one step left; no change if already at front
    void prev()
    {
        if (curr == head)
            return; // No previous element
        Link<E> *temp = head;
        // March down list until we find the previous element
        while (temp->next != curr)
            temp = temp->next;
        curr = temp;
    }

    // Move curr one step right; no change if already at end
    void next()
    {
        if (curr != tail)
            curr = curr->next;
    }

    int length() const { return cnt; } // Return length
    // Return the position of the current element
    int currPos() const
    {
        Link<E> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
            temp = temp->next;
        return i;
    }

    // Move down list to "pos" position
    void moveToPos(int pos)
    {
        if (!((pos >= 0) && (pos <= cnt)))
        {
            throw std::invalid_argument("Position out of range");
        };
        curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
    }

    const E &getValue() const
    { // Return current element
        if (!(curr->next != nullptr))
        {
            throw std::invalid_argument("No value");
        };
        return curr->next->element;
    }
};