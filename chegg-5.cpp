#include<bits/stdc++.h>
using namespace std;
int res[4]={0,0,0,0},c[4],n;
void greedy_change(int n){
    sort(c,c+4);
    int prev = 3;
    while(1){
        for(int i=prev;i>-1;i--){
            res[i] += (n/c[i]);
            n %= c[i];
        }
        if(n%c[0]) {
            if(res[1]) {res[1]--; n+=c[1]; prev=0;}
            else if(res[2]) {res[2]--; n+=c[2]; prev=1;}
            else {res[3]--; n+=c[3]; prev=2;}
            continue;
        } else break;
    }
    return;
}
int main(){
    for(int i=0;i<4;i++) cin>>c[i]; cin>>n;
    greedy_change(n);
    for(int i=0;i<4;i++) cout<<res[i]<<" ";
    return 0;
}