#include <iostream>
#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    string s;
    unordered_map<string, int> umap;

    for (int i = 1; i <= n; i++){
        cin >> s;
        umap[s] = i;
    }

    // 정수나 문자열 중 하나를 받게 되는데 일단 string으로 받고 그 다음에 숫자가 되는지 확인해야하나?
    for (int i = 0; i < m; i++){
        string input;
        cin >> input;

        try{
            int num = stoi(input);
            for (auto &pair : umap){
                if (pair.second == num){
                    cout << pair.first << endl;
                    break;
                }
            }
        } catch (const invalid_argument& e){
            cout << umap[input] << endl;
        }
    }


    return 0;
}