#pragma once
struct node
{
	// node의 key 값
	int key;
	//  tree의 height
	int height;
	// 왼쪽, 오른쪽 노드를 가리키는 2개의 pointer
	struct node* left;
	struct node* right;

};
// 구조체 포인터 형 재정의
typedef struct node* AVL_node;

