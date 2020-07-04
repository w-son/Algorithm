import java.util.*;

class Solution {

    private boolean[][] map;
    private int[] dist;

    public int solution(int n, int[][] edge) {

        map = new boolean[n+1][n+1];
        dist = new int[n+1];
        Arrays.fill(dist, -1);

        for(int i=0; i<edge.length; i++) {
            int x = edge[i][0];
            int y = edge[i][1];
            map[x][y] = true;
            map[y][x] = true;
        }

        int max = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        dist[1] = 1;
        while(!queue.isEmpty()) {
            int now = queue.poll();
            for(int i=1; i<=n; i++) {
                if(map[now][i] && dist[i] == -1) {
                    dist[i] = dist[now] + 1;
                    if(dist[i] > max)
                        max = dist[i];

                    queue.add(i);
                }
            }
        }

        final int cmp = max;
        return (int) Arrays.stream(dist).filter(x -> x == cmp).count();
    }
}