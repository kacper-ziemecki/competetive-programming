#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

vector<pair<int,int>> res;

void subsolve(int a, int b,int k = 100){
  if(k == 0){
    res.push_back({a,b});
    return;
  }
  if(a+2 <= 8 && b+1 <= 8){
    subsolve(a+2, b+1, k-1);
  }
  if(a+2 <= 8 && b-1 >= 1){
    subsolve(a+2, b-1, k-1);
  }
  if(a-2 >= 1 && b+1 <= 8){
    subsolve(a-2, b+1, k-1);
  }
  if(a-2 >= 1 && b-1 >= 1){
    subsolve(a-2, b-1, k-1);
  }
  if(a+2 <= 8 && b+1 <= 8){
    subsolve(a+2, b+1, k-1);
  }

  if(b+2 <= 8 && a-1 >= 1){
    subsolve(a-1, b+2, k-1);
  }
  if(b-2 >= 1 && a+1 <= 8){
    subsolve(a+1, b-2, k-1);
  }
  if(b-2 >= 1 && a-1 >= 1){
    subsolve(a-1, b-2, k-1);
  }

}

void solve()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  subsolve(a,b);
  for(auto el : res){
    cout << el.first << " " << el.second << endl;
  }
  cout << "-------------\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}