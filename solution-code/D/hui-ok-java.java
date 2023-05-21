import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n+1], p = new int[n+1];
        long[] res = new long[n+1];
        for(int i=1; i<=n; i++) a[i] = sc.nextInt();
        for(int i=1; i<=n; i++) p[a[i]] = i;
        for(int i=1; i<=n; i++){
            int j = p[i];
            int dist = i > j ? i - j : j - i;
            if(i == j) continue;
            int t = a[i]; a[i] = a[j]; a[j] = t;
            p[a[i]] = i; p[a[j]] = j;
            res[a[i]] += dist; res[a[j]] += dist;
        }
        for(int i=1; i<=n; i++) System.out.print(res[i] + " ");
        sc.close();
    }
}