#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* next;
};
struct node *top = NULL;
void push (int v){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = v; newNode->next = top;
    top = newNode;
    return;
}
int pop(){
    int t=-1;
    if(top==NULL){
        // printf("Stack is empty\n");
    }else {
        struct node *tp = top;
        top = top->next;
        t = tp->val; free(tp);
    }
    return t;
}
bool isEmpty(){
    return (top == NULL);
}
void postfix(char a[],int n){
    int i=0,c,d;
    while(i<n){
        if(a[i]=='+') { c=pop(), d=pop(); if(d==-1){printf("Invalid");return;} push(c+d); i++;}
        else if(a[i]=='-') {c=pop(), d=pop(); if(d==-1){printf("Invalid");return;} push(c-d); i++;}
        else if(a[i]=='/') {c=pop(), d=pop(); if(d==-1){printf("Invalid");return;} push(c/d); i++;}
        else if(a[i]=='*') {c=pop(), d=pop(); if(d==-1){printf("Invalid");return;} push(c*d); i++;}
        else if(a[i]==' ') i++;
        else{
            int b=0;
            while(a[i]!=' '){
                b*=10; b+=((int)a[i]-48);
                i++;
            }    
            if(b) push(b);
        }
    }
    c = pop(); d = pop();
    if(d==-1 && c!=-1) printf("RESULT = %d",c);
    else printf("Invalid arguments, check...");
    return;
}
int main(){
    char a[30]; int n;
    for(int i=0;i<20;i++){
        scanf("%c",&a[i]); 
        if(a[i]=='\n') {n=i; break;}
    }
    postfix(a,n);
    return 0;
}