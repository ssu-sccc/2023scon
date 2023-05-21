import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int[][] g = new int[n][n];
        int[] c = new int[n];
        boolean[] f = new boolean[n];

        for(int i=0; i<n; i++){
            c[i] = 101010; f[i] = false;
            for(int j=0; j<n; j++) g[i][j] = 101010;
        }

        for(int i=0; i<m; i++){
            int u = sc.nextInt(); u--;
            int v = sc.nextInt(); v--;
            int w = sc.nextInt();
            if(w < g[u][v]) g[u][v] = w;
            if(w < g[v][u]) g[v][u] = w;
        }

        f[0] = true;
        for(int i=1; i<n; i++) c[i] = g[0][i];

        int res = 0;
        for(int iter=1; iter<n; iter++){
            int v = 0;
            for(int i=0; i<n; i++) if(c[v] > c[i]) v = i;
            res += c[v]; c[v] = 101010; f[v] = true;
            for(int i=0; i<n; i++) if(!f[i] && c[i] > g[v][i]) c[i] = g[v][i];
        }
        System.out.println(res);
        sc.close();
    }
}