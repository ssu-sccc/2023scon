#include <bits/stdc++.h>
using namespace std;

int N, M, S, P[2020], R;
vector<tuple<int,int,int>> E;
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){ return Find(u) != Find(v) && (P[P[u]]=P[v], true); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> S; E.resize(M); iota(P+1, P+N+1, 1);
    for(auto &[w,u,v] : E) cin >> u >> v >> w;
    sort(E.begin(), E.end());
    for(auto [w,u,v] : E) if(Merge(u, v)) R += w;
    cout << R;
}