#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  vector<string> list1(a, " "), list2(b, " ");
  for(auto &el : list1) cin >> el;
  for(auto &el : list2) cin >> el;
  for(auto el : list2){
    if(el.size() >= 47){
      cout << "Good\n";
      continue;
    }
    else{
      bool flag = true;
      for(auto el2 : list1){
        for(int i = 0; i < el.size() - el2.size() + 1; i++){
          for(int j = i; j < i+el2.size(); j++){
            if(el[j] != el2[j - i]){
              flag
            }
          }
          if(el.substr(i, el2.size()) == el2){
            cout << "Good\n";
            flag = true;
            break;
          }
        }
        if(flag){
          break;
        }
      }
      if(flag) continue;
    }
    cout << "Bad\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  solve();
}