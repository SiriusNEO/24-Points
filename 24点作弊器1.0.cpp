//By Frank
#include<bits/stdc++.h>
using namespace std;
#define R register
#define N 6
#define eps 1e-8
double Num[5][5],Ans2[N][N];
char Ans1[N];
char B[1<<15],*S=B,*T=B;
bool key,ret1;
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?EOF:*S++)

template<class TT>inline void read(R TT &x){
	x=0;R bool f=0;R char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=(ch=='-');
	for(;ch>47&&ch<58;ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	(f)&&(x=-x);
}
int check(R double x)	//精度修正一个数的正负 
{
    if(x>-eps&&x<eps) return 0;
    return (x>0)?1:-1;
}
bool dfs(R int dep)
{
    if(dep==4)
	{
        if(check(Num[dep][1]-24.0)==0) 
		{
			/*
			for(R int i=1;i<=4;++i)
			{
				for(R int j=1;j<=4;++j)
				{
				printf("%.1lf ",Num[i][j]);
				}
				puts("\n");
			}
			*/
			if(!key)
			{
				for(R int i=1;i<4;++i) 
				{
					printf("%.1lf%c%.1lf=%.1lf\n",Ans2[i][1],Ans1[i],Ans2[i][2],Ans2[i][3]);
				}
			}
			return true;
		}
		return false;
    }
    R int Top = 0 ;
    for(R int i=1;i<4-dep+1;++i)
	{
		for(R int j=i+1;j<=4-dep+1;++j)
		{
			Top=0;for(R int k = 1; k<=4-dep+1; ++k)
                if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
            	Num[dep+1][++Top] = Num[dep][i]+Num[dep][j] ;
            	Ans1[dep]='+';
            	Ans2[dep][1]=Num[dep][i];
            	Ans2[dep][2]=Num[dep][j];
            	Ans2[dep][3]=Num[dep+1][Top];
            	if(dfs(dep+1)) return true;
            
            
            Top=0;for(R int k=1 ; k<=4-dep+1; ++k)
                if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
            	Num[dep+1][++Top] = Num[dep][i]-Num[dep][j] ;
            	Ans1[dep]='-';
				Ans2[dep][1]=Num[dep][i];
            	Ans2[dep][2]=Num[dep][j];
            	Ans2[dep][3]=Num[dep+1][Top];
				if(dfs(dep+1)) return true ;
            	
            Top=0;for(R int k=1 ; k<=4-dep+1 ; ++k)
                if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
            	Num[dep+1][++Top] = Num[dep][j]-Num[dep][i] ;
            	Ans1[dep]='-';
				Ans2[dep][1]=Num[dep][i];
            	Ans2[dep][2]=Num[dep][j];
            	Ans2[dep][3]=Num[dep+1][Top];
				if(dfs(dep+1)) return true;
            
			Top=0;for(R int k = 1 ; k<=4-dep+1 ; ++k)
                if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
            	Num[dep+1][++Top] = Num[dep][i]*Num[dep][j] ;
            	Ans1[dep]='*';
				Ans2[dep][1]=Num[dep][i];
            	Ans2[dep][2]=Num[dep][j];
            	Ans2[dep][3]=Num[dep+1][Top];
				if(dfs(dep+1)) return true;
            
            if(check(Num[dep][j] ))
			{
            	Top=0;for(R int k=1 ; k<=4-dep+1 ; ++k)
                	if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
                	Num[dep+1][++Top] = Num[dep][i]/Num[dep][j] ;
                	Ans1[dep]='/';
					Ans2[dep][1]=Num[dep][i];
            		Ans2[dep][2]=Num[dep][j];
            		Ans2[dep][3]=Num[dep+1][Top];
					if(dfs(dep+1)) return true;
            }
            
            if(check(Num[dep][i]))
			{
                Top=0;for(R int k=1 ; k<=4-dep+1 ; ++k)
                	if(k^i && k^j) Num[dep+1][++Top] = Num[dep][k] ;
                	Num[dep+1][++Top] = Num[dep][j]/Num[dep][i] ;
                	Ans1[dep]='/';
					Ans2[dep][1]=Num[dep][i];
            		Ans2[dep][2]=Num[dep][j];
            		Ans2[dep][3]=Num[dep+1][Top];
					if(dfs(dep+1)) return true;
            }
        }
    }
    return false;
}
void subtask1()  //解题 
{
	key=0;
	for(R int i=1;i<=4;++i)
	{
		scanf("%lf",&Num[1][i]);
		if(Num[1][i] < 0) 
		{
			ret1=1;
			return;
		}
	}
		if(dfs(1)) 
		{
			puts("Yes.");
			return ;
		}
	puts("No.");
}
void subtask2()	//出题 
{
	key=1;
	R int lim;
	scanf("%d",&lim);
	while(1)
	{
		for(R int i=1;i<=4;++i) Num[1][i]=(double)(rand()%lim+1);
		if(dfs(1)) 
		{
			for(R int i=1;i<=4;++i)printf("%.0lf ",Num[1][i]);
			putchar('\n');
			return ;
		}
	}
}
int main()
{
    srand(time(NULL));
	puts("欢迎使用“二十四点”作弊器1.0，使用说明：");
	puts("功能1（输入1调用）：给定题目，系统解题");
	puts("功能2（输入2调用）：随机出题（配合1给出答案食用更佳）");
	puts("功能3（输入-1调用）：从1模式返回（否则会一直在该模式下）"); 
	res:
	puts("输入你的命令：");
	R int order;
	scanf("%d",&order);
    while(1)
	{
		memset(Num,0,sizeof(Num));
		if(order==1) subtask1();
		else if(order==2)
		{
			subtask2();	
			goto res;
		}
		if(ret1)
		{
			ret1=0;goto res;
		}
	}
	return 0;
}
