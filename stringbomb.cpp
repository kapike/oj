#include<stdio.h>

int main(){
  char first;
  char second;
  char third;
  int count = 0;
  while(scanf("%c",&first)!=EOF){
    if(first!= 'B' || first!='A')
      continue;
    if(count == 0){
      count++;
    }else if(first == 'B'){
      count--;
    }else if(first == 'A'){
      count++;
    }
    printf("%c %d %d\n",first,first,count);
  }

  printf("%d\n",count);
  return 0;
}
