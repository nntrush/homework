#include <stdio.h>
#include <stdlib.h>
int sz[1001][1001];
int swz[1001];
int X,Y;
void read(){

	scanf("%d %d",&X,&Y);
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++){
			scanf("%d",&sz[i][j]);
		}
	}
	return ;
}
void swap_R(int x,int y){
	for(int j=1;j<=Y;j++)swz[j]=sz[x][j];
	for(int j=1;j<=Y;j++)sz[x][j]=sz[y][j];
	for(int j=1;j<=Y;j++)sz[y][j]=swz[j];
	return ;
}
void swap_C(int x,int y){
	for(int i=1;i<=X;i++)swz[i]=sz[i][x];
	for(int i=1;i<=X;i++)sz[i][x]=sz[i][y];
	for(int i=1;i<=X;i++)sz[i][y]=swz[i];
	return ;
}
void insert_R(int x){
	X++;
	for(int i=X;i>x;i--)for(int j=1;j<=Y;j++)sz[i][j]=sz[i-1][j];
	for(int j=1;j<=Y;j++)sz[x][j]=0;
	return ;
}
void insert_C(int y){
	Y++;
	for(int j=Y;j>y;j--)for(int i=1;i<=X;j++)sz[i][j]=sz[i][j-1];
	for(int i=1;i<=X;i++)sz[i][y]=0;
	return ;
}
void delete_R(int x){
	for(int i=x;i<X;i++)for(int j=1;j<=Y;j++)sz[i][j]=sz[i+1][j];
	X--;
	return ;
}
void delete_C(int y){
	for(int j=y;j<Y;j++)for(int i=1;i<=X;i++)sz[i][j]=sz[i][j+1];
	Y--;
	return ;
}
int main(int argc, char *argv[]) {
//	freopen("C.in","r",stdin);
	read();
	int n,x,y;
	char cmend[10];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&cmend);
		if(cmend[0]=='S'){
			scanf("%d %d",&x,&y);
			if(cmend[1]=='R')swap_R(x,y);
			else swap_C(x,y);
		}else if(cmend[0]=='I'){
			scanf("%d",&x);
			if(cmend[1]=='R')insert_R(x);
			else insert_C(x);
		}else{
			scanf("%d",&x);
			if(cmend[1]=='R')delete_R(x);
			else delete_C(x);
		}
/*	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++)printf("%d ",sz[i][j]);
		printf("\n");
	}	*/	
	}
	for(int i=1;i<=X;i++){
		for(int j=1;j<=Y;j++)printf("%d ",sz[i][j]);
		printf("\n");
	}
	return 0;
}
