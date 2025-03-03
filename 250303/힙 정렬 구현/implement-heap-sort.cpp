#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int> &v, int n, int i){
    int largest = i;
    int l = i * 2;
    int r = i * 2 + 1;

    if (l <= n && v[l] > v[largest]) 
        largest = l;

    if (r <= n && v[r] > v[largest]) 
        largest = r;

    if (largest != i){
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heap_sort(vector<int> &v, int n){  // 함수 이름을 quick_sort에서 heap_sort로 변경했습니다.
    // max-heap 만들기
    for (int i = n/2; i >= 1; i--){
        heapify(v, n, i);
    }

    // max-heap을 만들었으면 정렬하기
    for (int i = n; i > 1; i--){
        swap(v[1], v[i]);
        heapify(v, i-1, 1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);  // 1-indexed로 사용

    // 올바른 인덱스(1부터 n까지)로 입력 받기
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    heap_sort(v, n);

    for (int i = 1; i <= n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
