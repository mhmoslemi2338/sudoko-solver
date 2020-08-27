#include <stdio.h>
#include <windows.h> 


int show(int);
int ifsquere(int,int,int);
int ifrow(int,int,int);
int ifcolomn(int,int,int);

int sdk1[9][9]={
7,0,0,0,0,0,2,0,0,
4,0,2,0,0,0,0,0,3,
0,0,0,2,0,1,0,0,0,
3,0,0,1,8,0,0,9,7,
0,0,9,0,7,0,6,0,0,
6,5,0,0,3,2,0,0,1,
0,0,0,4,0,9,0,0,0,
5,0,0,0,0,0,1,0,6,
0,0,6,0,0,0,0,0,8
};
int sdk[9][9]={
0,0,2,5,0,0,8,0,4,
0,0,1,0,0,0,0,0,0,
4,0,0,8,0,0,0,0,0,
0,1,0,0,0,9,3,8,0,
0,3,6,0,0,0,0,7,0,
0,0,4,0,3,0,0,0,0,
0,0,0,0,0,6,0,0,0,
0,0,0,3,4,0,0,0,1,
6,7,0,0,0,0,0,0,9
};

int sdk_[9][9]={
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0
};


int solve(int x,int y){
	int num=1;
	int tmp_x=0;
	int tmp_y=0;
	
	if(sdk[x][y]!=0){
		if(x==8 && y==8){ return 1;}
		if(x<8) {x++;}
		else{
			x=0;
			y++;
		}
		if(solve(x,y)) return 1;
		return 0;	
	}
	
	
	if(sdk[x][y]==0){
		while(num<10){
			if(!ifsquere(x,y,num) && !ifrow(x,y,num) && !ifcolomn(x,y,num)){
				sdk[x][y]=num;

				if(x==8 && y==8) return 1;
				if(x<8) tmp_x=x+1;
				else{
					tmp_x=0;
					tmp_y=y+1;
				}
				if(solve(tmp_x,tmp_y)) return 1;	
			}
			num++;
		}
		sdk[x][y]=0;
		return 0;
	}
}
		


int main(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			sdk_[i][j]=sdk[i][j];
		}
	}
	
	int x=0;
	int y=0;
	
	show(0);
	solve(x,y);
	x=show(1);
	if(x==1) printf("NO SOLUTION FOUND\n\n");
	getchar();
return 0;
}









int ifcolomn(int x,int y,int num){
	int i;
	for(i=0;i<9;i++)
		if(num==sdk[x][i]) return 1;
	return 0;
}
int ifrow(int x,int y,int num){
	int i;
	for(i=0;i<9;i++)
		if(num==sdk[i][y]) return 1;
	return 0;
}
int ifsquere(int x,int y,int num){
	int i,j;
	
	if(x<3) x=0;
	else if(x<6) x=3;
	else x=6;
	
	if(y<3) y=0;
	else if(y<6) y=3;
	else y=6;
	
	for(i=x;i<x+3;i++)
		for(j=y;j<y+3;j++)
			if(num==sdk[i][j]) return 1;
	return 0;
}



int show(int color){
	
	
	HANDLE  hConsole;
	int L;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	

	int i,j;
	int k=0;
	printf(" ");
	for(j=0;j<9;j++) printf("----");
	printf("\n");
	for(i=0;i<9;i++){
		printf(" | ");
		for(j=0;j<9;j++){
			if(sdk[i][j]==0) {
				printf("- | ");
				k=1;
			}
			else {
				if(color==1){
					if(sdk_[i][j]==0){
						L=2;
		    			SetConsoleTextAttribute(hConsole, L);
						printf("%d",sdk[i][j]);
						L=7;
						SetConsoleTextAttribute(hConsole, L);
					}
					else printf("%d",sdk[i][j]);
				}
				
				else printf("%d",sdk[i][j]);
				printf(" | ");
			}
		}	
		printf("\n");
	}
	printf(" ");
	for(j=0;j<9;j++) printf("----");
	printf("\n\n");
	if(k==1) return 1;
	return 0;
}
	
	
