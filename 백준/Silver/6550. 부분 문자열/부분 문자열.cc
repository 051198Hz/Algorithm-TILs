#include "iostream"

using namespace std;

//s의 0번째 문자열이 t의 0 - t.size()까지의 문자들 중 일치하는 것이 있는지 확인, 일치하면 cnt++, break
//일치 한다면, s의 1번째 문자열이 t의 1 - t.size()까지의 문자들 중 일치하는것이 있는지 확인, 일치하면 cnt++, break
//cnt가 1도 증가하지 않았으면 그즉시 break하여 NO 출력
//상기 과정을 s.size()까지 반복하여
//만난다면 break후 s의 i+1번째 문자열이 t의 j+m의 문

int main(){
    string s,t;
    while(cin>>s>>t){
        long j = 0;
        for(long i = 0; i < t.size(); i++){
            char tw = t[i];
            char sw = s[j];
            if(tw == sw){
                j++;
            }
            if(j == s.size()){
                cout<<"Yes\n";
                break;
            }
            if(i == t.size()-1){
                cout<<"No\n";
            }
        }
    }
    return 0;
}