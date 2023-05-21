#include <bits/stdc++.h>
using namespace std;

tuple<int,int,string> A[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(auto &[p,y,s] : A) cin >> p >> y >> s;
    sort(A, A+3, [](auto a, auto b){ return get<1>(a) < get<1>(b); });
    for(int i=0; i<3; i++) cout << get<1>(A[i]) % 100;
    cout << "\n";
    sort(A, A+3, [](auto a, auto b){ return get<0>(a) > get<0>(b); });
    for(int i=0; i<3; i++) cout << get<2>(A[i])[0];
}