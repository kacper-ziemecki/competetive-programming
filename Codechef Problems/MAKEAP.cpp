#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  scanf("%i%i", &a, &b);
  if (!((b - a) & 1))
  {
    printf("%i\n", (b - a) / 2 + a);
  }
  else
  {
    printf("-1\n");
  }
}

int main()
{
  int t;
  scanf("%i", &t);
  while (t--)
  {
    solve();
  }
}