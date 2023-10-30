#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
#include"height.h"
#include"rotation.h"
AVL_node insert_node(AVL_node root,int key) {
	
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
	
	// update height
	update_height(root);
	
	int fb = get_height(root->left) - get_height(root->right);

	if (fb > 1) {
		if (get_height(root->left->left) > get_height(root->left->right)) {
			root = R_Rotation(root);
		}
		else root = LR_Rotation(root);
	}
	if (fb < -1) {
		if (get_height(root->right->left) < get_height(root->right->right)) {
			root = L_Rotation(root);
		}
		else root = RL_Rotation(root);
	}

	return root;
}
