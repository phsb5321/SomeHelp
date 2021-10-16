#include <bits/stdc++.h>

using namespace std;
int m = 0;

int binary(int a[], int l, int r, int k)
{
    if (r >= l)
    {
        m = (l + r) / 2;
        if (k == a[m])
        {
            for (int i = 0; i <= m; i++)
            {
                if (a[i] == k) return i;
            }
        }
        else if (k < a[m])
        { //lado esquerdo

            return binary(a, l, m - 1, k);
        }
        else
        { // lado direito
            return binary(a, m + 1, r, k);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n = 0;
    int e = 0;
    string asw = "";
    scanf("%d", &n);
    scanf("%d", &e);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int aux;
        scanf("%d", &aux);
        arr[i] = aux;
    }
    int count = 0;
    int test = 0;
    while (count < e)
    {
        count++;
        scanf("%d", &test);
        asw += binary(arr, 0, n, test) + "\n";
    }
    cout << asw;
}