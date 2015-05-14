#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
const int MAX =20;
char s[MAX];
int ans[MAX];
int anspre[MAX];
int ansmiddle[MAX];
int ansafter[MAX];
int n=0;


typedef struct node{
    int have_value;
    int v;
    struct node *left,*right;
}Node;

Node* newnode(){
    Node* u=(Node*)malloc(sizeof(Node));
    if(u!=NULL)
    {
        u->have_value=0;
        u->left=u->right=NULL;
    }
    return u;
}

void addnode(int v,char* s,Node* root){
    int n=sizeof (s);
    Node* u=root;
    for(int i=0;i<n;i++){
        if (s[i]=='L') {
            if(u->left==NULL)u->left=newnode();
            u=u->left;
        }else if(s[i]=='R'){
            if(u->right==NULL)u->right=newnode();
            u=u->right;
        }
    }
    u->v=v;
    u->have_value=1;
}

void cengci(Node* root){
    Node* q0[MAX];
    q0[0]=root;
    int front=0,rear=1;
    while (front<rear){
        Node* u=q0[front++];
        if(!u->have_value)break;
        
        ans[n++]=u->v;
        if(u->left!=NULL){q0[rear++]=u->left;}
        if(u->right!=NULL){q0[rear++]=u->right;}
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }
}


void Preorder(Node * t){
    if(t){
        printf("%d ",t->v);
        Preorder(t->left);
        Preorder(t->right);
    }
}
void Inorder(Node * t)
{
    if(t){
        Inorder(t->left);
        printf("%d ",t->v);
        Inorder(t->right);
    }
}
void PostOrder(Node * t){
    if(t){
        PostOrder(t->right);
        PostOrder(t->left);
        printf("%d ",t->v);
    }
}

void NRPreOrder(Node * root){
    stack<Node*> s;
    Node * q=root;
    while(q||!s.empty()){
        while(q){
            printf("%d ",q->v);
            s.push(q);
            q=q->left;
        }
        if (!s.empty())
        {
            q=s.top();
            s.pop();
            q=q->right;
        }
    }
}


int get_input(){
    Node* root=newnode();
    for(;;)
    {
        if(scanf("%s",s)!=1)return 0;
        if(!strcmp(s,"()"))break;
        int v=0;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1,root);
    }
    Preorder(root);
    printf("\n");
    NRPreOrder(root);
//  Inorder(root);
//  printf("\n");
//  PostOrder(root);
    return 1;
}

int main(){
    
    get_input();
    return 0;
}