#include <iostream>
using namespace std;

struct n {
	int x;
	n* next;
};

typedef n node;

void Write(node* iter) {
	int i = 1;
	while (true) {
		cout << i << ". kutunun degeri: " << iter->x << endl;
		if (iter->next == NULL)
			break;
		iter = iter->next;
		i++;
	}
}

node* AddBox(node* root, int value) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = value;
		root->next = NULL;
	}
	else {
		node* iter = root;
		while (iter->x <= value) {
			if (iter->next == NULL) {
				iter->next = (node*)malloc(sizeof(node));
				iter->next->x = value;
				iter->next->next = NULL;
				return root;
			}
			iter = iter->next;
		}
		node* temp = (node*)malloc(sizeof(node));
		temp->x = iter->x;
		temp->next = iter->next;
		iter->x = value;
		iter->next = temp;
	}
	return root;
}

node* DeleteBox(node* root, int value) {
	node* iter = root;
	if (iter->x == value) {
		root = iter->next;
		free(iter);
	}
	else {
		while (iter->next->x != value)
		{
			iter = iter->next;
		}
		node* temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
	}
	return root;
}

void amain() {
	node* root = NULL;
	int dizi[5] = { 1,8,9,3,7 };
	for (int i = 0; i < 5; i++) {
		root = AddBox(root, dizi[i]);
	}
	Write(root);
	cout << "--------------" << endl;
	Write(DeleteBox(root, 1));
}