#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int x);
void splitNum(int x, int num[]);
int main(int argc, char *argv[]) {
//	freopen("","r",stdin);
	int sum=0,psum=0,num[11];
	double aver=0,n=0;
	for(int i=101;i<=9999;i++){
		if(isPrime(i)){
			splitNum(i,num);
			sum=0,psum=0;
			for(int j=1;j<=num[0];j++)sum+=num[j],psum+=num[j]*num[j];
			if(isPrime(sum)&&isPrime(psum)){
				aver+=i,n++;
				printf("%d ",i);
			}
		}
	}
	aver/=n;
	printf("%lf",aver);
	return 0;
}
bool isPrime(int x){
	if(x==1)return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)return 0;
	return 1;
}
void splitNum(int x,int num[]){
	num[0]=0;
	while(x){
		num[++num[0]]=x%10;
		x/=10;
	}
	return ;
}
//超级素数：它本身，各位数字的和，各位数字的平方和，都是素数。
//求 100~10000 内的所有超级素数，及它们的平均数。
// 2021-10-29
