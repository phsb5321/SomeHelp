// UVA - 11988

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 5;
int last, cur;
int Next[maxn];
char s[maxn];

int main()
{
  while (scanf("%s", s + 1) == 1)
  {
    int n = strlen(s + 1);
    last = cur = 0;
    Next[0] = 0;
    for (int i = 1; i <= n; i++)
    {
      char ch = s[i];
      if (ch == '[')
        cur = 0;
      else if (ch == ']')
        cur = last;
      else
      {
        Next[i] = Next[cur];
        Next[cur] = i;
        if (cur == last)
          last = i;
        cur = i;
      }
    }
    for (int i = Next[0]; i != 0; i = Next[i])
      printf("%c", s[i]);
    printf("\n");
  }
}