#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_life
{
	int width;
	int height;
	int iterations;

	char* border;
	char* next;
} t_life;

int getIndex(t_life* life, int x, int y)
{
	return (y * life->width + x);
}

int insaid(t_life* life, int x, int y)
{
	return (x >= 0 && x < life->width && y >= 0 && y < life->height);
}

void drawBoard(t_life* life, int x, int y)
{
	if (insaid(life, x, y))
		life->border[getIndex(life, x, y)] = 1;
}

void getInput(t_life* life)
{
	char c;
	int pen = 0;
	int x = 0, y = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < life->height - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < life->width - 1)
			x++;
		if (pen)
			drawBoard(life, x, y);
	}
}

int getNeighbors(t_life* life, int x, int y)
{
	int dx = -1, dy = -1, nx = 0, ny = 0;
	int count = 0;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			 nx = x + dx;
			 ny = y + dy;
			 if (!(dx == 0 && dy == 0) && insaid(life, nx, ny))
			 	count += life->border[getIndex(life, nx, ny)];
			dx++;
		}
		dy++;
	}
	return (count);
}

void clearBorder(char* next, int size)
{
	int i = 0;

	while (i < size)
	{
		next[i] = 0;
		i++;
	}
}

void swapBorder(t_life* life)
{
	char* tmp = life->next;

	life->next = life->border;
	life->border = tmp;
}

void step(t_life* life)
{
	int x = 0, y = 0, nighbors = 0, pos = 0;
	
	y = 0;
	while (y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			nighbors = getNeighbors(life, x, y);
			pos = getIndex(life, x, y);
			life->next[pos] = 0;
			if (life->border[pos] == 1 && (nighbors == 3 || nighbors == 2))
			{
				life->next[pos] = 1;
			}
			else if (life->border[pos] == 0 && nighbors == 3)
			{
				life->next[pos] = 1;
			}
			x++;
		}
		y++;
	}
}

void simulate(t_life* life)
{
	int i = 0;

	while (i < life->iterations)
	{
		clearBorder(life->next, life->width * life->height);
		step(life);
		swapBorder(life);
		i++;
	}

}

void printBoard(t_life* life)
{
	int x = 0, y = 0;

	while (y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			if (life->border[getIndex(life, x, y)])
				putchar('O');
			else
				putchar(' ');
			x++;
		}
		putchar('\n');
		y++;
	}
}

int main(int argc, char** argv)
{
	if (argc != 4)
		return (1);
	t_life life;
	life.width = atoi(argv[1]);
	life.height = atoi(argv[2]);
	life.iterations = atoi(argv[3]);
	if (life.width <= 0 || life.height <= 0 || life.iterations < 0)
		return (0);
	life.border = calloc(life.width * life.height, sizeof(char));
	life.next = calloc(life.width * life.height, sizeof(char));
	if (!life.border || !life.next)
	{
		free(life.border);
		free(life.next);
		return (1);
	}
	getInput(&life);
	simulate(&life);
	printBoard(&life);
	free(life.border);
	free(life.next);
	return (0);
}