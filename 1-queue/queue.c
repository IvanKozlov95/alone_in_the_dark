#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void);
void enqueue(struct s_queue *queue, void *content);
void *dequeue(struct s_queue *queue);
void *peek(struct s_queue *queue);
int isEmpty(struct s_queue *queue);

struct s_node	*newnode(void *content) {
	struct s_node *n = malloc(sizeof(struct s_node));

	n->next = NULL;
	n->content = content;
	return n;
}

struct s_queue *init(void) {
	struct s_queue	*q = malloc(sizeof(struct s_queue));

	q->first = NULL;
	q->last = NULL;
	return q;
}

void enqueue(struct s_queue *queue, void *content) {
	if (!queue)	{
		return ;
	}

	struct s_node	*n = newnode(content);

	if (isEmpty(queue)) {
		queue->last = n;
		queue->first = n;
	} else {
		queue->last->next = n;
		queue->last = n;
	}
}

void *dequeue(struct s_queue *queue) {
	void	*ret = NULL;

	if (queue && !isEmpty(queue)) {
		void	*tmp = queue->first;
		ret = queue->first->content;
		queue->first = queue->first->next;
		free(tmp);
		if (queue->first == NULL) {
			queue->last = NULL;
		}
	}
	return ret;
}

void *peek(struct s_queue *queue) {
	void	*ret = NULL;

	if (queue && !isEmpty(queue)) {
		ret = queue->first->content;
	}
	return ret;
}

int isEmpty(struct s_queue *queue) {
	return queue->first == NULL;
}

// #include <stdio.h>

// int		main(void) {
// 	struct s_queue *q = init();

// 	enqueue(q, "1");
// 	enqueue(q, "2");
// 	enqueue(q, "3");
// 	printf("%s\n", peek(q));
// 	printf("%s\n", dequeue(q));
// 	printf("%s\n", peek(q));
// 	printf("%s\n", dequeue(q));
// 	printf("%s\n", dequeue(q));
// 	printf("%s\n", dequeue(q));
// 	printf("%s\n", dequeue(q));
// 	printf("%s\n", peek(q));
// 	printf("%s\n", peek(NULL));
// }