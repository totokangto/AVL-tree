#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"insert_node.h"
#include"height.h"
#include"rotation.h"
AVL_node delete_node(AVL_node root, int key) {
	
	// 1. find node and delete
	// 없애려는 노드의 key가 root의 key보다 작으면 left subtree로 이동
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	// 없애려는 노드의 key가 root의 key보다 크면 right subtree로 이동
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	// 없애려는 노드의 key = root의 key => 삭제할 node
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
			// root의 left subtree 중 가장 큰 key값을 갖는 node 찾기
			AVL_node max = root->left;
			while (max->right != NULL)
				max = max->right;
			// root의 key를 left subtree에서 가장 큰 key로 교체
			root->key = max->key;
			// root의 left subtree에서 그 노드 삭제
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