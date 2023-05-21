import java.util.*;
import java.io.*;

public class Main{
    static int n, q, res;
    static int[] p, s, r;
    static int find(int v){
        while(v != p[v]){
            int nxt = p[v];
            p[v] = p[nxt]; v = nxt;
        }
        return v;
    }
    static void merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
        if(find(u^1) == u) res -= s[u];
        if(find(v^1) == v) res -= s[v];
        if(r[u] > r[v]){ int t = u; u = v; v = t; }
        p[u] = v; s[v] += s[u];
        if(r[u] == r[v]) r[v]++;
        if(find(v^1) == v) res += s[v];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] temp = br.readLine().split(" ");
        n = Integer.parseInt(temp[0]);
        q = Integer.parseInt(temp[1]);
        p = new int[2*n]; s = new int[2*n]; r = new int[2*n];
        for(int i=0; i<2*n; i++){ p[i] = i; s[i] = i % 2; }
        for(int i=0; i<q; i++){
            temp = br.readLine().split(" ");
            int u = Integer.parseInt(temp[0]) - 1;
            int v = Integer.parseInt(temp[1]) - 1;
            merge(u*2, v*2+1);
            merge(v*2, u*2+1);
            bw.write(String.valueOf(res) + "\n");
        }
        br.close();
        bw.close();
    }
}