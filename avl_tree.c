#include<stdio.h>
#include<stdlib.h>
#include"make_tree_node.h"
#include"insert_node.h"
#include"delete_node.h"

int main(void) {
	AVL_node root = NULL;
	
	root = insert_node(root, 3);
	root = insert_node(root, 2);
	root = insert_node(root, 1); // R Rotation
	root = insert_node(root, 4);
	root = insert_node(root, 5); // L Rotation
	root = insert_node(root, 6);
	root = insert_node(root, 7); // L Rotation
	root = insert_node(root, 16);
	root = insert_node(root, 15); // RL Rotation
	root = insert_node(root, 14); // LR Rotation
	printf("root key : %d\n", root->key); // 4
	printf("root height : %d\n", root->height); // 3
	root = delete_node(root, 1); // delete node that has no child
	root = delete_node(root, 2); // delete node that has one child, Single Rotation(Left)
	root = delete_node(root, 15); // delete node that has two child
	root = delete_node(root, 16); // Double Rotation(Left Right)
	printf("root key : %d\n", root->key); // 6
	printf("root height : %d\n", root->height); // 2

	return 0;
}