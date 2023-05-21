#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[202020];
int C[12121212][2], S[12121212], P=1;

void Insert(ll v){
    int x = 1; S[x]++;
    for(int i=0; i<60; i++){
        int key = v >> i & 1;
        if(!C[x][key]) C[x][key] = ++P;
        x = C[x][key]; S[x]++;
    }
}

int DFS(int node, int take){
    if(!node || S[node] == take) return 0;
    if(!C[node][0] && !C[node][1]) return S[node] - take;
    int l = C[node][0], r = C[node][1];
    if(!l) return DFS(r, take+1) + 1;
    if(!r) return DFS(l, take+1) + 1;
    return max(DFS(l, max(0,take-S[r])+1), DFS(r, max(0,take-S[l])+1)) + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) Insert(A[i]);
    cout << DFS(1, 0);
}