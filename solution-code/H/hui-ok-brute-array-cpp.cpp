#include <bits/stdc++.h>
using namespace std;

int N, K, X, A[22], O[22];
vector<int> G[22];
vector<int> D[22][40404];

int Encode(const vector<int> &v){
    int res = 0;
    for(auto i : v) res = res * (X + 1) + i;
    return res;
}

vector<int> Decode(int v){
    vector<int> res(K);
    for(int i=K-1; i>=0; i--, v/=X+1) res[i] = v % (X + 1);
    return res;
}

void Print(vector<int> res){
    for(int i=0; i<K; i++){
        cout << count(res.begin(), res.end(), i) << " ";
        for(int j=0; j<N; j++) if(res[j] == i) cout << j + 1 << " ";
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K >> X;
    for(int i=0; i<N; i++){
        int c; cin >> c; G[i].resize(c);
        for(auto &j : G[i]) cin >> j, j--;
    }
    for(int i=0; i<N; i++) cin >> A[i], O[i] = i;
    sort(O, O+N, [](int u, int v){ return A[u] > A[v]; });

    for(auto i : G[O[0]]){
        vector<int> a(K), b(N, -1);
        a[i] = 1; b[O[0]] = i; D[0][Encode(a)] = b;
    }
    for(int i=1; i<N; i++){
        bool match = false;
        for(int g=0; g<40404; g++){
            if(D[i-1][g].empty()) continue;
            const auto &group = Decode(g), assign = D[i-1][g];
            for(auto j : G[O[i]]){
                if(group[j] == X) continue;
                auto a = group, b = assign;
                a[j] += 1; b[O[i]] = j;
                auto id = Encode(a);
                if(D[i][id].empty()) D[i][id] = b, match = true;
            }
        }
        if(!match) for(int g=0; g<40404; g++) D[i][g] = D[i-1][g];
    }
    for(int i=0; i<40404; i++) if(!D[N-1][i].empty()) { Print(D[N-1][i]); return 0; }
}