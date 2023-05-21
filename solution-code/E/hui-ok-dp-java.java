import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        int[] dp = new int[22];
        dp[0] = dp[1] = 1;
        for(int i=2; i<22; i++) dp[i] = dp[i-1] + dp[i-2];

        int cnt = 0, res = 1;
        for(int i=0; i<n; i++){
            if(i + 3 < n && s.substring(i, i+4).equals("long")){ cnt++; i += 3; }
            else{ res *= dp[cnt]; cnt = 0; }
        }
        System.out.println(res * dp[cnt]);
        sc.close();
    }
}