#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  for(int i = 0; i < text.size() - 4;i++){
    if(text[i] == 'p' && text[i+1] == 'a' && text[i+2] == 'r' && text[i+3] == 't' && text[i+4] == 'y'){
      text[i+4] = 'i';
      text[i+3] = 'r';
      text[i+2] = 'w';
    }
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