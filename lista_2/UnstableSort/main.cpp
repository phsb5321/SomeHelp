#include <cstdio>
#include <iostream>

using namespace std;

class Component
{
public:
    int index;
    int value;
};

bool comp(Component left, Component right)
{
    if (left.value < right.value)
        return true;
    else if (left.value == right.value)
        return left.index > right.index;
    else
        return false;
}

void merge(Component Arr[], int left, int right)
{

    Component temp[right];
    for (int i = left; i <= right; i++)
    {
        temp[i] = Arr[i];
    }
    int middle = (left + right) / 2;
    int left_index = left;
    int right_index = middle + 1;
    for (int curr = left; curr <= right; curr++)
    {
        if (left_index == middle + 1)
        { // Left sublist exhausted
            Arr[curr] = temp[right_index];
            right_index++;
        }
        else if (right_index > right)
        { // Right sublist exhausted
            Arr[curr] = temp[left_index];
            left_index++;
        }
        else if (comp(temp[left_index], temp[right_index]))
        {
            Arr[curr] = temp[left_index];
            left_index++;
        }
        else
        {
            Arr[curr] = temp[right_index];
            right_index++;
        }
    }
}

void mergesort(Component Arr[], int left, int right)
{
    if (left < right)
    {
        int middle = 0;
        middle = (left + right) / 2;
        mergesort(Arr, left, middle);
        mergesort(Arr, middle + 1, right);
        merge(Arr, left, right);
    }
}

int main(int argc, char const *argv[])
{
    int number_of_elements;
    cin >> number_of_elements;
    Component list_of_elements[number_of_elements];

    for (int i = 0; i < number_of_elements; i++)
    {
        cin >> list_of_elements[i].value;
        list_of_elements[i].index = i + 1;
    }

    mergesort(list_of_elements, 0, number_of_elements);

    for (int i = 0; i < number_of_elements; i++)
        cout << list_of_elements[i].index << " ";
    return 0;
}
