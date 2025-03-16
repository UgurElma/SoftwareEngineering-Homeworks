#include <iostream>
using namespace std;
struct n {
	int x;
	n* next;
};
typedef n node;
void Write(node* root) {
	int i = 1;
	node* iter = root;
	while (true) {
		cout << i << ". kutunun degeri: " << iter->x << endl;
		if (iter->next == root)
			break;
		iter = iter->next;
		i++;
	}
}
node* AddBox(node* root, int value) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->x = value;
		root->next = root;
	}
	else {
		node* iter = root;
		while (iter->x < value) {
			if (iter->next == root) {
				iter->next = (node*)malloc(sizeof(node));
				iter->next->x = value;
				iter->next->next = root;
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
		node* temp = iter->next;
		iter->x = iter->next->x;
		iter->next = iter->next->next;
		free(temp);
	}
	else {
		while (iter->next->x != value) {
			iter = iter->next;
			if (iter->next == root) {
				return root;
			}
		}
		node* temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
	}
	return root;
}
void main() {
	node* root = NULL;
	int dizi[6] = { 2,4,5,3,6,1 };
	for (int i = 0; i < 6; i++) {
		root = AddBox(root, dizi[i]);
	}
	Write(root);
	cout << "---------------------" << endl;
	Write(DeleteBox(root, 6));
}