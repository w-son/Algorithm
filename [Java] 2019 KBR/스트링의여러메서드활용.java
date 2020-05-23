// 매칭 점수 : String indexOf, substring, toLowerCase, isAlphabetic
import java.util.*;

class Match {
    int idx;
    double score;
    public Match(int idx, double score) {
        this.idx = idx;
        this.score = score;
    }
}

class Solution {

    private HashMap<String, ArrayList<String>> map;
    private HashMap<String, Double> pscore;
    private HashMap<String, Double> lscore;
    private ArrayList<Match> match;
    private Comparator<Match> cmp;

    public void init() {
        this.map = new HashMap<>();
        this.pscore = new HashMap<>();
        this.lscore = new HashMap<>();
        this.match = new ArrayList<>();
        this.cmp = new Comparator<Match>() {
            @Override
            public int compare(Match o1, Match o2) {
                if(o1.score == o2.score)
                    return o1.idx - o2.idx;
                else
                    return o2.score - o1.score > 0 ? 1 : -1;
            }
        };
    }

    // 페이지의 기본 점수를 리턴하는 함수
    public int getPrimaryScore(String page, String word) {
        int score = 0;
        int start = 0;
        while((start = page.indexOf(word, start)) != -1) {
            int end = start + word.length();
            if(!Character.isAlphabetic(page.charAt(start-1))&&!Character.isAlphabetic(page.charAt(end)))
                score++;
            start = end;
        }
        return score;
    }

    // 페이지의 url을 리턴하는 함수
    public String getUrl(String page) {
        int start = page.indexOf("<meta property=\"og:url\" content=\"") + 33;
        int end = start;
        while(page.charAt(end) != '\"') end++;
        return page.substring(start, end);
    }

    // 페이지의 link를 리턴하는 함수
    public ArrayList<String> getLinks(String page) {
        int start = 0;
        ArrayList<String> links = new ArrayList<>();
        while((start = page.indexOf("<a href=\"", start)) != -1) {
            start += 9;
            int end = start;
            while(page.charAt(end) != '\"') end++;
            links.add(page.substring(start, end));
            start = end;
        }
        return links;
    }

    public int solution(String word, String[] pages) {
        // 초기화
        init();
        int len = pages.length;
        word = word.toLowerCase();
        for(int i=0; i<len; i++)
            pages[i] = pages[i].toLowerCase();

        // 링크들과 기본점수 구하기
        for(int i=0; i<len; i++) {
            String page = pages[i];
            String url = getUrl(page);
            double score = (double) getPrimaryScore(page, word);
            ArrayList<String> links = getLinks(page);
            map.put(url, links);
            pscore.put(url, score);
        }

        for(String url : map.keySet()) {
            ArrayList<String> links = map.get(url);
            if(links.size() > 0) {
                double score = pscore.get(url) / links.size();
                for(String link : links)
                    if(pscore.getOrDefault(link, (double)-1) != (double)-1) {
                        double added = lscore.getOrDefault(link, (double)0) + score;
                        lscore.put(link, added);
                    }
            }
        }

        for(int i=0; i<len; i++) {
            String url = getUrl(pages[i]);
            double p = pscore.get(url);
            double l = lscore.getOrDefault(url, (double)0);
            Match m = new Match(i, p + l);
            match.add(m);
        }
        Collections.sort(match, cmp);
        return match.get(0).idx;
    }
}