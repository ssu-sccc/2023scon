#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B; cin >> N >> A >> B;
    if(A < B) cout << "Bus";
    else if(A > B) cout << "Subway";
    else cout << "Anything";
}