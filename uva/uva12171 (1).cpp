// UVa12171 Sculpture
// Rujia Liu
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 50 + 5;
const int maxc = 1000 + 1;

// original data
int n, x0[maxn], y0[maxn], z0[maxn], x1[maxn], y1[maxn], z1[maxn];

// discretization related
int nx, ny, nz;
int xs[maxn*2], ys[maxn*2], zs[maxn*2];

// floodfill related
const int dx[] = {1,-1,0,0,0,0};
const int dy[] = {0,0,1,-1,0,0};
const int dz[] = {0,0,0,0,1,-1};
int color[maxn*2][maxn*2][maxn*2];

struct Cell {
  int x, y, z;
  Cell(int x=0, int y=0, int z=0):x(x),y(y),z(z){}
  bool valid() const {
    return x >= 0 && x < nx-1 && y >= 0 && y < ny-1 && z >= 0 && z < nz-1;
  }
  bool solid() const {
    return color[x][y][z] == 1; // solid
  }
  bool getVis() const {
    return color[x][y][z] == 2; // visited
  }
  void setVis() const {
    color[x][y][z] = 2;
  }
  Cell neighbor(int dir) const {
    return Cell(x+dx[dir], y+dy[dir], z+dz[dir]);
  }
  int volume() const {
    return (xs[x+1]-xs[x])*(ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
  }
  int area(int dir) const {
    if(dx[dir] != 0) return (ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
    else if(dy[dir] != 0) return (xs[x+1]-xs[x])*(zs[z+1]-zs[z]);
    return (xs[x+1]-xs[x])*(ys[y+1]-ys[y]);
  }
};

void discretize(int* x, int& n) {
  sort(x, x+n);
  n = unique(x, x+n) - x;
}

int ID(int* x, int n, int x0) {
  return lower_bound(x, x + n, x0) - x;
}

void floodfill(int& v, int& s) {
  v = 0;
  s = 0;
  Cell c;
  c.setVis();
  queue<Cell> q;
  q.push(c);
  while(!q.empty()) {
    Cell c = q.front(); q.pop();
    v += c.volume();
    for(int i = 0; i < 6; i++) {
      Cell c2 = c.neighbor(i);
      if(!c2.valid()) continue;
      if(c2.solid()) s += c.area(i);
      else if(!c2.getVis()){
        c2.setVis();
        q.push(c2);
      }
    }
  }
  v = maxc*maxc*maxc - v;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    nx = ny = nz = 2;
    xs[0] = ys[0] = zs[0] = 0;
    xs[1] = ys[1] = zs[1] = maxc;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
      x1[i] += x0[i]; y1[i] += y0[i]; z1[i] += z0[i];
      xs[nx++] = x0[i]; xs[nx++] = x1[i];
      ys[ny++] = y0[i]; ys[ny++] = y1[i];
      zs[nz++] = z0[i]; zs[nz++] = z1[i];
    }
    discretize(xs, nx);
    discretize(ys, ny);
    discretize(zs, nz);

    // paint
    memset(color, 0, sizeof(color));
    for(int i = 0; i < n; i++) {
      int X1 = ID(xs, nx, x0[i]), X2 = ID(xs, nx, x1[i]);
      int Y1 = ID(ys, ny, y0[i]), Y2 = ID(ys, ny, y1[i]);
      int Z1 = ID(zs, nz, z0[i]), Z2 = ID(zs, nz, z1[i]);
      for(int X = X1; X < X2; X++)
        for(int Y = Y1; Y < Y2; Y++)
          for(int Z = Z1; Z < Z2; Z++)
            color[X][Y][Z] = 1;
    }

    int v, s;
    floodfill(v, s);
    printf("%d %d\n", s, v);
  }

  return 0;
}



























#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>

using namespace std;

const int u[6]={0,0,0,0,1,-1};
const int v[6]={1,-1,0,0,0,0};
const int w[6]={0,0,1,-1,0,0};

struct rec{
    int x1,y1,z1,x2,y2,z2;
};

struct POINT{
    int x,y,z;
};

bool vis[103][103][103];
bool loc[103][103][103];
int n,T,ans1,ans2;
int x[103],y[103],z[103];
rec p[103];
int numx,numy,numz;

int IDX(int aim){
    return lower_bound(x,x+numx,aim)-x;
}

