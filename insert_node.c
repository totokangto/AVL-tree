#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
#include"height.h"
#include"rotation.h"
AVL_node insert_node(AVL_node root, int key) {

	// 1. find right space and insert node 
	// �ڽ� ��尡 ������ �� �ڸ��� ��� �߰�
	if (root == NULL) {
		AVL_node avl = (AVL_node)malloc(sizeof(struct node));
		avl->key = key;
		avl->height = 0;
		avl->left = NULL;
		avl->right = NULL;
		return avl;
	}

	// �������� ����� key�� root�� key���� ������ left subtree�� �̵�
	if (key < root->key) {
		root->left = insert_node(root->left, key);
	}
	// �������� ����� key�� root�� key���� ũ�� right subtree�� �̵�
	else if (key > root->key) {
		root->right = insert_node(root->right, key);
	}

	// 2. restore balance
	// update height
	update_height(root);
	// balanced factor
	int bf = get_height(root->left) - get_height(root->right);

	// left subtree's height > right subtree's height
	if (bf > 1) {
		if (get_height(root->left->left) > get_height(root->left->right)) {
			root = R_Rotation(root);
		}
		else root = LR_Rotation(root);
	}
	// right subtree's height > left subtree's height
	else if (bf < -1) {
		if (get_height(root->right->left) < get_height(root->right->right) || get_height(root->left) == -1) {
			root = L_Rotation(root);
		}
		else root = RL_Rotation(root);
	}

	return root;
}