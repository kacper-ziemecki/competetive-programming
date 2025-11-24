#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  int res = 0,i = 0;
  for(;i < text.size() - 1;){
    if(text[i] != text[i+1]){
      res++;
      i++;
    }
    i++;
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}