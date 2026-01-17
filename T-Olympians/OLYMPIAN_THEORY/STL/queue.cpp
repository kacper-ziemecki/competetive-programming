#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


int main()
{
  vector<int> lista = {1,5,3,2,5,7,4,3,1,5};

  // mozemy szybko push_backowac -> O(1)
  lista.pb(7);
  //usuwac byle gdzie -> O(n)
  lista.erase(lista.begin()+i);
  //usuwamy tylko z prawej strony, czyli konca -> O(1)
  lista.pop_back();

  queue<int> q;
  //mozemy szybko pushowac -> O(1)
  q.push(4);
  // albo
  q.emplace(4);
  // mozemy usunac z przodu -> O(1)
  q.pop();
  

}