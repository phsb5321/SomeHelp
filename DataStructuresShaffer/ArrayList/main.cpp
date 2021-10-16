#include <bits/stdc++.h>

template <typename E> // Array-based list implementation
class List
{
public:
    int maxSize;  // Maximum size of list
    int listSize; // Number of list items now
    int curr;     // Position of current element
    E *listArray; // Array holding list elements

    List(int size = 100001)
    { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    // Insert "it" at current position
    void insert(const E &it)
    {
        if (!(listSize < maxSize))
        {
            throw std::invalid_argument("List capacity exceeded");
        };
        for (int i = listSize; i > curr; i--) // Shift elements up
            listArray[i] = listArray[i - 1];  // to make room
        listArray[curr] = it;
        listSize++; // Increment list size
    }

    void append(const E &it)
    { // Append "it"
        if (!(listSize < maxSize))
        {
            throw std::invalid_argument("List capacity exceeded");
        };
        listArray[listSize++] = it;
    }

    // Remove and return the current element.
    E remove()
    {
        if ((curr >= 0) && (curr < listSize))
        {
            throw std::invalid_argument("No element");
        };
        E it = listArray[curr];                   // Copy the element
        for (int i = curr; i < listSize - 1; i++) // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--; // Decrement size
        return it;
    }

    void moveToStart() { curr = 0; }      // Reset position
    void moveToEnd() { curr = listSize; } // Set at end
    void prev()
    {
        if (curr != 0)
            curr--;
    } // Back up
    void next()
    {
        if (curr < listSize)
            curr++;
    } // Next
    // Return list size
    int length() const { return listSize; }

    // Return current position
    int currPos() const { return curr; }

    // Set current list position to "pos"
    void moveToPos(int pos)
    {
        if (!((pos >= 0) && (pos <= listSize)))
        {
            throw std::invalid_argument("Pos out of range");
        };
        curr = pos;
    }

    const E &getValue() const
    { // Return current element
        if (!((curr >= 0) && (curr < listSize)))
        {
            throw std::invalid_argument("No current element");
        };
        return listArray[curr];
    }
};