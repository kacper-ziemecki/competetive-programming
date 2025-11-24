  #include <bits/stdc++.h>
  using namespace std;
  #define endl "\n"
  #define ll long long int 

  void solve()
  {
    int n,a,b,res1 = 0, res2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> a >> b;
      int temp1 =0, temp2 = 0;
      while(a){
        temp1 += a % 10;
        a /= 10;
      }
      while(b){
        temp2 += b % 10;
        b /= 10;
      }
      if(temp1 > temp2){
        res1++;
      }
      else if(temp1 < temp2){
        res2++;
      }
      else{
        res1++;
        res2++;
      }
    }
    if(res1 > res2){
      cout << 0 << " " << res1 << endl;
    }
    else if(res1 < res2){
      cout << 1 << " " << res2 << endl;
    }
    else{
      cout << 2 << " " << res1 << endl;
    }
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