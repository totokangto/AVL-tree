#pragma once
#include"make_tree_node.h"
#include"rotation.h"
#include"height.h"
AVL_node R_Rotation(AVL_node root) {
	AVL_node a = root->left;
	AVL_node b = a->right;

	a->right = root;
	a->left = b;
	update_height(a);
	update_height(b);
	
	return a;
}
AVL_node L_Rotation(AVL_node root) {
	AVL_node a = root->right;
	AVL_node b = a->left;

	a->left = root;
	a->right = b;
	update_height(a);
	update_height(root);

	return a;
}
AVL_node LR_Rotation(AVL_node root) {
	
	// L_Rotation
	AVL_node a = root->left;
	AVL_node b = a->right;
	AVL_node c = b->left;

	b->left = a;
	a->right = c;
	root->left = b;
	update_height(b);
	update_height(a);
	update_height(root);
	
	// R_Rotation
	return R_Rotation(root);
}
AVL_node RL_Rotation(AVL_node root) {

	// R_Rotation
	AVL_node a = root->right;
	AVL_node b = a->left;
	AVL_node c = b->right;

	b->right = a;
	a->left = c;
	root->right = b;
	update_height(b);
	update_height(a);
	update_height(root);

	// R_Rotation
	return L_Rotation(root);
}