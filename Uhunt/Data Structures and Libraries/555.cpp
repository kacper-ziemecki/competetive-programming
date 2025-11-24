#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

map<char, int> mapa1{{'C', 4}, {'D', 3}, {'S', 2}, {'H', 1}};
map<char, int> mapa2{{'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}};
bool compare(string one, string two){
  if(mapa1[one[0]] == mapa1[two[0]]) return mapa2[one[1]] < mapa2[two[1]];
  return mapa1[one[0]] > mapa1[two[0]];

}

void solve(char dealer)
{
  vector<string> one, two, three, four;
  string lineOne, lineTwo, text;
  cin >> lineOne >> lineTwo;
  text = lineOne + lineTwo;
  ll time = 0;
  for(ll i = 1; i < text.size(); i+=2){
    time++;
    string s;
    if(time % 4 == 1){
      s+= text[i-1];
      s+=text[i];
      one.push_back(s);
    }
    else if(time % 4 == 2){
      s+= text[i-1];
      s+=text[i];
      two.push_back(s);
    }
    else if(time % 4 == 3){
      s+= text[i-1];
      s+=text[i];
      three.push_back(s);
    }
    else if(time % 4 == 0){
      s+= text[i-1];
      s+=text[i];
      four.push_back(s);
    }
  }
  sort(one.begin(), one.end(), compare);
  sort(two.begin(), two.end(), compare);
  sort(three.begin(), three.end(), compare);
  sort(four.begin(), four.end(), compare);
  string kolo = "NESW";
  for(ll i = 0; i < kolo.size(); i++){
    if(dealer == kolo[i]){
      ll tmp = 0;
      for(ll j = i; tmp < kolo.size(); j++, j %= kolo.size()){
        cout << kolo[(j+2) % kolo.size()] << ": ";
        if(tmp == 0){
          for(auto el : two) cout << el << " ";
          cout << endl;
        }
        if(tmp == 1){
          for(auto el : three) cout << el << " ";
            cout << endl;
        }
        if(tmp == 2){
          for(auto el : four) cout << el << " ";
            cout << endl;
        }
        if(tmp == 3){
          for(auto el : one) cout << el << " ";
            cout << endl;
        }
        tmp++;
      }
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  char dealer;
  while(true){
    cin >> dealer;
    if(dealer == '#'){
      break;
    } 
    solve(dealer);
  }
  
  
}