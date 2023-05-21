#include <bits/stdc++.h>
using namespace std;

int N, Q, P[606060], S[606060], R;
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
void Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    if(Find(u^1) == u) R -= S[u];
    if(Find(v^1) == v) R -= S[v];
    P[u] = v; S[v] += S[u];
    if(Find(v^1) == v) R += S[v];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    iota(P, P+606060, 0);
    for(int i=1; i<=N; i++) S[i*2] = 1;
    for(int q=1; q<=Q; q++){
        int u, v; cin >> u >> v;
        Merge(u*2, v*2+1);
        Merge(v*2, u*2+1);
        cout << R << "\n";
    }
}