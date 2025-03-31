// n번째로 적히는 숫자. 숫자가 얼마나 들어가는지 확인해야하는데...
// 그냥 코드 적게되면 무조건 시간초과 발생할것이고... 이걸 어떻게 이진탐색을 이용하지?
// 해당 숫자까지 3이나 5의 개수를 알아야 하는것 아닌감?
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;

    // 해당 숫자까지 3이 나타난 개수는 n/3으로 알 수 있고
    // 해당 숫자까지 5가 나타난 개수는 n/5로 알 수 있다.
    // 또 해당 숫자까지 15가 나타난 개수는 n/15로 알 수 있으니.
    // 해당 숫자까지 숫자가 나타난 개수는 (해당숫자 - 해당숫자/3 - 해당숫자/5 + 해당숫자/15) 이렇게 구할 수 있다.
    // 이걸 이진탐색으로 구하면 될것같은데... left는 1로 한다고 하면 right의 초기값은 어떻게 설정해야하지?

    int left = 1;
    int right = n*2;
    int ans = 0;

    while (left <= right){
        int mid = (left + right) / 2;
        int count = mid - mid/3 - mid/5 + mid/15;

        if (count == n && (mid%3 > 0 && mid%5 > 0 && mid%15 > 0)){ // 이게 되더라도 mid가 3의 배수이거나, 5의 배수, 15의 배수인 경우는 제외해야한다. 그러면 어떻게?
            cout << mid;
            break;
        } else if (count >= n){
            right = mid-1;
        } else{
            left = mid+1;
        }
        
    }


    return 0;
}