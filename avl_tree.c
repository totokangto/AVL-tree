#include<stdio.h>
#include<stdlib.h>
#include"make_tree_node.h"
#include"insert_node.h"

int main(void) {
	AVL_node a = NULL;
	a = insert_node(a, 6);
	printf("%d\n", a->key);
	AVL_node b = insert_node(a, 3);
	printf("%d\n", b->key);
	printf("%d\n", a->left->key);
	AVL_node c = insert_node(a, 4);
	printf("%d\n", a->left->key);
	return 0;
}