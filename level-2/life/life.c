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

int getIndex(t_life* life, int x, int y)
{
	return (y * life->width + x);
}

int isInsaid(t_life* life, int x, int y)
{
	return (x >= 0 && x < life->width && y >= 0 && y < life->height);
}

void drawInCell(t_life* life, int x, int y)
{
	if (isInsaid(life, x, y))
		life->board[getIndex(life, x, y)] = 1;
}

void userInput(t_life* life)
{
	char c;
	int x = 0, y = 0, pen = 0;

	while (read(0, &c, 1) > 0)
	{
		if (c == 'x')
			pen = !pen;
		if (c == 'w' && y > 0)
			y--;
		if (c == 's' && y < life->height - 1)
			y++;
		if (c == 'a' && x > 0)
			x--;
		if (c == 'd' && x < life->width - 1)
			x++;
		if (pen)
			drawInCell(life, x, y);
	}
}

void clear_board(char* board, int size)
{
	int i = 0;

	while (i < size)
		board[i++] = 0;
}

int count_neighbors(t_life* life, int x, int y)
{
	int dx = -1, dy = -1, nx = 0, ny = 0;
	int count = 0;

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
				if (isInsaid(life, nx, ny))
					count += life->board[getIndex(life, nx, ny)];
			}
			dx++;
		}
		dy++;
	}
	return (count);
}

void step (t_life* life)
{
	int x = 0, y = 0, neigh = 0, pos = 0;

	while (y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			pos = getIndex(life, x, y);
			neigh = count_neighbors(life, x, y);

			life->next[getIndex(life, x, y)] = 0;
			if (life->board[pos] == 1 && (neigh == 2 || neigh == 3))
			{
				life->next[pos] = 1;
			}
			else if (life->board[pos] == 0 && neigh == 3)
			{
				life->next[pos] = 1;
			}

			x++;
		}
		y++;
	}
}

void swap_board(t_life* life)
{
	char* tmp = life->board;
	life->board = life->next;
	life->next = tmp;

}

void simulate(t_life* life)
{
	int i = 0;

	while (i < life->iterations)
	{
		clear_board(life->next, life->width * life->height);
		step(life);
		swap_board(life);
		i++;
	}
}

void print_board(t_life* life)
{
	int x = 0, y = 0;

	while (y < life->height)
	{
		x = 0;
		while (x < life->width)
		{
			if (life->board[getIndex(life, x, y)])
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
		return (1);
	life.board = calloc(life.width * life.height, sizeof(char));
	life.next = calloc(life.width * life.height, sizeof(char));
	if (!life.board || !life.next)
	{
		free(life.board);
		free(life.next);
		return (1);
	}
	userInput(&life);
	simulate(&life);
	print_board(&life);
	free(life.board);
	free(life.next);
	return (0);
}
