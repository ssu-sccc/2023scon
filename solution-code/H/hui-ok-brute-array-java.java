import java.util.Scanner;

public class Main{
    static int n, k, x;
    static int[] a, o;
    static int[][] g;
    static int[][][] d;

    static int encode(int[] v){
        int res = 0;
        for(int i=0; i<k; i++) res = res * (x + 1) + v[i];
        return res;
    }

    static int[] decode(int v){
        int[] res = new int[k];
        for(int i=k-1; i>=0; i--, v/=x+1) res[i] = v % (x + 1);
        return res;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        x = sc.nextInt();

        a = new int[n];
        o = new int[n];
        g = new int[n][];
        d = new int[n][40404][];

        for(int i=0; i<n; i++){
            int c = sc.nextInt();
            g[i] = new int[c];
            for(int j=0; j<c; j++) g[i][j] = sc.nextInt() - 1;
        }
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        for(int i=0; i<n; i++) o[i] = i;
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(a[o[j-1]] < a[o[j]]){ int t = o[j-1]; o[j-1] = o[j]; o[j] = t; }
            }
        }

        for(int i : g[o[0]]){
            int[] a = new int[k], b = new int[n];
            for(int j=0; j<n; j++) b[j] = -1;
            a[i] = 1; b[o[0]] = i; d[0][encode(a)] = b;
        }

        for(int i=1; i<n; i++){
            boolean match = false;
            for(int gr=0; gr<40404; gr++){
                if(d[i-1][gr] == null) continue;
                int[] group = decode(gr), assign = d[i-1][gr];
                for(int j : g[o[i]]){
                    if(group[j] == x) continue;
                    int[] a = new int[k], b = new int[n];
                    for(int s=0; s<k; s++) a[s] = group[s];
                    for(int s=0; s<n; s++) b[s] = assign[s];
                    a[j] += 1; b[o[i]] = j;
                    int id = encode(a);
                    if(d[i][id] == null){ d[i][id] = b; match = true; }
                }
            }
            if(!match) d[i] = d[i-1];
        }

        int[] res = null;
        for(int i=0; i<40404; i++) if(d[n-1][i] != null) res = d[n-1][i];
        for(int i=0; i<k; i++){
            int cnt = 0;
            for(int j=0; j<n; j++) if(res[j] == i) cnt++;
            System.out.print(cnt + " ");
            for(int j=0; j<n; j++) if(res[j] == i) System.out.print(j+1 + " ");
            System.out.println();
        }
    }
}