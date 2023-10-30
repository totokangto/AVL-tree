#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
AVL_node insert_node(AVL_node root,int key) {
	
	// �ڽ� ��尡 ������ �� �ڸ��� ��� �߰�
	if (root == NULL) {
		AVL_node avl = (AVL_node)malloc(sizeof(struct node)); 
		avl->key = key;
		avl->height = 1;
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

	return root;
}
