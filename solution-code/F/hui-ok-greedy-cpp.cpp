#include <bits/stdc++.h>
using namespace std;

int N, M, G[44][44], R;

bool Go(int c){
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            for(int k=j+1; k<=N; k++){
                if(G[i][j] + G[i][k] + G[j][k] + c == 2){
                    G[i][j] = G[i][k] = G[j][k] = 1;
                    R += c;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1,u,v; i<=M; i++) cin >> u >> v, G[u][v] = 1;
    while(Go(0) || Go(1));
    cout << R;
}