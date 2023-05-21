import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        boolean flag = true;
        for(int i=1; i<n; i++) if(a[i] - a[i-1] != a[1] - a[0]) flag = false;
        if(flag){
            System.out.println("YES");
            for(int i=0; i<n; i++) System.out.print(a[i] + " ");
            System.out.println();
            for(int i=0; i<n; i++) System.out.print("0 ");
            System.out.println();
        }
        else System.out.println("NO");
        sc.close();
    }
}