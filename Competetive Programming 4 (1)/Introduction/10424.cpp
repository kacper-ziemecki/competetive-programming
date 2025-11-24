#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string one, string two)
{
  ll sum1 = 0, sum2 = 0;
  for (auto el : one)
  {
    char temp = tolower(el);
    if (temp - 'a' >= 0 && temp - 'z' <= 0)
      sum1 += temp - 'a' + 1;
  }
  for (auto el : two)
  {
    char temp = tolower(el);
    if (temp - 'a' >= 0 && temp - 'z' <= 0)
      sum2 += temp - 'a' + 1;
  }

  while (sum1 >= 10)
  {
    ll temp = 0;
    while (sum1)
    {
      temp += sum1 % 10;
      sum1 /= 10;
    }
    sum1 = temp;
  }
  while (sum2 >= 10)
  {
    ll temp = 0;
    while (sum2)
    {
      temp += sum2 % 10;
      sum2 /= 10;
    }
    sum2 = temp;
  }

  cout << fixed << setprecision(2) << (long double)(min(sum2, sum1)) * 100 / (long double)(max(sum2, sum1)) << " %" << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  string one, two;
  while (getline(cin, one) && getline(cin, two))
    solve(one, two);
}