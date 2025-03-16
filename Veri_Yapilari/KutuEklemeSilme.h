#include <iostream>
#include <list>
using namespace std;

struct n
{
	int value;
	n* next;
};
typedef n node;

void WriteBox(node* iter) {
	while (true) {
		cout << iter->value << endl;
		if (iter->next == NULL)
			break;
		iter = iter->next;
	}
}

void AddBox(node* iter, int x) {
	while (iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->value = x;
	iter->next->next = NULL;
}
node* DeleteBoxByIndex(node* iter, int index) {
	list<int> values;
	int indexer = 0;
	while (true) {
		if (indexer != index)
			values.push_back(iter->value);
		indexer++;
		if (iter->next == NULL)
			break;
		iter = iter->next;
	}
	node* root = (node*)malloc(sizeof(node));
	root->value = values.front();
	values.pop_front();
	root->next = NULL;
	for (auto item : values) {
		AddBox(root, item);
	}
	return root;
}
int GetCount(node* r) {
	int count = 0;
	while (true) {
		count++;
		if (r->next == NULL)
			break;
		r = r->next;
	}
	return count;
}

node* AddBoxByIndex(node* iter, int index, int value) {
	list<int> values;
	int count = GetCount(iter);
	for (int i = 0; i < count + 1; i++) {
		if (i == index)
			values.push_back(value);
		else {
			values.push_back(iter->value);
			if (iter->next != NULL)
				iter = iter->next;
		}
	}
	node* root = (node*)malloc(sizeof(node));
	root->value = values.front();
	values.pop_front();
	root->next = NULL;
	for (auto item : values) {
		AddBox(root, item);
	}
	return root;
}
void smain() {
	node* root = NULL;
	root = (node*)malloc(sizeof(node));
	cout << "Ilk kutunun degerini gir: ";
	int firstValue;
	cin >> firstValue;
	root->value = firstValue;
	root->next = NULL;
	for (int i = 1; i < 5; i++) {
		AddBox(root, i + 1);
	}
	WriteBox(root);
	cout << "----------------------------------" << endl;
	WriteBox(AddBoxByIndex(root, 5, 20));
}