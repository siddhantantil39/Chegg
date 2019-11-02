#include<stdio.h>
#include<string.h>
#define nl printf("\n")
struct Name{
    char nm[50];
    int wins,loses,ties;
}p[2];
int game=0,x,y;
int c[3][3]={-1};

void plays(int a){
    while(1){
        printf("%s, Enter Position: ",p[a].nm);
        scanf("%d %d",&x,&y);
        if(c[x][y]==-1) {c[x][y]=a; break;}
    }
    return;
}
void reset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            c[i][j]=-1;
        }
    }
    return;
}
void printA(){
    nl;
    printf("         ---------"); nl;
    for(int i=0;i<3;i++){
        printf("         ");
        for(int j=0;j<3;j++){
            printf("|"); //(c[i][j]) ? printf("O") : printf("X");
            if(c[i][j]==-1) printf(" ");
            else{
                (c[i][j]) ? printf("O") : printf("X");
            }
            printf("|");
        }nl;
        printf("         ---------"); nl;
    }
    nl;
    return;
}
int check(int a){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(c[i][j]!=a) break;
            if(j==2) { p[a].wins+=1; p[!a].loses+=1; return 1; }
        }
        for(int j=0;j<3;j++){
            if(c[j][i]!=a) break;
            if(j==2) { p[a].wins+=1; p[!a].loses+=1; return 1; }
        }
    }
    if(c[0][0]==a && c[0][0]==c[1][1] && c[1][1]==c[2][2]) { p[a].wins+=1; p[!a].loses+=1; return 1; }
    if(c[0][2]==a && c[0][2]==c[1][1] && c[1][1]==c[2][0]) { p[a].wins+=1; p[!a].loses+=1; return 1; }
    return 0;
}
void dispStat(){
    printf("Player-1: %s        Player-2: %s\n",p[0].nm,p[1].nm);
    printf("Wins %d             Wins %d\n",p[0].wins,p[1].wins);
    printf("Loses %d            Loses %d\n",p[0].loses,p[1].loses);
    printf("Draws %d            Draws %d\n",p[0].ties,p[1].ties); nl;
    return;
}
int main(){
    int n=0;
    printf("Enter your name Player-1: "); 
    scanf("%s",p[0].nm); p[0].wins=0; p[0].loses=0; p[0].ties=0;
    printf("\nEnter your name Player-2: "); 
    scanf("%s",p[1].nm); p[1].wins=0; p[1].loses=0; p[1].ties=0;
    nl;
    reset();
    while(game<5 && p[0].wins<=2 && p[1].wins<=2 ){
        dispStat();
        printf("*********** Game No. : %d ************",(game+1)); nl; nl; n=0;
        while(n<9){
        plays(0); 
        printA(); if(check(0)) {printf("Player-1 won the match..\n\n"); break;} n++;
        if(n>8) break;
        plays(1); 
        printA(); if(check(1)) {printf("Player-2 won the match..\n\n"); break;} n++;
        }
        reset();
        if(n==9) {p[0].ties++; p[1].ties++; printf("This game is a tie..\n\n"); }
        game++;
    }
    nl;
    dispStat();
    if(p[0].wins>2) printf("%s won the series..\n\n",p[0].nm);
    else if(p[1].wins>2) printf("%s won the series..\n\n",p[1].nm);
    else printf("Tough competition -- SERIES DRAW..\n\n");
    return 0;
}

/*
    0 0 0 1 1 1 0 3 2 2
*/