#include<stdio.h>
#include<vector>
#include<algorithm>
long long  mymax(long long a, long long b, long long c){
  return a>b ? (a>c? a: c) : (b>c ? b:c);
}

int main(){
  long long  t;
  int i = 0;
  long long maxres;
  long long lastsmax;
  long long thissmax;
  long long lastf1;
  long long thisf1;
  long long lastf2;
  long long thisf2;
  long long tmp;
  while(scanf("%lld",&t)!=EOF){
    if(i==0){
      thisf1 = t;
      thisf2 = t;
      thissmax = t;
      maxres = t;
    }else{
      lastf1 = thisf1;
      lastf2 = thisf2;
      lastsmax = thissmax;
      tmp = lastf2+t;
      if(lastf2 <0 && t<0 && tmp>=0){
        tmp = -9223372036854775807;
      }
      thissmax = lastsmax>0 ? lastsmax+t : t;
      thisf1 = mymax(tmp,thissmax,thissmax);
      thisf2 = mymax(tmp, lastsmax,thissmax);
      if(thisf1 > maxres){
        maxres = thisf1;
      } 
    }
    i++;
  }
  printf("%lld\n",maxres);
  return 0;
}


