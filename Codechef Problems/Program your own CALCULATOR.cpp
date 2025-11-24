#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  long double a,b;
  cin >> a >> b;
  char c;
  cin >> c;
  if(c == '+'){
    cout << a+b << endl;
  }
  if(c == '-'){
    cout << a-b << endl;
  }
  if(c == '*'){
    cout << a*b << endl;
  }
  if(c == '/'){
    cout << a/b << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  solve();
}