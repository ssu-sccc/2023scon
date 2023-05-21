#include <bits/stdc++.h>
using namespace std;

int N, D[22] = {1, 1};
string S;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> S;
    for(int i=2; i<22; i++) D[i] = D[i-1] + D[i-2];
    
    int C = 0, R = 1;
    for(int i=0; i<N; i++){
        if(i + 3 < N && S.substr(i, 4) == "long") C++, i += 3;
        else R *= D[C], C = 0;
    }
    cout << R * D[C];
}