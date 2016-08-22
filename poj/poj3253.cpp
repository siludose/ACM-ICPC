#include <iostream>
using namespace std;
long long n,i,ans,p[20001];
void heap(long x,long y)
{
  long i,j,temp;
  temp=p[x];
  i=x;
  j=i*2;
  while(j<=y)
  {
    if(j<y&&p[j+1]<p[j])
      j++;
    if(temp>p[j])
    {
      p[i]=p[j];
      i=j;
      j=i*2;             
    }       
    else
      break;    
  }     
  p[i]=temp;
}
int main()
{
  cin>>n;
  ans=0;
  for(i=1;i<=n;i++)
    cin>>p[i];
  for(i=n/2;i>=1;i--)
    heap(i,n);
  while(n>1)
  {
    p[0]=p[1];
    p[1]=p[n--];
    heap(1,n);
    p[1]+=p[0];
    ans+=p[1];
    heap(1,n);          
  }  
  cout<<ans<<endl;
  return 0;
}