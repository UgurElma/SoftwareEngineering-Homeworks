#include <iostream>;
using namespace std;

struct n {
	int x;
	n* sag;
	n* sol;
};

typedef n node;

int Bul(node* root, int value)
{
	if (root->x == value)
		return 1;
	if (root->sol != NULL)
		return Bul(root->sol, value);
	if (root->sag != NULL)
		return Bul(root->sag, value);
	return -1;
}

node* Min(node* root)
{
	while (root->sol != NULL)
	{
		root = root->sol;
	}
	return root;
}

node* Max(node* root)
{
	while (root->sag != NULL)
	{
		root = root->sag;
	}
	return root;
}

node* Sil(node* root, int value)
{
	if (root == NULL)
		return NULL;
	if (root->x == value)
	{
		if (root->sag != NULL)
		{
			node* temp = Min(root->sag);
			root->x = temp->x;
			temp = NULL;
			return root;
		}
		if (root->sol != NULL)
		{
			node* temp = Max(root->sol);
			root->x = temp->x;
			temp = NULL;
			return root;
		}
		return NULL;
	}
	if (root->x < value)
	{
		root->sag = Sil(root->sag, value);
		return root;
	}
	root->sol = Sil(root->sol, value);
	return root;
}

node* Ekle(node* root, int value) {
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->x = value;
		root->sag = NULL;
		root->sol = NULL;
		return root;
	}
	if (root->x > value)
	{
		root->sol = Ekle(root->sol, value);
		return root;
	}
	if (root->x < value)
	{
		root->sag = Ekle(root->sag, value);
		return root;
	}
	return root;
}

void smain()
{
	node* root = NULL;
	root = Ekle(root, 50);
	root = Ekle(root, 55);
	root = Ekle(root, 58);
	root = Ekle(root, 52);
	root = Ekle(root, 56);
	root = Ekle(root, 51);
	root = Sil(root, 59);
	cout << "\nMax: " << Max(root)->x << "\nMin: " << Min(root)->x << "\nVar mi: " << Bul(root, 53);
}