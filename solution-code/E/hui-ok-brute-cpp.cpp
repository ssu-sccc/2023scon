#include <bits/stdc++.h>
using namespace std;

int N, R;
string S;

void f(int idx){
    if(idx == N){ R++; return; }
    f(idx+1);
    if(idx + 7 < N && S.substr(idx, 8) == "longlong") f(idx+8);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> S;
    f(0);
    cout << R;
}