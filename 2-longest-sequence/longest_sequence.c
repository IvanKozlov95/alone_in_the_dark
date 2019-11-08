struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	rec(struct s_node *node, int l, int prev) {
	if (!node)
		return l;
	l = (node->value - prev) == 1 ? l + 1 : 1;
	int left = rec(node->left, l, node->value);
	int right = rec(node->right, l, node->value);
	return left > right ? left : right;
}

int	longest_sequence(struct s_node *node) {
	if (!node)
		return 0;
	int left = rec(node->left, 1, node->value);
	int right = rec(node->right, 1, node->value);
	return left > right ? left : right;
}

#ifdef test

#define NODE(value, left, right) &(struct s_node){ value, left, right }

#include <stdio.h>

int		main(void) {
	struct s_node *r1 = NODE(1, 0, 0);
	struct s_node *r2 = NULL;
	printf("1 == %d\n", longest_sequence(r1));
	printf("0 == %d\n", longest_sequence(r2));
	struct s_node *r3 = NODE(
		10,
		NODE(
			5,
			NODE(
				6,
				NODE(
					7,
					0,
					0
				),
				NODE(
					13,
					0,
					0
				)
			),
			NODE(
				9,
				0,
				0
			)
		),
		0
	);
	printf("3 == %d\n", longest_sequence(r3));
	struct s_node *r4 = NODE(
		5,
		NODE(
			6,
			0,
			0
		),
		NODE(
			4,
			NODE(
				9,
				NODE(
					3,
					0,
					0
				),
				NODE(
					2,
					0,
					0
				)
			),
			NODE(
				3,
				0,
				NODE(
					2,
					0,
					0
				)
			)
		)
	);
	printf("2 == %d\n", longest_sequence(r4));
	struct s_node *r5 = NODE(
		30,
		NODE(
			15,
			NODE(
				61,
				0,
				0
			),
			0
		),
		NODE(
			41,
			NODE(
				80,
				0,
				0
			),
			0
		)
	);
	printf("1 == %d\n", longest_sequence(r5));
}

#endif