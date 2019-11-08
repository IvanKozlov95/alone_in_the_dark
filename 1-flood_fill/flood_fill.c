typedef struct  s_point
{
		int		x;
		int		y;
}				t_point;

int		valid(t_point size, t_point p) {
	return size.x > p.x && size.y > p.y && p.x >= 0 && p.y >= 0;
}

t_point	inc(t_point p, int x, int y) {
	p.x += x;
	p.y += y;
	return p;
}

void	rec(char **tab, t_point size, t_point p, char c) {
	if (!valid(size, p) || tab[p.y][p.x] != c)
		return ;

	tab[p.y][p.x] = 'F';
	rec(tab, size, inc(p, 1, 0), c);
	rec(tab, size, inc(p, -1, 0), c);
	rec(tab, size, inc(p, 0, 1), c);
	rec(tab, size, inc(p, 0, -1), c);
}

void	flood_fill(char **tab, t_point size, t_point begin) {
	if (valid(size, begin) && tab) {
		rec(tab, size, begin, tab[begin.y][begin.x]);
	}
}

#ifdef test

#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

#endif