#include<stdio.h>

typedef struct Vector2
{
	int x, y;
}Vector2;

//function declarations
void InitBoard(int xMax, int yMax);
int IsOnBoard(int x, int y);
void Visit(struct Vector2 pos);
void CalculatePaths(int x, int y);
Vector2 NextToVisit(int x, int y);

int numVisited;
int board[5][5];
Vector2 visitedStack[25];

void main(int argc, char *argv[])
{
	int xMax = 5, yMax = 5;
	InitBoard(xMax, yMax);
	int x, y;
	for(x=0;x<xMax;x++)
	{
		for(y=0; y<yMax; y++)
		{
			CalculatePaths(x, y);
		}
	}
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
	int numVisited = 0;
	Vector2 next;
	next.x = x;
	next.y = y;
	while (numVisited<25)
	{
		next = NextToVisit(next.x, next.y);
		Visit(next);
		printf("%d: %d, %d. ", numVisited, next.x, next.y);
	}
	printf("\n");
}

Vector2 NextToVisit(int x, int y)
{
	
}

void Visit(Vector2 pos)
{
	numVisited++;
	board[pos.x][pos.y] = 0;
}

void UnVisit(Vector2 pos)
{
	numVisited--;
	oard[pos.x][pos.y] = 1;
}
