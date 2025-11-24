#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b,c;
  cin >> a >> b >> c;
  int temp1,temp2;
  for(int i = 0; i < c; i++){
    cin >> temp1 >> temp2;
    if(temp1 == b){
      b = temp2;
    }
    else if(temp2 == b){
      b = temp1;
    }
  }
  cout << b << endl;
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