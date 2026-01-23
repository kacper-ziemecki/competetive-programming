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
  // {1,2,3,4,5,6}
  // pq.top(); - O(log n)
  // pq.push(5) - O(log n)
  log 1e6 = 20
  //            typ   w jaki sposob
  // priority_queue<int, vector<int>, less<>> pq;
  priority_queue<int, vector<int>, greater<>> pq;
  pq.push(5);
  pq.push(3);
  cout << pq.top() << endl;
  pq.push(100);
  pq.push(1);
  pq.push(10);
  cout << pq.top() << endl;
  cout << pq.size() << endl;
  cout << pq.empty() << endl;
  pq.pop();
  cout << pq.top() << endl;

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq1;
  pq1.push(make_pair(1,2));
  pq1.push(make_pair(1,3));
  pq1.push(make_pair(5,3));
  cout << pq1.top().first << ' ' << pq1.top().second << endl;
  pq1.pop();
  cout << pq1.top().first << ' ' << pq1.top().second << endl;
}