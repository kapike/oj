#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int mymax(int a, int b, int c){
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
      thissmax = lastsmax>0 ? lastsmax+t : t;
      thisf1 = mymax(t+lastf2,thissmax,thissmax);
      thisf2 = mymax(t+lastf2, lastsmax,thissmax);
      if(thisf1 > maxres){
        maxres = thisf1;
      } 
    }
    i++;
  }
  printf("%lld\n",maxres);
  return 0;
}


