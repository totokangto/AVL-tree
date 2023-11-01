#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
#include"height.h"
#include"rotation.h"
AVL_node delete_node(AVL_node root, int key) {
	
	// 1. find node and delete
	// ���ַ��� ����� key�� root�� key���� ������ left subtree�� �̵�
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	// ���ַ��� ����� key�� root�� key���� ũ�� right subtree�� �̵�
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	// ���ַ��� ����� key = root�� key => ������ node
	else {
		if (root->left == NULL || root->right == NULL) {
			
			AVL_node temp = root->right ? root->right : root->left;
			// node has no child
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			// node has one child
			else
				// change root to left subtree of root
				*root = *temp;			
			free(temp);
		}
		else {
			// node has two child
			// root�� left subtree �� ���� ū key���� ���� node ã��
			AVL_node max = root->left;
			while (max->right != NULL)
				max = max->right;
			// root�� key�� left subtree���� ���� ū key�� ��ü
			root->key = max->key;
			// root�� left subtree���� �� ��� ����
			root->left = delete_node(root->left, max->key);
		}
	}

	// 2. restore balance
	if (root == NULL)
		return root;

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