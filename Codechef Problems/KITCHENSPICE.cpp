#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  scanf("%i", &n);
  if (n < 4)
  {
    printf("MILD\n");
  }
  else if (n < 7)
  {
    printf("MEDIUM\n");
  }
  else
  {
    printf("HOT\n");
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