import java.util.*;

public class Main{
    static int n, m, res;
    static int[] c;
    static int[][] g;

    static void dfs(int v){
        c[v] = 1;
        for(int i=1; i<=n; i++) if(g[v][i] == 1 && c[i] == 0) dfs(i);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        c = new int[n+1];
        g = new int[n+1][n+1];
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            g[u][v] = g[v][u] = 1;
        }
        for(int i=1; i<=n; i++) if(c[i] == 0) { dfs(i); res++; }
        System.out.println(res - 1);
        sc.close();
    }
}