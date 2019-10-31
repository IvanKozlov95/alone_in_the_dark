int		count_2(int n) {
	int		count = 0;

	while (n > 0) {
		count += n % 10 == 2;
		n /= 10;
	}
	return count;
}

int		count_of_2(int n) {
	int		i = 1;
	int		count = 0;

	while (++i <= n) {
		count += count_2(i);
	}
	return count;
}
