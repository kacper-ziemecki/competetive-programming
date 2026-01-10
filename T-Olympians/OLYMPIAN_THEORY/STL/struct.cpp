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


struct DSU{
  vector<int> p, sajz;
  DSU(int n){ // n to jest ilosc wierzcholkow w moim dsu
    p.resize(n+1);
    sajz.assign(n+1, 1);
    for(int i = 0; i <= n; i++) p[i] = i;
  }
  int getSet(int a){
    return (p[a] == a ? a : p[a] = getSet(p[a]));
  }
  void unionSet(int a, int b){
    a = getSet(a);
    b = getSet(b);
    if(a == b) return;
    if(sajz[a] < sajz[b]) swap(a,b);
    p[b] = a;
    sajz[a] += sajz[b];
  }
  bool isCycle(int a, int b){ 
  // jest w tym samym zbiorze i chcemy jeszcze dodać krawędź pomiedzy a i b
  // to wtedy powstanie cykl
    a = getSet(a);
    b = getSet(b);
    return a == b;
  }
};

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../in.in", "r", stdin);
  freopen("../../../out.out", "w", stdout);
#endif

  int liczba = 0;
  DSU nazwa_zmiennej(5);
  // tworzymy zmienna dsu, która jest DSU i ma 10 wierzcholkow
  DSU dsu(10);
  // chcemy poloczyc 2 i 7 wierzcholek
  dsu.unionSet(2,7);
  // wazne:
  //1) funkcje, które definiujemy w strukturce nazwyją sie metodami
  //2) metody uruchamiamy poprzez podanie nazwy zmiennej oraz kropki
  // i dopiero wtedy nazwy metody z argumentami
  // np.
  cout << dsu.getSet(3) << endl;

  DSU dsu2(16);
  // jak tak sobie zrobie
  // to c++ nie wie czy odnosze sie do zmiennej dsu czy dsu2
  // przez co wyswietli sie error
  getSet(2); // ZLE
  // natomiast jak powiem c++, ze odnosze sie do jakiejsc 
  // konkretnej zmiennej to wtedy nie bedzie bledu
  dsu2.getSet(2); // OK
}