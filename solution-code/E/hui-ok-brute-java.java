import java.util.Scanner;

public class Main{
    static int n, res;
    static String s;
    static void f(int idx){
        if(idx == n){ res++; return; }
        f(idx + 1);
        if(idx + 7 < n && s.substring(idx, idx+8).equals("longlong")) f(idx + 8);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        s = sc.next();
        f(0);
        System.out.println(res);
        sc.close();
    }
}