#pragma once
struct node
{
	// node�� key ��
	int key;
	//  tree�� height
	int height;
	// ����, ������ ��带 ����Ű�� 2���� pointer
	struct node* left;
	struct node* right;

};
// ����ü ������ �� ������
typedef struct node* AVL_node;

