#include<stdio.h>
#include<stdlib.h>
#include"make_tree_node.h"
#include"insert_node.h"
#include"height.h"

int main(void) {
	AVL_node root = NULL;
	
	root = insert_node(root, 3);
	root = insert_node(root, 2);
	root = insert_node(root, 1);
	root = insert_node(root, 4);
	root = insert_node(root, 5);
	printf("%d\n", root->height);
	//printf("%d\n", root->height);
	/*
	AVL_node a = (AVL_node)malloc(sizeof(struct node));
	AVL_node b = (AVL_node)malloc(sizeof(struct node));
	AVL_node c = (AVL_node)malloc(sizeof(struct node));
	a->key = 100;
	a->height = 0;
	a->left = NULL;
	a->right = NULL;
	b->key = 99;
	b->height = 0;
	b->left = NULL;
	b->right = NULL;
	//c->key = 98;
	//c->height = 0;

	a->left = b;
	update_height(a);
	//b->left = c;
	//update_height(b);
	//update_height(a);

	int ah = get_height(a);
	int bh = get_height(b->left->left);
	printf("%d\n%d\n", a->left,b);
	printf("%d\n%d\n", b->left, bh);
	*/
	

	return 0;
}