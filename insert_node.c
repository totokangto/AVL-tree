#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
int get_height(AVL_node node) {
	if (node == NULL) return -1; // height of empty tree = -1
	return node->height;
}
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

	// update height, 높이가 높은 쪽의 높이 + 1 = 새로운 높이
	root->height = get_height(root->left) > get_height(root->right) ? 1 + get_height(root->left) : 1 + get_height(root->right);
	int fb = get_height(root->left) - get_height(root->right);

	return root;
}
