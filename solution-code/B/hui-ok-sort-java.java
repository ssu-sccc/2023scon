import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<Info> a = new ArrayList<>();
        for(int i=0; i<3; i++){
            int p = sc.nextInt();
            int y = sc.nextInt();
            String s = sc.next();
            a.add(new Info(p, y, s));
        }
        Collections.sort(a, new YearComparator());
        for(int i=0; i<3; i++) System.out.print(a.get(i).y % 100);
        System.out.println();
        Collections.sort(a, new ProblemComparator());
        for(int i=0; i<3; i++) System.out.print(a.get(i).s.charAt(0));
        System.out.println();
        sc.close();
    }
}

class Info{
    public int p, y;
    public String s;
    Info(int p, int y, String s){
        this.p = p;
        this.y = y;
        this.s = s;
    }
}

class YearComparator implements Comparator<Info> {
    @Override
    public int compare(Info a, Info b){ return a.y - b.y; }
}

class ProblemComparator implements Comparator<Info> {
    @Override
    public int compare(Info a, Info b){ return b.p - a.p; }
}