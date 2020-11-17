#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream> 
#include<cstring>  
#include<string>   
#include<iomanip>   
#include<algorithm>   
using namespace std;   
  
#define MAXN 9999  
#define MAXSIZE 10  
#define DLEN 4  
  
class BigNum  
{   
  private:   
    int a[500];    //可以控制大数的位数   
    int len;       //大数长度  
  public:   
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //构造函数  
    BigNum(const long long );       //将一个int类型的变量转化为大数  
    BigNum(const BigNum &);  //拷贝构造函数  
    BigNum &operator=(const BigNum &);   //重载赋值运算符，大数之间进行赋值运算  
  
  
    BigNum operator+(const BigNum &) const;   //重载加法运算符，两个大数之间的相加运算   
    BigNum operator-(const BigNum &) const;   //重载减法运算符，两个大数之间的相减运算   
  
    bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较  
  
    void print();       //输出大数  
};   
BigNum::BigNum(const long long  b)     //将一个int类型的变量转化为大数  
{   
    long long  c,d = b;  
    len = 0;  
    memset(a,0,sizeof(a));  
    while(d > MAXN)  
    {  
            c = d - (d / (MAXN + 1)) * (MAXN + 1);   
            d = d / (MAXN + 1);  
            a[len++] = c;  
        }  
    a[len++] = d;  
}


void BigNum::print()    //输出大数  
{   
    int i;     
    cout << a[len - 1];   
    for(i = len - 2 ; i >= 0 ; i--)  
    {   
            cout.width(DLEN);   
            cout.fill('0');   
            cout << a[i];   
        }   
    cout << endl;  
} 

bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较  
{   
    int ln;   
    if(len > T.len)  
        return true;   
    else if(len == T.len)  
    {   
            ln = len - 1;   
            while(a[ln] == T.a[ln] && ln >= 0)  
                ln--;   
            if(ln >= 0 && a[ln] > T.a[ln])  
                return true;   
            else  
                return false;   
        }   
    else  
        return false;   
} 
BigNum BigNum::operator+(const BigNum & T) const   //两个大数之间的相加运算  
{  
    BigNum t(*this);  
    int i,big;      //位数     
    big = T.len > len ? T.len : len;   
    for(i = 0 ; i < big ; i++)   
    {   
            t.a[i] +=T.a[i];   
            if(t.a[i] > MAXN)   
            {   
                        t.a[i + 1]++;   
                        t.a[i] -=MAXN+1;   
                    }   
        }   
    if(t.a[big] != 0)  
        t.len = big + 1;   
    else  
        t.len = big;     
    return t;  
}  
BigNum BigNum::operator-(const BigNum & T) const   //两个大数之间的相减运算   
{    
    int i,j,big;  
    bool flag;  
    BigNum t1,t2;  
    if(*this>T)  
    {  
            t1=*this;  
            t2=T;  
            flag=0;  
        }  
    else  
    {  
            t1=T;  
            t2=*this;  
            flag=1;  
        }  
    big=t1.len;  
    for(i = 0 ; i < big ; i++)  
    {  
            if(t1.a[i] < t2.a[i])  
            {   
                        j = i + 1;   
                        while(t1.a[j] == 0)  
                            j++;   
                        t1.a[j--]--;   
                        while(j > i)  
                            t1.a[j--] += MAXN;  
                        t1.a[i] += MAXN + 1 - t2.a[i];   
                    }   
            else  
                t1.a[i] -= t2.a[i];  
        }  
    t1.len = big;  
    while(t1.a[t1.len - 1] == 0 && t1.len > 1)  
    {  
            t1.len--;   
            big--;  
        }  
    if(flag)  
        t1.a[big-1]=0-t1.a[big-1];  
    return t1;   
}  
BigNum::BigNum(const BigNum & T) : len(T.len)  //拷贝构造函数  
{   
    int i;   
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)  
        a[i] = T.a[i];   
}   
BigNum & BigNum::operator=(const BigNum & n)   //重载赋值运算符，大数之间进行赋值运算  
{  
    int i;  
    len = n.len;  
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)   
        a[i] = n.a[i];   
    return *this;   
} 



BigNum & mymax(BigNum & a, BigNum & b, BigNum & c){
  return a>b ? (a>c? a: c) : (b>c ? b:c);
}

int main(){
  long long  t;
  long long i = 0;
  BigNum maxres;
  BigNum lastsmax;
  BigNum thissmax;
  BigNum  lastf1;
  BigNum thisf1;
  BigNum lastf2;
  BigNum thisf2;
  BigNum tmp;
  while(scanf("%lld",&t)!=EOF){
    if(i==0){
      thisf1 = BigNum(t);
      thisf2 = BigNum(t);
      thissmax = BigNum(t);
      maxres = BigNum(t);
    }else{
      lastf1 = thisf1;
      lastf2 = thisf2;
      lastsmax = thissmax;
      tmp = lastf2+t;
      thissmax = lastsmax>0 ? lastsmax+t : t;
      thisf1 = mymax(tmp,thissmax,thissmax);
      thisf2 = mymax(tmp, lastsmax,thissmax);
      if(thisf1 > maxres){
        maxres = thisf1;
      } 
    }
    i++;
  }
  maxres.print();
  return 0;
}


