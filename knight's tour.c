#include<stdio.h>
#define N 8

int knight_tour(int x,int y,int step_count,int solved[N][N],int x_move[],int y_move[])
{
	int c;
	int nexti,nextj;
	if(step_count==N*N)
		return 1;
	for(c=0;c<8;c++)
	{
		nexti= x+x_move[c];
		nextj= y+y_move[c];
		if(valid_move(nexti,nextj,solved))
		{
			solved[nexti][nextj]=step_count;
			if(knight_tour(nexti,nextj,step_count+1,solved,x_move,y_move)==1)
				return 1;
			else
				solved[nexti][nextj]=-1;
		}
	}
	return 0;
}
		
		

int valid_move(int x,int y,int solved[N][N])
{
	if((x>=0 && x<N) && (y>=0 && y<N) && solved[x][y]==-1)
	 return 1;
	return 0;
}

int knight_tour_sol()
{
		int x_move[8]={2,1,-1,-2,-2,-1,1,2};
		int y_move[8]={1,2,2,1,-1,-2,-2,-1};
		
		int x,y,starti,startj;
		int solved[N][N];
		for(x=0;x<N;x++)
			for(y=0;y<N;y++)
				solved[x][y]=-1;
		
		printf("Enter the starting position: ");
		scanf("%d %d",&starti,&startj);
		printf("\n");
				
		solved[starti][startj]=0;
		if(knight_tour(starti,startj,1,solved,x_move,y_move)==0)
		{
			printf("Solution does not exist");
			return 0;
		}
		else
			for(x=0;x<N;x++)
			{
				for(y=0;y<N;y++)
					printf("%d\t",solved[x][y]);
				printf("\n");
			}
		return 1;
}

void main()
{
	
	knight_tour_sol();
}	
		
