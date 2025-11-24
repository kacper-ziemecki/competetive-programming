#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  string text;
  cin >> text;
  for(int i = 0; i < n - 1; i+= 2){
    char temp = text[i+1];
    text[i+1] = text[i];
    text[i] = temp;
    text[i] = 'z' - text[i] + 'a';
    text[i+1] = 'z' - text[i+1] + 'a';
  }
  if(n&1){
    text[n-1] = 'z' - text[n-1] + 'a';
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