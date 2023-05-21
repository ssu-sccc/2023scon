#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 500'000;

int N, A[SZ+1], P[SZ+1];
ll R[SZ+1];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], P[A[i]] = i;
    for(int i=1; i<=N; i++){
        int j = P[i]; if(i == j) continue;
        swap(A[i], A[j]);
        P[A[i]] = i; P[A[j]] = j;
        R[A[i]] += abs(i - j);
        R[A[j]] += abs(i - j);
    }
    for(int i=1; i<=N; i++) cout << R[i] << " \n"[i==N];
}