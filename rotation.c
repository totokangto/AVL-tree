#pragma once
#include<stdio.h>
#include"make_tree_node.h"
#include"rotation.h"
#include"height.h"
AVL_node R_Rotation(AVL_node root) {
	AVL_node a = root->left;
	AVL_node b = a->right;

	// root�� left node�� right subtree�� ���� ���
	if (b != NULL) {
		root->left = b;
	}
	else {
		root->left = NULL;
	}
	a->right = root;
	update_height(root);
	update_height(a);

	return a;
}
AVL_node L_Rotation(AVL_node root) {
	AVL_node a = root->right;
	AVL_node b = a->left;

	
	// root�� right node�� left subtree�� ���� ���
	if (b != NULL) {
		root->right = b;
	}
	else {
		root->right = NULL;
	}
	a->left = root;
	update_height(root);
	update_height(a);
	
	return a;
}
AVL_node LR_Rotation(AVL_node root) {
	
	// L_Rotation
	AVL_node a = root->left;
	AVL_node b = a->right;
	AVL_node c = b->left;

	b->left = a;
	// root�� left node�� right node�� left subtree�� ���� ���
	if (c != NULL) {
		a->right = c;
	}
	else {
		a->right = NULL;
	}
	root->left = b;
	
	update_height(root);
	update_height(a);
	update_height(b);
	
	// R_Rotation
	return R_Rotation(root);
}
AVL_node RL_Rotation(AVL_node root) {

	// R_Rotation
	AVL_node a = root->right;
	AVL_node b = a->left;
	AVL_node c = b->right;

	b->right = a;
	// root�� right node�� left node�� right subtree�� ���� ���
	if (c != NULL) {
		a->left = c;
	}
	else {
		a->left = NULL;
	}
	root->right = b;
	
	update_height(root);
	update_height(a);
	update_height(b);

	// R_Rotation
	return L_Rotation(root);
}

