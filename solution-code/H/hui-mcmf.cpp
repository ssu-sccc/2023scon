#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v, c, d, r;
    edge() = default;
    edge(int v, int c, int d, int r) : v(v), c(c), d(d), r(r) {}
};

int N, K, X, D[333], P[333], I[333], C[333];
vector<edge> G[333];
void add_edge(int u, int v, int c, int d){
    G[u].emplace_back(v, c, +d, (int)G[v].size());
    G[v].emplace_back(u, 0, -d, (int)G[u].size()-1);
}
pair<int,int> run(int s, int t){
    int flow = 0, cost = 0;
    while(true){
        memset(C, 0, sizeof C);
        memset(P, -1, sizeof P);
        memset(D, 0x3f, sizeof D);
        queue<int> Q; Q.push(s); D[s] = 0; C[s] = 1;
        while(!Q.empty()){
            int v = Q.front(); Q.pop(); C[v] = 0;
            for(int i=0; i<G[v].size(); i++){
                auto e = G[v][i];
                if(e.c > 0 && D[e.v] > D[v] + e.d){
                    D[e.v] = D[v] + e.d; P[e.v] = v; I[e.v] = i;
                    if(!C[e.v]) Q.push(e.v);
                }
            }
        }
        if(P[t] == -1) break;
        int fl = 1e9;
        for(int i=t; i!=s; i=P[i]) fl = min(fl, G[P[i]][I[i]].c);
        if(!fl) break;
        flow += fl; cost += fl * D[t];
        for(int i=t; i!=s; i=P[i]) G[P[i]][I[i]].c -= fl, G[i][G[P[i]][I[i]].r].c += fl;
    }
    return {flow, cost};
}

int A[22], O[22];
vector<int> V[22], R[22];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    int S = 0, T = N + K * X + 1;
    for(int i=1; i<=N; i++){
        int s; cin >> s; V[i].resize(s);
        for(auto &j : V[i]) cin >> j;
    }
    for(int i=1; i<=N; i++) cin >> A[i];
    iota(O+1, O+N+1, 1);
    sort(O+1, O+N+1, [](int u, int v){ return A[u] < A[v]; });

    for(int i=1; i<=N; i++) add_edge(S, i, 1, 0);
    for(int i=1; i<=K*X; i++) add_edge(N+i, T, 1, 0);
    for(int i=1; i<=N; i++){
        for(auto j : V[O[i]]){
            for(int k=1; k<=X; k++) add_edge(O[i], N + (j - 1) * X + k, 1, (1 << i) * -1);
        }
    }
    run(S, T);

    for(int i=1; i<=N; i++){
        for(auto e : G[i]) if(N < e.v && e.v < T && e.c == 0) R[(e.v-N-1)/X+1].push_back(i);
    }
    for(int i=1; i<=K; i++){
        cout << R[i].size() << " ";
        for(auto j : R[i]) cout << j << " ";
        cout << "\n";
    }
}