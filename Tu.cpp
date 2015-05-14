
#include <stdlib.h> 
#include <stdio.h>

const int MAX=8;
int mat[MAX][MAX];
int vis[MAX][MAX];

void dij(int x,int y)
{
    if(!mat[x][y]||vis[x][y])return;
    vis[x][y]=1;
    dij(x-1,y-1);dij(x-1,y);dij(x-1,y+1);
    dij(x,y-1);             dij(x,y+1);
    dij(x+1,y-1);dij(x+1,y);dij(x+1,y+1);
}
int main(void)
{
    int n;
    scanf("%d",&n);
    char s[MAX];
    for(int i=0;i<n;i++){
        scanf("%s",s);
        for (int j=0;j<n;j++){
            mat[i+1][j+1]=s[j]-'0';
        }
    }
    for(int i=0;i<n+2;i++){
        for (int j=0;j<n+2;j++){
            printf("%d ",mat[i][j]);}
        printf("\n");
    }
    int count =0;
    for(int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if(mat[i][j]&&!vis[i][j]){count++;dij(i,j);}
        }
    }
    printf("the number is:%d",count);
    return 0;
}