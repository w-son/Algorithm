import java.util.*;

class Solution {

    private Map<String, Integer> map;
    private List<Movie> list;
    private Comparator<Movie> cmp;

    public Class Movie {
        String name;
        int cnt;
        public Movie(String name, int cnt) {
            this.name = name;
            this.cnt = cnt;
        }
    }

    public String[] solution(String[] movie) {
        map = new HashMap<>();
        list = new ArrayList<>();
        cmp = new Comparator<Movie>() {
            @Override
            public int compare(Movie o1, Movie o2) {
                if(o1.cnt == o2.cnt)
                    return o1.name.compareTo(o2.name);
                else
                    return o1.cnt < o2.cnt ? -1 : 1;
            }
        }

        for(int i=0; i<movie.length; i++) {
            String now = movie[i];
            int cnt = map.getOrDefault(now, 0);
            map.put(now, cnt+1);
        }

        for(String key : map.keySet())
            list.add(new Movie(key, map.get(key)));
        Collections.sort(list, cmp);

        int len = list.size();
        String[] ans = new String[len];
        for(int i=0; i<len; i++) {
            ans[i] = list.get(i).name;
        }

        return ans;
    }
}