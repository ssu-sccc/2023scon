import java.util.*;

public class Main{
    static int[] p, r;
    static int find(int v){
        while(v != p[v]){
            int nxt = p[v];
            p[v] = p[p[v]]; v = nxt;
        }
        return v;
    }
    static boolean merge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        if(r[u] > r[v]){ int t = u; u = v; v = t; }
        p[u] = v;
        if(r[u] == r[v]) r[v] += 1;
        return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        ArrayList<Edge> e = new ArrayList<>();
        for(int i=0; i<m; i++){
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            e.add(new Edge(u, v, w));
        }
        p = new int[n+1];
        r = new int[n+1];
        for(int i=1; i<=n; i++) p[i] = i;
        Collections.sort(e, new EdgeComparator());

        int res = 0;
        for(int i=0; i<m; i++) if(merge(e.get(i).u, e.get(i).v)) res += e.get(i).w;
        System.out.println(res);
        sc.close();
    }
}

class Edge{
    public int u, v, w;
    Edge(int u, int v, int w){
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

class EdgeComparator implements Comparator<Edge> {
    @Override
    public int compare(Edge a, Edge b){ return a.w - b.w; }
}