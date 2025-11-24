#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  scanf("%i", &n);
  if (n <= 70)
  {
    printf("0\n");
  }
  else if (n <= 100)
  {
    printf("500\n");
  }
  else
  {
    printf("2000\n");
  }
}
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    solve();
  }
}