int IDY(int aim){
    return lower_bound(y,y+numy,aim)-y;
}

int IDZ(int aim){
    return lower_bound(z,z+numz,aim)-z;
}

int solve(int flag,int nowx,int nowy,int nowz){//计算表面积
    if (flag==0) return (x[nowx+1]-x[nowx])*(z[nowz+1]-z[nowz]);
    if (flag==1) return (x[nowx+1]-x[nowx])*(z[nowz+1]-z[nowz]);
    if (flag==2) return (x[nowx+1]-x[nowx])*(y[nowy+1]-y[nowy]);
    if (flag==3) return (x[nowx+1]-x[nowx])*(y[nowy+1]-y[nowy]);
    if (flag==4) return (z[nowz+1]-z[nowz])*(y[nowy+1]-y[nowy]);
    if (flag==5) return (z[nowz+1]-z[nowz])*(y[nowy+1]-y[nowy]);
    return -1;
}

void bfs(){
    queue<POINT> q;
    while (!q.empty()) q.pop();
    q.push((POINT){0,0,0});
    ans2=(x[1]-x[0])*(y[1]-y[0])*(z[1]-z[0]);
    vis[0][0][0]=1;
    while (!q.empty()){
            POINT now=q.front();
            q.pop();
            for (int i=0;i<6;i++){
                    int tx=now.x+u[i];
                    int ty=now.y+v[i];
                    int tz=now.z+w[i];
                    if (tx<0 || tx>=numx-1 || ty<0 || ty>=numy-1 || tz<0 || tz>=numz-1 || vis[tx][ty][tz]) continue;
                    if (loc[tx][ty][tz]){
                            ans1+=solve(i,now.x,now.y,now.z);
                    }
                    else{
                            ans2+=(x[tx+1]-x[tx])*(y[ty+1]-y[ty])*(z[tz+1]-z[tz]);
                            vis[tx][ty][tz]=1;
                            q.push((POINT){tx,ty,tz});
                    }
            }
    }
}

int main(){
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
            scanf("%d",&n);
            for (int i=0;i<n;i++){
                    scanf("%d%d%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].z1,&p[i].x2,&p[i].y2,&p[i].z2);
                    p[i].x2+=p[i].x1;
                    p[i].y2+=p[i].y1;
                    p[i].z2+=p[i].z1;
                    x[2*i+1]=p[i].x1;
                    x[2*i+2]=p[i].x2;
                    y[2*i+1]=p[i].y1;
                    y[2*i+2]=p[i].y2;
                    z[2*i+1]=p[i].z1;
                    z[2*i+2]=p[i].z2;//先把坐算出来
            }
            x[0]=0;
            y[0]=0;
            z[0]=0;
            x[2*n+1]=1001;
            y[2*n+1]=1001;
            z[2*n+1]=1001;//拓展范围
            sort(x,x+2*n+2);
            sort(y,y+2*n+2);
            sort(z,z+2*n+2);
            numx=unique(x,x+2*n+2)-x;
            numy=unique(y,y+2*n+2)-y;
            numz=unique(z,z+2*n+2)-z;//离散化
            memset(loc,0,sizeof(loc));
            memset(vis,0,sizeof(vis));
            for (int now=0;now<n;now++){
                    for (int i=IDX(p[now].x1);i<IDX(p[now].x2);i++){
                            for (int j=IDY(p[now].y1);j<IDY(p[now].y2);j++){
                                    for (int k=IDZ(p[now].z1);k<IDZ(p[now].z2);k++){
                                        loc[i][j][k]=1;//记录矩形位置
                                    }
                            }
                    }
            }
            ans1=0;//^2
            ans2=0;//^3
            bfs();
            ans2=x[numx-1]*y[numy-1]*z[numz-1]-ans2;//总体积减去空气体积
            printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
/*
1
2
1 2 3 3 4 5
6 2 3 3 4 5

1
7
1 1 1 5 5 1
1 1 10 5 5 1
1 1 2 1 4 8
2 1 2 4 1 8
5 2 2 1 4 8
1 5 2 4 1 8
3 3 4 1 1 1

2
2
1 2 3 3 4 5
6 2 3 3 4 5
7
1 1 1 5 5 1
1 1 10 5 5 1
1 1 2 1 4 8
2 1 2 4 1 8
5 2 2 1 4 8
1 5 2 4 1 8
3 3 4 1 1 1
*/