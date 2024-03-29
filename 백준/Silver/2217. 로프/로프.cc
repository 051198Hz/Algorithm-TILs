#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
int*ropes;
bool compare(int a, int b){ //내림차순 정렬
    return a > b;
}
void input(){
    //입력으로 로프 개수, 각 로프의 최대 중량을 입력받는다
    cin>>n;
    ropes = new int[n];
    for(int i = 0; i<n; i++){
        cin>>ropes[i];
    }
}
void solution(){
    //figure
    //k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각 로프에는 w/k의 무게가 걸린다
    //모든 로프를 사용할 필요는 없지만, 이들 로프를 사용하여 들어올릴 수 있는 최대 중량을 구하시오.
    //try
    // 최대 중량이 각 10 15 인 로프가 있다고 하자.
    //모든 로프에는 w/k의 중량이 걸리지만, 각 로프가 견뎌낼 수 있는 중량은 정해져 있다.
    //따라서 최소 중량을 가진 로프에 w/k의 하한선이 걸리게 된다.
    // 1 1 1 일때
    // 로프 3개, 중량 합은 3, 각 로프에 걸리는 중량은 3/3 = 1. 최대 3의 중량을 견딜 수 있음
    // 10 9 8 7 6 5 4 3 2 1 의 로프가 있다고 하자
    //10일 때 10, 10 + 9 = 19, 19/2 = 9.5가 걸리게 되므로 9인 로프가 둘 수 없다. 최대 18
    //10 + 9 + 8 = 27, 27 / 3 = 9 이므로 8인 로프가 들 수 없다. 최대 24.
    //10 + 9 + 8 + 7 = 34,  / 4 = 8.5 이므로 7인 로프가 들 수 없다. 최대 28
    //10 + 9 + 8 + 7 + 6 = 40,  / 5 = 8 이므로 7인 로프가 들 수 없다. 최대 30
    //10 + 9 + 8 + 7 + 6 + 5 = 45,  / 6 = 7.5 이므로 7인 로프가 들 수 없다. 최대 30
    //10 + 9 + 8 + ... + 4 = 49,  / 7 = 7이므로 6인 로프가 들 수 없다. 최대 28
    //10 + 9 + 8 + ... + 4 + 3 = 52,  / 8 = 6.5 이므로 6인 로프가 들 수 없다. 최대 24
    //10 + 9 + .... + 3 + 2 = 54, /9 = 6, 8인 로프가 들 수 없다. 최대 18
    //따라서, 로프를 더하면 최대 중량이 증가하다, 어느순간 줄어드는것을 알 수 있다.
    //최대 중량 = 현재 로프 * (i+1) 을 저장.
    //다음 루프를 돌때, 이전 최대중량보다 현재 최대 중량이 작으면 break;
    // 10 10 10 일때
    // 10 = 10 / 1 = 10
    // 10 + 10  = 20 /2 = 10
    // 10 + 10 + 10 = 30 / 3 = 10
    //줄어들면 줄어든 전 값을 출력 후 종료.
    //solve
    //다음 케이스로 나뉜다.
    // 1. n+n+n....
    // 2. n + (n-a) + (n-b) + (n-c) + ...
    // 3. n + (n-a) + (n-a) + (n-c) + ..
    //10 10 10 10
    //10 + 10 = 20, /2 = 10
    //10 + 10 + 10 = 30, /3 = 10
    //3 3 3 10
    //10 = 10, 최대 10
    // 10 + 3 = 13,  /2 = 6.5,  최대 6
    // 10 + 3 + 3 = 16, /3 = 5.3, 최대 9
    // 10 + 3 + 3 + 3 = 19, /4 = 4.7, 최대 12
    // 10 + 3 + 3 + 3 + 2 = 21, /5 = 4.2, 최대 10
    // 10 + 3 + 3 + 3 + 2 + 2 = 23 / 6 = 3.8 최대 12
    // 10 + 3 + 3 + 3 + 2 + 2 + 2 = 25 / 7 = 3.5 최대 14
    // 같은 숫자가 계속되면 최대값이 늘어날 수 도 있으므로 모든 값을 검사해야함.
    sort(ropes, ropes+n, compare);
    int maxW = 0;
    for(int  i = 0; i<n; i++){
        int curMaxW = ropes[i] * (i+1);
        maxW = curMaxW > maxW ? curMaxW : maxW;
    }
    cout<<maxW;


}
int main(){
    fastio;
    input();
    solution();
    return 0;
}