import java.util.*;
import java.io.*;

public class Main{
    static int dfs(Trie node, int take){
        if(node == null || node.sz == 0) return 0;
        Trie l = node.c[0], r = node.c[1];
        if(l == null && r == null) return node.sz - take;
        if(l == null) return dfs(r, take+1) + 1;
        if(r == null) return dfs(l, take+1) + 1;
        return Math.max(dfs(l, Math.max(0,take-r.sz)+1), dfs(r, Math.max(0,take-l.sz)+1)) + 1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        String[] temp = br.readLine().split(" ");
        long[] a = new long[n];
        for(int i=0; i<n; i++) a[i] = Long.parseLong(temp[i]);

        Trie trie = new Trie();
        for(int i=0; i<n; i++) trie.insert(a[i], 0);
        System.out.println(dfs(trie, 0));
        br.close();
    }
}

class Trie{
    public int sz;
    public Trie[] c;
    Trie(){ sz = 0; c = new Trie[2]; }
    public void insert(long v, int d){
        this.sz += 1;
        if(d == 60) return;
        int key = (int)(v % 2);
        if(c[key] == null) c[key] = new Trie();
        c[key].insert(v/2, d+1);
    }
}