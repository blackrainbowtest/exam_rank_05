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
	int x = 0, y = 0, pen = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		else
		{
			if (c == 'w' && y > 0)
				y--;
			else if (c == 's' && y < life->height - 1)
				y++;
			else if (c == 'a' && x > 0)
				x--;
			else if (c == 'd' && x < life->width - 1)
				x++;
		}
		if (pen)
			drawcell(life, x, y);
	}
}

void printboard(t_life* life)
{
	int x = 0, y = 0;

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

int count_neighbors(t_life* life, int x, int y)
{
	int count, dx, dy, nx, ny = 0;

	count = 0;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (!(dx == 0 && dy == 0))
			{
				nx = x + dx;
				ny = y + dy;
				if (inside(life, nx, ny))
					count += life->board[getindex(life, nx, ny)];
			}
			dx++;
		}
		dy++;
	}
	return (count);
}

void swapboards(t_life* life)
{
	char* tmp;

	tmp = life->board;
	life->board = life->next;
	life->next = tmp;
}

void clearboard(char* board, int size)
{
	int i = 0;

	while (i < size)
	{
		board[i] = 0;
		i++;
	}
}

void step(t_life* life)
{
	int x, y, neighbors, pos = 0;

	y = 0;
	while (y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			pos = getindex(life, x, y);
			neighbors = count_neighbors(life, x, y);
			life->next[pos] = 0;
			if (life->board[pos] && (neighbors == 2 || neighbors == 3))
				life->next[pos] = 1;
			else
			{
				if (neighbors == 3)
					life->next[pos] = 1;
			}
			x++;
		}
		y++;
	}
}

void simulate(t_life* life)
{
	int i, size;

	i = 0;
	size = life->width * life->height;
	while (i < life->iterations)
	{
		clearboard(life->next, size);
		step(life);
		swapboards(life);
		i++;
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
	simulate(&life);
	printboard(&life);
	free(life.board);
	free(life.next);
	return (0);
}