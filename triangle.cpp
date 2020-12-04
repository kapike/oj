#include <stdio.h>
#include <algorithm>
int main(){
  int n;
  scanf("%d",&n);
  long long *data = new long long int[n];
  int i = 0;
  while(i<n){
    scanf("%lld",data+i);
    i++;
  }
  std::sort(data,data+n);
  bool flag = false;
  for(i=0;i<n-2;i++){
    if(data[i]+data[i+1]>data[i+2]){
      flag = true;
      break;
    }
  }
  if(flag){
    printf("%s","YES");
  }else{
    printf("%s","NO");
  }
  return 0;
}
