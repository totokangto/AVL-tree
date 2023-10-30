#pragma once
#include"make_tree_node.h"
#include"height.h"
#include<stdio.h>
int get_height(AVL_node root) {
	if (root == NULL) return -1; // height of empty tree = -1
	return root->height;
}
void update_height(AVL_node root) {
	//  ���ο� ���� = subtree �߿��� ���̰� ���� ���� ���� + 1
	root->height = get_height(root->left) > get_height(root->right) ? 1 + get_height(root->left) : 1 + get_height(root->right);
}