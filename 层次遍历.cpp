#include <stdlib.h>
#include <stdio.h>
char s[20];

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
    int failed=0;
    int n=strlen(s);
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
int kann(Node* node)
{
    if(node!=NULL)return 1;
    return 0;
}
int ans[20];
int n=0;
void print_tree(Node* root){
    Node* q[20];
    q[0]=root;
    int front=0,rear=1;
    while (front<rear){
        Node* u=q[front++];
        if(!u->have_value)break;
        
        ans[n++]=u->v;
        if(u->left!=NULL){q[rear++]=u->left;}
        if(u->right!=NULL){q[rear++]=u->right;}
    }
    
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
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
    print_tree(root);
    return 1;
}

int main(){
    
    get_input();
    return 0;
}