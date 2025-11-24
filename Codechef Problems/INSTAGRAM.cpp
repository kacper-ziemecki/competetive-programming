#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  scanf("%i%i", &a, &b);
  if (b * 10 < a)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
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