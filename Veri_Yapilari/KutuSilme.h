#include <iostream>
#include <list>
using namespace std;

struct n {
	int x;
	n* next;
};
typedef n node;

void WriteBoxes(node* r) {
	int index = 1;
	while (true) {
		cout << index << ". kutunun degeri: " << r->x << endl;
		if (r->next == NULL)
			break;
		r = r->next;
		index++;
	}
}

void AddBox(node* r, int x) {
	while (r->next != NULL) {
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x = x;
	r->next->next = NULL;
}

void DeleteFinalBox(node* iter) {
	while (iter->next->next != NULL) {
		iter = iter->next;
	}
	iter->next = NULL;
}

static node* DeleteFirstBox(node* iter, int index) {
	if (iter != NULL)
		iter = iter->next;
	return iter;
}

void DeleteBoxbyIndex(node* iter, int index) {
	int i = 0;
	if (iter != NULL) {
		while (iter->next != NULL) {
			i++;
			if (i == index) {
				iter->next = iter->next->next;
				break;
			}
			iter = iter->next;
		}
	}
}

void main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	int value, index, count;
	cout << "Kutu sayisini gir: ";
	cin >> count;
	cout << 1 << ". kutunun degerini gir: ";
	cin >> value;
	root->x = value;
	root->next = NULL;
	for (int i = 2; i <= count; i++) {
		int value;
		cout << i << ". kutunun degerini gir: ";
		cin >> value;
		AddBox(root, value);
	}
	WriteBoxes(root);
	cout << "----------------" << endl;
	cout << "Silenecek kutunun indexini gir: ";
	cin >> index;
	if (index >= count) {
		cout << "Boyle bir kutu zaten yok!";
	}
	else {
		if (index == 0)
			root = DeleteFirstBox(root, 0);
		else
			DeleteBoxbyIndex(root, index);
		WriteBoxes(root);
	}
}