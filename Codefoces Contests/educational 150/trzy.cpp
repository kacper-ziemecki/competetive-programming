#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

bool check(string text, ll index, unordered_map<char,ll> test){
  string wzor = "ABCDE";
  for(char el : wzor){
    if(el - text[index] > 0){
      if(test[el] > index){
        return true;
      }
    }
  }
  return false;
}

bool checking(char element, ll index, unordered_map<char,ll> test){
string wzor = "ABCDE";
  for(char el : wzor){
    if(el - element > 0){
      if(test[el] > index){
        return true;
      }
    }
  }
  return false;
}
void solve()
{
  string text;
  cin >> text;
  ll suma = 0;
  vector<ll> lista;

  unordered_map<char, ll> test;
  for(ll i = text.size()-1; i >= 0; i--){
    if(!test[text[i]]){
      test[text[i]] = i;
    }
  }

  for(ll i = 0; i < text.size()-1; i++){
    if(check(text, i, test)){
      if(text[i] == 'A'){
        suma -= 1;
        lista.push_back(-1);
      }
      if(text[i] == 'B'){
        suma -= 10;
        lista.push_back(-10);
      }
      if(text[i] == 'C'){
        suma -= 100;
        lista.push_back(-100);
      }
      if(text[i] == 'D'){
        suma -= 1000;
        lista.push_back(-1000);
      }
      if(text[i] == 'E'){
        suma -= 10000;
        lista.push_back(-10000);
      }
    }
    else{
      if(text[i] == 'A'){
        suma += 1;
        lista.push_back(1);
      }
      if(text[i] == 'B'){
        suma += 10;
        lista.push_back(10);
      }
      if(text[i] == 'C'){
        suma += 100;
        lista.push_back(100);
      }
      if(text[i] == 'D'){
        suma += 1000;
        lista.push_back(1000);
      }
      if(text[i] == 'E'){
        suma += 10000;
        lista.push_back(10000);
      }
    }
  }
  if(text.back() == 'A'){
    suma += 1;
    lista.push_back(1);
  }
  if(text.back() == 'B'){
    suma += 10;
    lista.push_back(10);
  }
  if(text.back() == 'C'){
    suma += 100;
    lista.push_back(100);
  }
  if(text.back() == 'D'){
    suma += 1000;
    lista.push_back(1000);
  }
  if(text.back() == 'E'){
    suma += 10000;
    lista.push_back(10000);
  }

  ll res = suma;

  ll temp1 = 0;
  ll temp2 = 0;
  ll temp3 = 0;
  ll temp4 = 0;
  ll temp5 = 0;

  ll temp11 = 0;
  ll temp22 = 0;
  ll temp33 = 0;
  ll temp44 = 0;
  ll temp55 = 0;

  ll temp;
  for(ll i = 0; i < lista.size(); i++){
    temp = suma;

    temp -= lista[i];
    if(!checking('E', i, test)){
      temp += 10000;
      temp -= temp1 * 2;
      temp += temp11 * 2;
    }
    else{
      temp -= 10000;
    }

    res = max(res, temp);

    temp = suma;

    temp -= lista[i];
    if(!checking('D', i, test)){
      temp += 1000;
      temp -= temp2 * 2;
      temp += temp22 * 2;
    }
    else{
      temp -= 1000;
    }

    res = max(res, temp);

    temp = suma;

    temp -= lista[i];
    if(!checking('C', i, test)){
      temp += 100;
      temp -= temp3 * 2;
      temp += temp33 * 2;
    }
    else{
      temp -= 100;
    }

    res = max(res, temp);

    temp = suma;

    temp -= lista[i];
    if(!checking('B', i, test)){
      temp += 10;
      temp -= temp4 * 2;
      temp += temp44 * 2;
    }
    else{
      temp -= 10;
    }

    res = max(res, temp);

    temp = suma;

    temp -= lista[i];
    if(!checking('A', i, test)){
      temp += 1;
      temp -= temp5 * 2;
      temp += temp55 * 2;
    }
    else{
      temp -= 1;
    }


    res = max(res, temp);
    if(lista[i] < 10000 && lista[i] > 0) temp1 += lista[i];
    if(lista[i] < 1000 && lista[i] > 0) temp2 += lista[i];
    if(lista[i] < 100 && lista[i] > 0) temp3 += lista[i];
    if(lista[i] < 10 && lista[i] > 0) temp4 += lista[i];
    if(lista[i] < 1 && lista[i] > 0) temp5 += lista[i];

    if(lista[i] <= -10000 ) temp11 -= lista[i];
    if(lista[i] <= -1000 ) temp22 -= lista[i];
    if(lista[i] <= -100 ) temp33 -= lista[i];
    if(lista[i] <= -10 ) temp44 -= lista[i]; 
    if(lista[i] <= -1 ) temp55 -= lista[i];

    if(lista[i] > 10000 ) temp11 = 0;
    if(lista[i] > 1000 ) temp22 = 0;
    if(lista[i] > 100 ) temp33 = 0;
    if(lista[i] > 10 ) temp44 = 0; 
    if(lista[i] > 1 ) temp55 = 0;

  }
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}