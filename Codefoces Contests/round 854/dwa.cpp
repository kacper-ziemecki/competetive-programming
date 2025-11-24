#include <bits/stdc++.h>
using namespace std;

void solve()
{
  string napis;
  cin >> napis;
  vector<int> lista(26, 0);
  for (auto el : napis)
  {
    lista[el - 'a']++;
  }
  vector<char> res(napis.length(), ' ');
  int j = 0;
  for (int i = 0; i < 27; i++)
  {
    while (lista[i] - 2 >= 0)
    {
      res[j] = char('a' + i);
      res[napis.length() - 1 - j] = char('a' + i);
      lista[i] -= 2;
      j++;
    }
    if (lista[i] == 1)
    {
      int cnt = 0;
      int l = i;
      for (; l < 27; l++)
      {
        while (lista[l] - 1 >= 0)
        {
          if (cnt == 0)
          {
            res[napis.length() - 1 - j] = char('a' + l);
          }
          else
          {
            res[j] = char('a' + l);
          }
          if (cnt == 1)
            break;
          cnt++;
        }
        if (cnt == 1)
          break;
      }
      for (int k = l; k < 27; k++)
      {
        while (lista[k] - 1 >= 0)
        {
          res[j] = char('a' + i);
          lista[k]--;
          j++;
        }
      }
    }
  }
  for (auto el : res)
  {
    cout << el << " ";
  }
  cout << endl;
}

int main()
{
  long long t;
  cin >> t;
  while (t--)
    solve();
}