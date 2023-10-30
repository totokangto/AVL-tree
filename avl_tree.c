#include<stdio.h>
#include<stdlib.h>
#include"make_tree_node.h"
#include"insert_node.h"

int main(void) {
	AVL_node root = NULL;
	root = insert_node(root, 6);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	printf("%d\n", root->height);
	return 0;
}