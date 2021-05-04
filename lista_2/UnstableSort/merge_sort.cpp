#include <cstdio>
#include <iostream>

using namespace std;

// *(int(*)[6])temp

class Component
{
public:
    int index;
    int value;
};

bool comp(Component a, Component b)
{
    if (a.value < b.value)
        return true;
    else if (a.value == b.value) 
        return a.index > b.index;
    else
        return false;
}

template <typename E>
void mergesort(E A[], E temp[], int left, int right)
{
    if (left == right)
        return; // List of one element
    int mid = (left + right) / 2;
    mergesort<E>(A, temp, left, mid);
    mergesort<E>(A, temp, mid + 1, right);
    for (int i = left; i <= right; i++) // Copy subarray to temp
        temp[i] = A[i];
    // Do the merge operation back to A
    int i1 = left;
    int i2 = mid + 1;
    for (int curr = left; curr <= right; curr++)
    {
        if (i1 == mid + 1) // Left sublist exhausted
            A[curr] = temp[i2++];
        else if (i2 > right) // Right sublist exhausted
            A[curr] = temp[i1++];
        else if (comp(temp[i1], temp[i2]))
            A[curr] = temp[i1++];
        else
            A[curr] = temp[i2++];
    }
}
int main(int argc, char const *argv[])
{
    int number_of_inputs = 0;
    scanf("%d", &number_of_inputs);

    Component array[number_of_inputs];
    Component temporary[number_of_inputs];

    for (int a = 0; a < number_of_inputs; a++)
    {
        scanf(" %d", &array[a].value);
        array[a].index = a + 1;
    }

    mergesort<Component>(array, temporary, 0, number_of_inputs);

    for (int b = 0; b < number_of_inputs; b++)
    {
        cout << temporary[b].index << " ";
    }

    return 0;
}