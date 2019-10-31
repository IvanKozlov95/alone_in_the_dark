#include <stddef.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2) {
	if (!lst1 || !lst2)
		return NULL;

	while (lst1) {
		struct s_node *head2 = lst2;
		while (lst2) {
			if (lst2 == lst1)
				return lst1;
			lst2 = lst2->next;
		}
		lst2 = head2;
		lst1 = lst1->next;
	}
	return NULL;
}

// #include <stdio.h>

// int	main(void) {
// 	struct s_node n10 = { "10", NULL };
// 	struct s_node n9 = { "9", &n10 };
// 	struct s_node n8 = { "8", &n9 };
// 	struct s_node n7 = { "7", &n9 };
// 	struct s_node n6 = { "6", NULL };
// 	printf("%p\n", intersection(&n7, &n6));
// }
