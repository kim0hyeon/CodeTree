#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v, int start, int end){
    int pivot = v[end];
    int i = start - 1;

    for (int j = start; j < end; j++){
        if (v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i+1], v[end]);  // pivot과 경계에 있는 원소를 교환해 pivot 오른쪽엔 pivot보다 큰 원소들이 오도록 한다.

    return i+1;  // pivot의 최종 위치 반환
}

void quick_sort(vector<int> &v, int start, int end){
    if (start < end){
        int pos = partition(v, start, end);

        quick_sort(v, start, pos-1);
        quick_sort(v, pos+1, end);
    }


}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    quick_sort(v, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }


    return 0;
}