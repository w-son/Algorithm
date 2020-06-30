import java.awt.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

    private static int n;
    private static int m;
    private static int count;
    private static char[][] map;
    private static int[] mx = new int[] { 1, -1, 0, 0 };
    private static int[] my = new int[] { 0, 0, 1, -1 };

    public static boolean checkPuyo() {

        boolean[][] check = new boolean[n][m];

        // 터지는 조건을 만족하는 뿌요좌표가 들어있다
        List<Point> list = new ArrayList<Point>();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] != '.') {
                    char color = map[i][j];
                    List<Point> temp = new ArrayList<Point>();
                    Queue<Point> queue = new LinkedList<Point>();

                    // 현재 붙어있는 뿌요 색을 temp에 담는다
                    check[i][j] = true;
                    temp.add(new Point(i, j));
                    queue.add(new Point(i, j));
                    while(!queue.isEmpty()) {
                        Point now = queue.poll();
                        for(int k=0; k<4; k++) {
                            int X = now.x + mx[k];
                            int Y = now.y + my[k];
                            if(0<=X&&X<n && 0<=Y&&Y<m) {
                                if(map[X][Y] == color && !check[X][Y]) {
                                    check[X][Y] = true;
                                    temp.add(new Point(X, Y));
                                    queue.add(new Point(X, Y));
                                }
                            }
                        }
                    }
                    // temp가 4개 이상, 즉 뿌요가 터지는 조건이면 리스트에 추가
                    if(temp.size() >= 4)
                        list.addAll(temp);
                }
            }
        }

        if(list.size() == 0) return false;
        else { // 뿌요 다 터트리고 리턴
            for(Point puyo : list)
                map[puyo.x][puyo.y] = '.';

            return true;
        }
    }

    public static void dropPuyo() {

        for(int j=0; j<m; j++) {
            for(int i=n-1; i>=0; i--) {

                char temp = '.';
                for(int k=i; k>=0; k--) {
                    if(map[k][j] != '.') {
                        temp = map[k][j];
                        map[k][j] = '.';
                        break;
                    }
                }
                map[i][j] = temp;
            }
        }
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = 12;
        m = 6;
        count = 0;
        map = new char[n][m];

        for(int i=0; i<n; i++) {
            String str = br.readLine();
            for(int j=0; j<m; j++)
                map[i][j] = str.charAt(j);
        }

        while(checkPuyo()) {
            count += 1;
            dropPuyo();
        }

        System.out.println(count);
    }

}
