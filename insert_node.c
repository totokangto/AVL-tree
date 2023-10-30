#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
int get_height(AVL_node node) {
	if (node == NULL) return -1; // height of empty tree = -1
	return node->height;
}
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

	// update height, ���̰� ���� ���� ���� + 1 = ���ο� ����
	root->height = get_height(root->left) > get_height(root->right) ? 1 + get_height(root->left) : 1 + get_height(root->right);
	int fb = get_height(root->left) - get_height(root->right);

	return root;
}
