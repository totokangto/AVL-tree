#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
#include"height.h"
#include"rotation.h"
AVL_node insert_node(AVL_node root,int key) {
	
	// 자식 노드가 없으면 그 자리에 노드 추가
	if (root == NULL) {
		AVL_node avl = (AVL_node)malloc(sizeof(struct node)); 
		avl->key = key;
		avl->height = 0;
		avl->left = NULL;
		avl->right = NULL;
		return avl;
	}

	// 넣으려는 노드의 key가 root의 key보다 작으면 left subtree로 이동
	if (key < root->key) {
		root->left = insert_node(root->left, key); 
	}
	// 넣으려는 노드의 key가 root의 key보다 크면 right subtree로 이동
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
