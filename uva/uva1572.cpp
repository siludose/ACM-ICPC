#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

    int n;
    int g[60][60];
    int visit[60];

int dfs (int u){
    visit[u]=-1;
    if (u%2)
        u--;
    else u++;
    for (int i=0;i<52;i++)
        if (g[u][i]){
            if (visit[i]<0)
                return false ;
            else if (!visit[i]&&!dfs (i))
                return false ;
        }
    if (u%2) u--;else u++;
    visit[u]=1;
    return true ;
}

int topo (){
    for (int u=0;u<52;u++)
        if (!visit[u]&&!dfs (u))
            return false ;
    return true ;
}

int main (){
    while (~scanf ("%d",&n)){
        memset (visit,0,sizeof visit);
        memset (g,0,sizeof g);
        for (int i=0;i<n;i++){
            char s[10];
            scanf ("%s",s);
            for (int j=0;j<4;j++){
                if (s[j*2]=='0')
                    continue ;
                int tempj=(s[j*2]-'A')*2;
                //g[tempj][tempj+1]=g[tempj+1][tempj]=1;
                tempj+=s[j*2+1]=='+'?0:1;
                for (int o=j+1;o<4;o++){
                    if (s[o*2]=='0')
                        continue ;
                    int tempo=(s[o*2]-'A')*2;
                    tempo+=s[o*2+1]=='+'?0:1;
                    g[tempj][tempo]=g[tempo][tempj]=1;
                }
            }
        }
        //for (int i=0;i<52;i++){for (int j=0;j<52;j++){cout<<g[i][j];}cout<<endl;}
        if (topo ())
            printf ("bounded\n");
        else printf ("unbounded\n");
    }
    return 0;
}