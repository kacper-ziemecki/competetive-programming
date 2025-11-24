#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
  string text;
  cin >> text;
  long double res = 0;
  ll i = 0;
  for (; i < text.size(); i++)
  {
    string number = "";
    char symbol = text[i];
    while ((i + 1 < text.size()) && (text[i + 1] >= '0') && (text[i + 1] <= '9'))
    {
      number += text[i + 1];
      i++;
    }
    if (number == "")
      number = "1";
    long double convertedNumber = 0;
    long double power = 1;
    for (ll i = number.size() - 1; i >= 0; i--)
    {
      convertedNumber += (number[i] - '0') * power;
      power *= 10;
    }
    long double temp;
    if (symbol == 'C')
      temp = 12.01;
    if (symbol == 'H')
      temp = 1.008;
    if (symbol == 'O')
      temp = 16.00;
    if (symbol == 'N')
      temp = 14.01;

    temp *= convertedNumber;
    res += temp;
  }
  cout << setprecision(3) << fixed;
  cout << res << endl;
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

  ll t;
  cin >> t;
  while (t--)
    solve();
}