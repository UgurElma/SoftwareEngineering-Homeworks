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
int GetCount(node* r) {
	int index = 1;
	while (true) {
		if (r->next == NULL)
			break;
		r = r->next;
		index++;
	}
	return index;
}

static list<int> GetValueList(node* r, int index, int value) {
	list<int> sayilar;
	int count = GetCount(r) + 1;
	for (int i = 0; i < count; i++) {
		if (i == index)
			sayilar.push_back(value);
		else {
			sayilar.push_back(r->x);
			r = r->next;
		}
	}
	return sayilar;
}
node* InsertBox(node* r) {
	int x, y;
	cout << "Istenilen degeri gir: ";
	cin >> x;
	cout << "Istenilen indexi gir: ";
	cin >> y;
	list<int> myList = GetValueList(r, y, x);
	node* root = (node*)malloc(sizeof(node));
	root->x = myList.front();
	root->next = NULL;
	int i = 0;
	for (auto element : myList)
	{
		if (i != 0)
			AddBox(root, element);
		i++;
	}
	return root;
}

void main() {
	node* root;
	root = (node*)malloc(sizeof(node));
	int value;
	cout << 1 << ". kutunun degerini gir: ";
	cin >> value;
	root->x = value;
	root->next = NULL;
	for (int i = 2; i <= 5; i++) {
		int value;
		cout << i << ". kutunun degerini gir: ";
		cin >> value;
		AddBox(root, value);
	}
	WriteBoxes(root);
	cout << "----------------" << endl;
	WriteBoxes(InsertBox(root));
}

