// 베스트앨범 : HashMap, ArrayList, Comparator, stream
import java.util.*;

class Song {
    int index;
    int plays;
    public Song(int i, int p) {
        this.index = i;
        this.plays = p;
    }
};

class Genre {
    String name;
    int count;
    ArrayList<Song> list;
    public Genre(String n) {
        this.name = n;
        this.count = 0;
        this.list = new ArrayList<>();
    }
    public void add(int i, int c) {
        Song temp = new Song(i, c);
        this.count += c;
        list.add(temp);
    }
    public void sort() {
        Comparator<Song> cmp = new Comparator<Song>() {
            @Override
            public int compare(Song o1, Song o2) {
                if(o1.plays == o2.plays) return o1.index - o2.index;
                else return o2.plays - o1.plays;
            }
        };
        Collections.sort(this.list, cmp);
    }
};

class Solution {

    public int[] solution(String[] genres, int[] plays) {

        HashMap<String, Genre> map = new HashMap<>();

        int len = genres.length;
        for(int i=0; i<len; i++) {
            Genre genre = map.getOrDefault(genres[i], new Genre(genres[i]));
            genre.add(i, plays[i]);
            map.put(genres[i], genre);
        }

        ArrayList<Genre> list = new ArrayList<>();
        for(String key : map.keySet()) {
            Genre genre = map.get(key);
            genre.sort();
            list.add(genre);
        }

        Comparator<Genre> cmp = new Comparator<Genre>() {
            @Override
            public int compare(Genre o1, Genre o2) {
                return o2.count - o1.count;
            }
        };
        Collections.sort(list, cmp);

        len = list.size();
        ArrayList<Integer> answer = new ArrayList<>();
        for(int i=0; i<len; i++) {
            Genre now = list.get(i);
            answer.add(now.list.get(0).index);
            if(now.list.size() >= 2)
                answer.add(now.list.get(1).index);
        }

        return answer.stream().mapToInt(i->i.intValue()).toArray();
    }
}