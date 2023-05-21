#include <bits/stdc++.h>
using namespace std;

int N, M, C[44], G[44][44], R;

void DFS(int v){
    C[v] = 1;
    for(int i=1; i<=N; i++) if(G[v][i] && !C[i]) DFS(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1,u,v; i<=M; i++) cin >> u >> v, G[u][v] = G[v][u] = 1;
    for(int i=1; i<=N; i++) if(!C[i]) DFS(i), R++;
    cout << R - 1;
}