#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_life
{
	int width;
	int height;
	int iterations;
	char* board;
	char* next;
} t_life;

int getindex (t_life* life, int x, int y)
{
	return (y * life->width + x);
}

int inside (t_life* life, int x, int y)
{
	return (x >= 0 && y >= 0 && x< life->width && y < life->height);
}

