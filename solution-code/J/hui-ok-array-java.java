import java.util.Scanner;

public class Main{
    static int p = 1;
    static int[] s;
    static int[][] c;
    static void insert(long v){
        int x = 1; s[x]++;
        for(int i=0; i<60; i++){
            int key = (int)(v >> i & 1);
            if(c[x][key] == 0) c[x][key] = ++p;
            x = c[x][key]; s[x]++;
        }
    }
    static int dfs(int node, int take){
        if(node == 0 || s[node] == take) return 0;
        if(c[node][0] == 0 && c[node][1] == 0) return s[node] - take;
        int l = c[node][0], r = c[node][1];
        if(l == 0) return dfs(r, take+1) + 1;
        if(r == 0) return dfs(l, take+1) + 1;
        return Math.max(dfs(l, Math.max(0,take-s[r])+1), dfs(r, Math.max(0,take-s[l])+1)) + 1;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++) a[i] = sc.nextLong();

        s = new int[n*61+2];
        c = new int[n*61+2][2];

        for(int i=0; i<n; i++) insert(a[i]);
        System.out.println(dfs(1, 0));
        sc.close();
    }
}