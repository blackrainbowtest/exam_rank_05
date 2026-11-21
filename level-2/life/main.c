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

void drawcell(t_life* life, int x, int y)
{
	if (inside(life, x, y))
		life->board[getindex(life, x, y)] = 1;
}

void readinput(t_life* life)
{
	char c;
	int x, y, pen = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else
		{
			if (c == 'w')
				y--;
			else if (c == 's')
				y++;
			else if (c == 'a')
				x--;
			else if (c == 'd')
				x++;
		}
		if (pen)
			drawcell(life, x, y);
	}
}

void printboard(t_life* life)
{
	int x, y = 0;

	y = 0;
	while (y < life->height)
	{
		x = 0;
		while (x <life->width)
		{
			if (life->board[getindex(life, x, y)])
				putchar('O');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}



int main(int argc, char **argv)
{
	t_life life;
	int size;

	if (argc != 4)
		return (1);
	life.width = atoi(argv[1]);
	life.height = atoi(argv[2]);
	life.iterations = atoi(argv[3]);
	if (life.width <= 0 || life.height <= 0 || life.iterations < 0)
		return (1);
	size = life.width * life.height;
	life.board = calloc(size, sizeof(char));
	life.next = calloc(size, sizeof(char));
	if (!life.board || !life.next)
	{
		free(life.board);
		free(life.next);
		return (1);
	}
	// main path
	readinput(&life);

	printboard(&life);
	free(life.board);
	free(life.next);
	return (0);
}