#include <bits/stdc++.h>

using namespace std;
class elements
{
public:
    int value;
    int index;
};

bool comaranxion(elements left, elements right)
{
    if (left.value < right.value)
        return true;
    else if (left.value == right.value)
        return left.index > right.index;
    else
        return false;
}

void merge(elements a[], int l, int r)
{

    elements temp[r];
    for (int i = l; i <= r; i++)
    {
        temp[i] = a[i];
    }
    int m = (l + r) / 2;
    int i1 = l;
    int i2 = m + 1;
    for (int curr = l; curr <= r; curr++)
    {
        if (i1 == m + 1)
        {
            a[curr] = temp[i2];
            i2++;
        }
        else if (i2 > r)
        {
            a[curr] = temp[i1];
            i1++;
        }
        else if (comaranxion(temp[i1], temp[i2]))
        {
            a[curr] = temp[i1];
            i1++;
        }

        else
        {
            a[curr] = temp[i2];
            i2++;
        }
    }
}

void mergesort(elements a[], int l, int r)
{

    if (l < r)
    {
        int m = 0;
        m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, r);
    }
}

int main()
{
    int size = 0;

    scanf("%d", &size);
    elements arr[size];
    for (int i = 0; i < size; i++)
    {
        int e = 0;
        scanf("%d", &arr[i].value);
        arr[i].index = i + 1;
    }
    mergesort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i].index);
    }
}