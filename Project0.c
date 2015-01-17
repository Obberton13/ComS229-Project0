#include<stdio.h>

//function declarations
void InitBoard(int xMax, int yMax);
int IsOnBoard(int x, int y);
void Visit(int x, int y);
void UnVisit(int x, int y);
void CalculatePaths(int x, int y);
void PrintPath(void);

int numVisited;
int numSolutions;
int board[5][5];
int visitedStackX[25];
int visitedStackY[25];

int main(int argc, char *argv[])
{
	int xMax = 5, yMax = 5;
	numVisited = 0;
	numSolutions = 0;
	InitBoard(xMax, yMax);
	int x, y;
	for(x=0;x<xMax;x++)
	{
		for(y=0; y<yMax; y++)
		{
			if(numVisited!=0)
			{
				numVisited = 0;
			}
			CalculatePaths(x, y);
		}
	}
	printf("Solutions found: %d\n", numSolutions);
	return 0;
}

void InitBoard(int xMax, int yMax)
{
	int x;
	int y;
	for(x=0; x<xMax; x++)
	{
		for(y=0;y<yMax;y++)
		{
			board[x][y] = 1;
		}
	}
}

int IsOnBoard(int x, int y)
{
	if(x<0||x>4||y<0||y>4)
	{
		return 0;
	}
	return board[x][y];
}

void CalculatePaths(int x, int y)
{
	Visit(x, y);
	if(numVisited>=25)
	{
		PrintPath();
		UnVisit(x, y);
		return;
	}
	if(IsOnBoard(x+2,y+1)==1)
	{
		CalculatePaths(x+2, y+1);
	}
	if(IsOnBoard(x+2,y-1)==1)
	{
		CalculatePaths(x+2, y-1);
	}
	if(IsOnBoard(x-2,y+1)==1)
	{
		CalculatePaths(x-2,y+1);
	}
	if(IsOnBoard(x-2,y-1)==1)
	{
		CalculatePaths(x-2, y-1);
	}
	if(IsOnBoard(x+1,y+2)==1)
	{
		CalculatePaths(x+1, y+2);
	}
	if(IsOnBoard(x+1,y-2)==1)
	{
		CalculatePaths(x+1, y-2);
	}
	if(IsOnBoard(x-1,y+2)==1)
	{
		CalculatePaths(x-1, y+2);
	}
	if(IsOnBoard(x-1,y-2)==1)
	{
		CalculatePaths(x-1, y-2);
	}
	UnVisit(x,y);
}

void Visit(int x, int y)
{
	visitedStackY[numVisited]=y;
	visitedStackX[numVisited]=x;
	board[x][y] = 0;
	numVisited++;
}

void UnVisit(int x, int y)
{
	board[x][y] = 1;
	numVisited--;
}

void PrintPath()
{
	numSolutions++;
	int i;
	for(i=0;i<24;i++)
	{
		printf("%d, ", 5*visitedStackX[i]+visitedStackY[i]);
	}
	printf("%d\n", 5*visitedStackX[24]+visitedStackY[24]);
}
