#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> V(N);
    for(auto &i : V) cin >> i;
    for(int i=2; i<N; i++) if(V[1] - V[0] != V[i] - V[i-1]) { cout << "NO"; return 0; }
    cout << "YES\n";
    for(auto i : V) cout << i << " "; cout << "\n";
    for(int i=0; i<N; i++) cout << "0 "; cout << "\n";
}