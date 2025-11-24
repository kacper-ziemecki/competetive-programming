#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,k;
  cin >> n >> k;
  string text;
  cin >> text;
  if(text[0] == '0'){
    text[0] = '1';
    k--;
  }
  while(k){
    text += '0';
    k--;
  }
  cout << text << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}