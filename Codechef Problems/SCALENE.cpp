#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c;
  scanf("%i%i%i", &a, &b, &c);
  if (a == b || a == c || b == c)
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n");
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