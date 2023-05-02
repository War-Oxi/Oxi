#include <iostream>
using namespace std;

using ll = long long;

ll POW(ll a, ll b, ll m){
  if(b == 1) return a % m;
  ll val = POW(a, b/2, m);
  val = val * val % m;
  if(b % 2 == 0) return val % m;
  return val * a % m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, C;
  cin >> A >> B >> C;
  cout << POW(A, B, C);
}