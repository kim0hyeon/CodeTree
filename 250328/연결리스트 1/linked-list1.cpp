#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node *prev, *next;

    Node(string s) : data(s), prev(nullptr), next(nullptr) {}
};

void insertNext(Node *node, Node *new_node){
    Node *tmp = node->next;

    node->next = new_node;
    new_node->prev = node;

    if (tmp != nullptr){
        tmp->prev = new_node;
        new_node->next = tmp;
    }
}

void insertPrev(Node *node, Node *new_node){
    Node *tmp = node->prev;

    node->prev = new_node;
    new_node->next = node;

    if (tmp != nullptr){
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

void printNode(Node *cur){
    if (cur->next == nullptr && cur->prev == nullptr){
        cout << "(Null)" << " " << cur->data << " " << "(Null)" << endl;
    } else if (cur->next == nullptr){
        cout << cur->prev->data << " " << cur->data << " " << "(Null)" << endl;
    } else if (cur->prev == nullptr){
            cout << "(Null)" << " " << cur->data << " " << cur->next->data << endl;
    } else {
        cout << cur->prev->data << " " << cur->data << " " << cur->next->data << endl;
    }
}


int main(){
    string s_init;
    cin >> s_init;
    int n;
    cin >> n;

    Node *cur = new Node(s_init);

    for (int i = 0; i < n; i++){
        int cmd;
        cin >> cmd;

        if (cmd == 1){
            string s_value;
            cin >> s_value;
            Node *new_node = new Node(s_value);
            insertPrev(cur, new_node);
        } else if (cmd == 2){
            string s_value;
            cin >> s_value;
            Node *new_node = new Node(s_value);
            insertNext(cur, new_node);
        } else if (cmd == 3 && cur->prev != nullptr){
            cur = cur->prev;
        } else if (cmd == 4 && cur->next != nullptr){
            cur = cur->next;
        }

        printNode(cur);

    }

    return 0;
}