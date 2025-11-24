#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int a, b;
  scanf("%i%i", &a, &b);
  printf("%s", a * 3 <= b ? "YES\n" : "NO\n");
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
