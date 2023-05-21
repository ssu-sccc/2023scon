#include <bits/stdc++.h>
using namespace std;

int N, K, X, A[333], O[333], C[333], P[333], T[333];
vector<int> G[333];

bool DFS(int v){
    for(auto i : G[v]){
        if(C[i]) continue; C[i] = 1;
        if(!P[i] || DFS(P[i])){ P[i] = v; return true; }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    for(int i=1; i<=N; i++){
        int s; cin >> s;
        for(int j=1; j<=s; j++){
            int t; cin >> t;
            for(int k=1; k<=X; k++) G[i].push_back((t-1)*X+k-1);
        }
    }
    for(int i=1; i<=N; i++) cin >> A[i], O[i] = i;
    sort(O+1, O+N+1, [](int u, int v){ return A[u] > A[v]; });
    for(int i=1; i<=N; i++){
        memset(C, 0, sizeof C);
        memcpy(T, P, sizeof T);
        if(!DFS(O[i])) memcpy(P, T, sizeof P);
    }
    for(int i=1; i<=K; i++){
        cout << X - count(P+(i-1)*X, P+i*X, 0) << " ";
        for(int j=(i-1)*X; j<i*X; j++) if(P[j]) cout << P[j] << " ";
        cout << "\n";
    }
}