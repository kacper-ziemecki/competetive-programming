#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int M;

struct Fenwick{
  vector<long long> f;
  long long ss;
  long long koniec;
  void inicjuj_Fenwick(int n){
    ss = n+1;
    koniec=0;
    f.assign(ss, 0);
  }
  void koryguj_fakture(int idx, long long v){
    // if(koniec-idx+1 >= 1) idx = koniec-idx+1;
    else idx = ss+(koniec-idx+1)-1;
    while(idx < ss){
      f[idx] += v;
      idx += (idx&(-idx));
    }
  }
  long long suma_range(int l, int r){
    long long suma = 0;
    while(r){
      suma += f[r];
      r -= (r&(-r));
    }
    l--;
    while(l){
      suma -= f[l];
      l -= (l&(-l));
    }
    return suma;
  }
  void dodaj_fakture(long long v){
    if(++koniec == ss) koniec = 1;
    int idx = koniec;
    v = v-suma_range(idx,idx);
    while(idx < ss){
      f[idx] += v;
      idx += (idx&(-idx));
    }
  }
  long long suma_faktur(int idx){
    if(idx > koniec){
      return suma_range(1,koniec) + suma_range(ss-(idx-koniec),ss-1);
    } else{
      return suma_range(koniec-idx+1,koniec);
    }
  }
};

Fenwick fenwick;

void inicjuj(int m) {
  fenwick.inicjuj_Fenwick(m);
}

void dodaj(int k) {
  fenwick.dodaj_fakture(k);
}

void koryguj(int i, int k) {
  fenwick.koryguj_fakture(i, k);
}

long long suma(int i) {
  return fenwick.suma_faktur(i);
}
