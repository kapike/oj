#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int mymax(int a, int b, int c){
  return a>b ? (a>c? a: c) : (b>c ? b:c);
}

int main(){
  short t;
  vector<short> data;
  while(scanf("%hd",&t)!=EOF){
    data.push_back(t);
  }
  int n = data.size();
  short f1[n];
  short f2[n];
  short smax[n];
  
  f1[0] = data[0];
  f2[0] = data[0];
  smax[0] = data[0];
  short maxresult = data[0];
  
  int tmp ;
  for(int i=1; i<n; i++){
    smax[i] = smax[i-1]>0 ? smax[i-1]+data[i] : data[i];
    f1[i] = mymax(data[i]+f2[i-1],smax[i],smax[i]);
    f2[i] = mymax(data[i]+f2[i-1],smax[i],smax[i-1]);
    if(maxresult < f1[i]){
      maxresult = f1[i];  
    }
  }
  printf("%d\n",maxresult);
  return 0;
}


