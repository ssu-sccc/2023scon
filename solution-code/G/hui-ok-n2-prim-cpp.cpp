#include <bits/stdc++.h>
using namespace std;

int N, M, S, G[2020][2020], C[2020], F[2020], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> S;
    memset(G, 0x3f, sizeof G); memset(C, 0x3f, sizeof C);
    for(int i=0,u,v,w; i<M; i++) cin >> u >> v >> w, G[u][v] = G[v][u] = min(G[v][u], w);
    F[1] = 1; for(int i=2; i<=N; i++) C[i] = G[1][i];
    for(int iter=1; iter<N; iter++){
        int v = min_element(C+1, C+N+1) - C;
        R += C[v]; C[v] = 0x3f3f3f3f; F[v] = 1;
        for(int i=1; i<=N; i++) if(!F[i]) C[i] = min(C[i], G[v][i]);
    }
    cout << R;
}