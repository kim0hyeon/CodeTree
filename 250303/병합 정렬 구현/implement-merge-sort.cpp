#include <iostream>

using namespace std;

int n;
int arr[100000];

void merge(int start, int mid, int end){
    int i = start, j = mid+1;
    int m_arr[end-start+1];
    int k = 0;

    while (i <= mid && j <= end){
        if (arr[i] < arr[j]){
            m_arr[k++] = arr[i++];
        } else{
            m_arr[k++] = arr[j++];
        }
    }

    while (i <= mid){
        m_arr[k++] = arr[i++];
    }

    while (j <= end){
        m_arr[k++] = arr[j++];
    }

    k = 0;
    for (i = start; i <= end; i++){
        arr[i] = m_arr[k++];
    }

}

void merge_sort(int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
}


int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    merge_sort(0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}