#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long mymax(long long a, long long b, long long c){
  return a>b ? (a>c? a: c) : (b>c ? b:c);
}

int main(){
  long long  t;
  int  i = 0;
  long long maxres;
  long long lastsmax;
  long long thissmax;
  long long lastf1;
  long long thisf1;
  long long lastf2;
  long long thisf2;
  long long tmp;
  long long tmp2;
  while(scanf("%lld",&t)!=EOF){
    if(i==0){
      thisf1 = t;
      thisf2 = t;
      thissmax = t;
      maxres = t;
      i++;
    }else{
      lastf1 = thisf1;
      lastf2 = thisf2;
      lastsmax = thissmax;
      tmp = lastf2+t;
      tmp2 = lastsmax + t;
      if(lastf2 <0 && t<0 && tmp>=0){
        tmp = -9223372036854775807;
      }
      if(lastsmax <0 && t<0 && tmp2>=0){
        tmp2 = -9223372036854775807;
      }
      thissmax = lastsmax>0 ? tmp2 : t;
      thisf2 = max(tmp, lastsmax);
      thisf1 = max(thisf2,thissmax);
      if(thisf1 > maxres){
        maxres = thisf1;
      } 
    }
  }
  printf("%lld\n",maxres);
  return 0;
}


