#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b, c;
  scanf("%i%i%i", &a, &b, &c);
  if (a * b < 0 || a * c < 0 || b * c < 0)
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