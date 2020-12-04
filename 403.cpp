#include<stdio.h>
#include<set>
#include<map>
using namespace std;
int main(){

  int n ;
  unsigned  *data;
  scanf("%d",&n);
  data = new unsigned[n]; 
  map<unsigned, set<unsigned> > decison;
  

  unsigned step;
  for(int i=0;i<n;i++){
    scanf("%u",&step);
    data[i] = step;
    decison[step] = set<unsigned>(); 
  }
  decison[data[0]].insert(0);
  
  for(int s = 0; s<n-1; s++){
    if(decison[data[s]].size()!=0){
       for(auto it : decison[data[s]]){
         for(int i =-1; i<2; i++)
           if(it+i<=data[n-1] && it+i>=data[0] &&it+i>0 ) 
            decison[data[s]+it+i].insert(it+i);
       }
    }
  }
  if(decison[data[n-1]].size()!=0){
    printf("true\n");
  }else{
    printf("false\n");
  }

  return 0;
}
