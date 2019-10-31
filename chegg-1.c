/*

INPUT:
XXXXX
X   X
X   X
X   X
XXXXX

OUTPUT:

 ░░░
 ░░░
 ░░░

Below is after recursive code execution.
∙∙∙∙∙
∙░░░∙
∙░░░∙
∙░░░∙
∙∙∙∙∙
Added Border.
+-----+
|∙∙∙∙∙|
|∙░░░∙|
|∙░░░∙|
|∙░░░∙|
|∙∙∙∙∙|
+-----+

*/

#include<stdio.h>
#define nl printf("\n")
#define N 78
#define M 21
int mp[N][M],vis[N][M]={0},mpp[N+2][M+2]={0};
char c;
void printmp(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
           if(mp[i][j]) printf(" ");
           else printf("%c",176);
        } nl;
    }
    return;
}
void ModifyPrint(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(mp[i][j]) printf("%c",249);
            else printf("%c",176);
        } nl;
    }
    return;
}
void ModifyPrint1(){
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            if((i==0 && j==0)||(i==N+1 && j==M+1)||(i==0 && j==M+1)||(i==N+1 && j==0))  printf("+");
            else if(i==0 || i==N+1) printf("-");
            else if(j==0 || j==M+1) printf("|");
            else if(mpp[i][j]) printf("%c",249);
            else printf("%c",176);
        } nl;
    }
    return;
}
int findEntry(){
    int x;
    for(int i=0;i<N;i++){
        if(mp[i][0]) {x=i; return x;} // found entrypoint.
    }
    return x;
}
void findPath(int x,int y){
    if(x<0 || y<0 || x>(N-1) || y>(M-1) || vis[x][y]) return;
    vis[x][y]=1; // TO AVOID MULTIPLE EXECUTION. (memoisation)
    if(mp[x][y]){
        mp[x][y]++; 
        findPath(x-1,y);
        findPath(x,y-1);
        findPath(x+1,y);
        findPath(x,y+1);
    }
    return;
}
void Read_Map(){
    // input from file.
    FILE *fpr; 
    fopen("yourfile.txt","r");
    printf("reading input from file..\n");
    int I=0,J=0;
    while((c=getc(fpr))!=EOF){
        if(c=='X') mp[I][J]=1;
        else mp[I][J]=0;
        if(I==(N-1) && J==(M-1)) break;  // end-of-file (or) end-of-map.
        if(I==(N-1)) I=0,J++;
        else I++;
    }
    printf("Reading file completed.\n");
    return;
}
void Border(){
    // adding border..
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            mpp[i+1][j+1]=mp[i][j];
        }
    }
    printf("Added Border.\n");
    ModifyPrint1();
    return;
}
int main(){
    // reading input from terminal.
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%c",&c);
            if(c=='X') mp[i][j]=1;
            else mp[i][j]=0;
        }
        scanf("%c",&c);
    }
                /*   (OR) use Read_Map method for reading input from file..)
                                    Read_Map(); */
    // driver.
    printmp();
    int x = findEntry(); 
    printf("Below is after recursive code execution.\n");
    findPath(x,0);
    ModifyPrint();
    Border();
    return 0;
}