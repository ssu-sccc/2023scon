import java.util.*;

public class Main{
    static int n, m, res;
    static int[][] g;

    static boolean go(int c){
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                for(int k=j+1; k<=n; k++){
                    if(g[i][j] + g[i][k] + g[j][k] + c == 2){
                        g[i][j] = g[i][k] = g[j][k] = 1;
                        res += c;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        g = new int[n+1][n+1];
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            g[u][v] = 1;
        }
        while(go(0) || go(1));
        System.out.println(res);
        sc.close();
    }
}