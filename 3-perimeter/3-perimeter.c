#include <stdio.h>

struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
};

void	recur(struct s_node *root, int leftmost, int rightmost)
{
	if (root == NULL)
		return;

	int		isLeaf = root->left == NULL && root->right == NULL;

	if (leftmost && rightmost)
		printf("%d", root->value);
	else if (leftmost || isLeaf)
		printf(" %d", root->value);

	recur(root->left, leftmost, 0);
	recur(root->right, 0, rightmost);

	if (rightmost && !leftmost && !isLeaf)
		printf(" %d", root->value);
}

void	perimeter(struct s_node *root)
{
	recur(root, 1, 1);
	printf("\n");
}

#ifdef test

#define NODE(value, left, right) &(struct s_node){ value, right, left }

int		main(void)
{
	struct s_node	*root1 = NODE(1, 0, 0);
	struct s_node	*root2 = NODE(
		92,
		NODE(
			85,
			NODE(
				79,
				0,
				NODE(
					10,
					NODE(
						39,
						NODE(
							35,
							NODE(96, 0, 0),
							0
							),
						0
						),
					0
					)
				),
			0
			),
		NODE(
			26,
			0,
			NODE(
				64,
				NODE(
					40,
					NODE(
						88,
						NODE(
							12,
							NODE(58, 0, 0),
							0
							),
						NODE(
							55,
							NODE(58, 0, 0),
							NODE(41, 0, 0)
							)
						),
					NODE(
						10,
						NODE(
							52,
							NODE(22, 0, 0),
							NODE(35, 0, 0)
							),
						NODE(
							87,
							0,
							NODE(31, 0, 0)
							)
						)
					),
				NODE(
					78,
					NODE(
						2,
						NODE(
							33,
							0,
							NODE(55, 0, 0)
							),
						NODE(
							11,
							NODE(99, 0, 0),
							0
							)
						),
					NODE(
						85,
						0,
						NODE(51, 0, 0)
						)
					)
				)
			)
		);

	perimeter(root1);
	perimeter(root2);
}

#endif
