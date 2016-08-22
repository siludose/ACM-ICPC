    #include "stdio.h"  
    #include "math.h"  
    #include "string.h"  
    int mark[100][100],savex[1000],savey[1000],minx[1000],miny[1000];  
    int count,thex,they,lenmin,tag,cur,n,flag;  
    int dir[16]={2,1,2,-1,1,2,1,-2,-2,1,-2,-1,-1,2,-1,-2};  
    void DFS(int x,int y,int cur)  
    {  
        int i;  
        if(x==thex&&y==they)  
        {  
            flag=1;tag=1;  
        //  count++;  
        //  printf("(%d,%d)",savex[0],savey[0]);  
        //  for(i=1;i<cur;i++)  
        //  printf("->(%d,%d)",savex[i],savey[i]);  
        //  printf("%d/n",count);  
            if(cur<lenmin)   
            {  
                lenmin=cur;  
                for(i=0;i<lenmin;i++) {minx[i]=savex[i];miny[i]=savey[i];}  
            }  
        }  
        else  
        {  
            for(i=0;i<8;i++)  
            if(x+dir[2*i]>=0&&x+dir[2*i]<=n-1&&y+dir[2*i+1]>=0&&y+dir[2*i+1]<=n-1&&!mark[x+dir[2*i]][y+dir[2*i+1]])  
            {  
                mark[x+dir[2*i]][y+dir[2*i+1]]=1;  
                savex[cur]=x+dir[2*i];savey[cur]=y+dir[2*i+1];  
                DFS(x+dir[2*i],y+dir[2*i+1],cur+1);  
                mark[x+dir[2*i]][y+dir[2*i+1]]=0;  
            }         
        }  
    }  
    int main()  
    {  
        int i,j,a,b;  
        while(scanf("%d %d %d %d %d",&n,&a,&b,&thex,&they)!=EOF)  
        {  
            flag=0;count=0;lenmin=99999;tag=0;  
      
            memset(mark,0,sizeof(mark));  
            memset(savex,0,sizeof(savex));  
            memset(savey,0,sizeof(savey));  
            savex[0]=a;savey[0]=b;  
            mark[a][b]=1;  
            DFS(a,b,1);  
            if(flag==0) printf("N0 way/n");  
            else   
            {  
                printf("minRode=%d/n",lenmin-1);  
                printf("(%d,%d)",minx[0],miny[0]);  
                for(i=1;i<lenmin;i++)  
                printf("->(%d,%d)",minx[i],miny[i]);  
                printf("/n");  
            }  
        }  
        return 0;  
    }  
