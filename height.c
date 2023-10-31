#pragma once
#include"make_tree_node.h"
#include"height.h"
#include<stdio.h>
int get_height(AVL_node root) {
	// height of empty tree = -1
	if (root == NULL) {
		int a = -1;
		return a;
	}
	return root->height;
}
void update_height(AVL_node root) {
	//  ���ο� ���� = subtree �߿��� ���̰� ���� ���� ���� + 1
	int left_h = get_height(root->left);
	int right_h = get_height(root->right);

	if (left_h > right_h) {
		root->height = 1 + left_h;
	}
	else {
		root->height = 1 + right_h;
	}
}