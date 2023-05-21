#include <bits/stdc++.h>
using namespace std;

int P[3], Y[3];
string S[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=0; i<3; i++) cin >> P[i] >> Y[i] >> S[i];
    if(Y[0] < Y[1] && Y[1] < Y[2]) cout << Y[0] % 100 << Y[1] % 100 << Y[2] % 100 << endl;
    if(Y[0] < Y[2] && Y[2] < Y[1]) cout << Y[0] % 100 << Y[2] % 100 << Y[1] % 100 << endl;
    if(Y[1] < Y[0] && Y[0] < Y[2]) cout << Y[1] % 100 << Y[0] % 100 << Y[2] % 100 << endl;
    if(Y[1] < Y[2] && Y[2] < Y[0]) cout << Y[1] % 100 << Y[2] % 100 << Y[0] % 100 << endl;
    if(Y[2] < Y[0] && Y[0] < Y[1]) cout << Y[2] % 100 << Y[0] % 100 << Y[1] % 100 << endl;
    if(Y[2] < Y[1] && Y[1] < Y[0]) cout << Y[2] % 100 << Y[1] % 100 << Y[0] % 100 << endl;
    if(P[0] > P[1] && P[1] > P[2]) cout << S[0][0] << S[1][0] << S[2][0] << endl;
    if(P[0] > P[2] && P[2] > P[1]) cout << S[0][0] << S[2][0] << S[1][0] << endl;
    if(P[1] > P[0] && P[0] > P[2]) cout << S[1][0] << S[0][0] << S[2][0] << endl;
    if(P[1] > P[2] && P[2] > P[0]) cout << S[1][0] << S[2][0] << S[0][0] << endl;
    if(P[2] > P[0] && P[0] > P[1]) cout << S[2][0] << S[0][0] << S[1][0] << endl;
    if(P[2] > P[1] && P[1] > P[0]) cout << S[2][0] << S[1][0] << S[0][0] << endl;
}