// 길 찾기 게임 : 전위 순회, 후위 순회, 포인터 활용
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node {
    int x;
    int y;
    int num;
    node * left;
    node * right;
};

unordered_map<int, vector<node>> table;
vector<int> levels;
vector<int> preorder;
vector<int> postorder;
node* root;

// 전위 순회
void preorder_traverse(node* now) {
    preorder.push_back(now->num);
    if(now->left != NULL)
        preorder_traverse(now->left);
    if(now->right != NULL)
        preorder_traverse(now->right);
}
// 후위 순회
void postorder_traverse(node* now) {
    if(now->left != NULL)
        postorder_traverse(now->left);
    if(now->right != NULL)
        postorder_traverse(now->right);
    postorder.push_back(now->num);
}
// 트리 생성
void make_tree(node* now, int left, int right, int next) {
    if(next == levels.size())
        return;
    
    int mid = now->x;
    for(int i=0; i<table[levels[next]].size(); i++) {
        node* temp = &table[levels[next]][i];
        // 자식 노드 기준에 맞는지 확인 후 생성
        if(left<=temp->x && temp->x<=mid) {
            now->left = temp;
            make_tree(temp, left, mid, next+1);
        }
        if(mid<=temp->x && temp->x<=right) {
            now->right = temp;
            make_tree(temp, mid, right, next+1);
        }
    }
    
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    for(int i=0; i<nodeinfo.size(); i++) {
        node temp;
        temp.x = nodeinfo[i][0];
        temp.y = nodeinfo[i][1];
        temp.num = i+1;
        temp.left = temp.right = NULL;
        
        table[temp.y].push_back(temp);
    }
    // 트리의 y좌표, 즉 level의 인덱스를 내림차순으로 정렬
    for(auto i=table.begin(); i!=table.end(); i++)
        levels.push_back(i->first);
    sort(levels.begin(), levels.end());
    reverse(levels.begin(), levels.end());
    
    root = &table[levels[0]][0];
    make_tree(root, 0, 100000, 1);
    
    preorder_traverse(root);
    postorder_traverse(root);
    
    vector<vector<int>> answer;
    answer.push_back(preorder);
    answer.push_back(postorder);
    
    return answer;
}
