#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node	*copy_node(struct s_node *node) {
	struct s_node *newnode = malloc(sizeof(struct s_node));

	newnode->next = NULL;
	newnode->other = NULL;
	newnode->data = node->data;
	return newnode;
}

int				lst_idx(struct s_node *head, struct s_node *node) {
	int		idx = 0;

	while (head) {
		if (head == node)
			return idx;
		idx++;
		head = head->next;
	}
	return -1;
}

struct s_node	*lst_at(struct s_node *head, int idx) {
	int		i = 0;

	if (idx < 0)
		return NULL;

	while (i != idx) {
		if (!head) return NULL;
		head = head->next;
		i++;
	}
	return head;
}

struct s_node	*clone_shallow(struct s_node *node, int *size) {
	int				len = 0;
	struct s_node	*copy = NULL;
	struct s_node	*head = NULL;

	while (node) {
		if (!copy) {
			copy = copy_node(node);
			head = copy;
		} else {
			copy->next = copy_node(node);
			copy = copy->next;
		}
		node = node->next;
		len++;
	}
	*size = len;
	return head;
}

struct s_node *clone_list(struct s_node *node) {
	int				size = 0;
	struct s_node	*copy = NULL;
	struct s_node	*head_copy = NULL;
	struct s_node	*head_orig = NULL;

	copy = clone_shallow(node, &size);
	head_orig = node;
	head_copy = copy;
	while (node) {
		if (node->other) {
			int idx = lst_idx(head_orig, node->other);
			copy->other = lst_at(head_copy, idx);
		}
		copy = copy->next;
		node = node->next;
	}
	return head_copy;
}

#ifdef test

#include <stdio.h>

#define NODE(d, n, o) &(struct s_node){ d, n, o }

void	print_list(struct s_node *l) {
	while (l) {
		printf("%p %d next %p other %p\n", l, l->data, l->next, l->other);
		l = l->next;
	}
}

int		main(void) {
	struct s_node *l1 = NODE(
		1,
		NODE(
			2,
			NODE(
				3,
				0,
				0
			),
			0
		),
		0
	);
	l1->other = l1;
	l1->next->other = l1->next->next;
	print_list(l1);
	printf("Copy: \n");
	print_list(clone_list(l1));
	print_list(clone_list(NULL));
	struct s_node *l2 = NODE(
		1,
		NODE(
			2,
			NODE(
				3,
				NODE(
					4,
					0,
					0
				),
				NODE(
					666,
					0,
					0
				)
			),
			0
		),
		0
	);
	l2->next->next->next->next = l2->next->next->other;
	printf("L2: \n");
	print_list(l2);
	printf("Copy: \n");
	print_list(clone_list(l2));
}

#endif
