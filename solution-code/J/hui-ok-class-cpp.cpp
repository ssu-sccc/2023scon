#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int sz;
    node *c[2];
    node(){ sz = 0; c[0] = c[1] = nullptr; }
    void insert(ll v, int d){
        sz++; if(d == 60) return;
        if(!c[v%2]) c[v%2] = new node;
        c[v%2]->insert(v/2, d+1);
    }
};

ll N, A[202020];

int DFS(node *T, int take){
    if(!T || T->sz == take) return 0;
    if(!T->c[0] && !T->c[1]) return T->sz - take;
    auto l = T->c[0], r = T->c[1];
    if(!l) return DFS(r, take+1) + 1;
    if(!r) return DFS(l, take+1) + 1;
    return max(DFS(l, max(0,take-r->sz)+1), DFS(r, max(0,take-l->sz)+1)) + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    node *T = new node;
    for(int i=1; i<=N; i++) T->insert(A[i], 0);
    cout << DFS(T, 0);
}