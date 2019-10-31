#include <stdlib.h>

int	valid(int r, int c, int n) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

int	max(int a, int b, int c) {
	int	maxab = a > b ? a : b;
	return maxab > c ? maxab : c;
}

int	gain(int **mine, int **cache, int r, int c, int n) {
	if (!valid(r, c, n))
		return 0;
	
	if (cache[r][c] == -1) {
		int	gain_r = gain(mine, cache, r, c + 1, n);
		int	gain_ru = gain(mine, cache, r + 1, c + 1, n);
		int	gain_rd = gain(mine, cache, r - 1, c + 1, n);
		cache[r][c] = mine[r][c] + max(gain_r, gain_ru, gain_rd);
	}
	return cache[r][c]; 
}

int	gold_gain(int **mine, int n) {
	int		max = 0;

	if (!mine || n <= 0)
		return 0;

	int		**cache = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) {
		cache[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++) {
			cache[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		int		local_max = gain(mine, cache, i, 0, n);
		if (local_max > max) {
			max = local_max;
		}
	}
	return max;
}
