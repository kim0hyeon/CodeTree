#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
    
    Node(int n) : data(n), prev(nullptr), next(nullptr) {}
};

void NodePop(Node *node){
    if (node->prev != nullptr)
        node->prev->next = node->next;
    if (node->next != nullptr)
        node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
}

void InsertNext(Node *node, Node *new_node){
    Node *tmp = node->next;
    node->next = new_node;
    new_node->prev = node;

    if (tmp != nullptr){
        new_node->next = tmp;
        tmp->prev = new_node;
    }
}

void InsertPrev(Node *node, Node *new_node){
    Node *tmp = node->prev;
    node->prev = new_node;
    new_node->next = node;

    if (tmp != nullptr){
        new_node->prev = tmp;
        tmp->next = new_node;
    }
}



int main(){
    int n;
    cin >> n;
    unordered_map<int, Node*> nodes;

    // n개의 단일 노드 만들기
    for (int i = 1; i <= n; i++){
        nodes[i] = new Node(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int cmd, cur;
        cin >> cmd >> cur;

        if (cmd == 1){
            NodePop(nodes[cur]);
        } else if (cmd == 2){
            int a;
            cin >> a;
            InsertPrev(nodes[cur], nodes[a]);
        } else if (cmd == 3){
            int a;
            cin >> a;
            InsertNext(nodes[cur], nodes[a]);
        } else{
            int left, right;
            nodes[cur]->prev == nullptr ? left = 0 : left = nodes[cur]->prev->data;
            nodes[cur]->next == nullptr ? right = 0 : right = nodes[cur]->next->data;

            cout << left << " " << right << endl;
        }
    }


    for (int i = 1; i <= n; i++){
        if (nodes[i]->next == nullptr)
            cout << 0 << " ";
        else
            cout << nodes[i]->next->data << " ";
    }


    return 0;
}