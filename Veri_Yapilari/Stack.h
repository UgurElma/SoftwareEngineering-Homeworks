#include <iostream>
using namespace std;
int* dizi;
int boyut = 2;
int tepe = 0;

void Write() {
	for (int i = 0; i < tepe; i++)
		cout << i + 1 << ". kutunun degeri: " << dizi[i] << endl;
}
void push(int value) {
	if (tepe == 0) {
		dizi = (int*)malloc(sizeof(int) * 2);
	}
	if (tepe >= boyut) {
		int* dizi2 = (int*)malloc(sizeof(int) * boyut * 2);
		for (int i = 0; i < tepe; i++)
			dizi2[i] = dizi[i];
		free(dizi);
		dizi = dizi2;
		boyut *= 2;
	}
	dizi[tepe++] = value;
}
int pop() {
	int value = dizi[--tepe];
	if (tepe <= boyut / 2) {
		int* dizi2 = (int*)malloc(sizeof(int) * boyut / 2);
		for (int i = 0; i < tepe; i++)
			dizi2[i] = dizi[i];
		free(dizi);
		dizi = dizi2;
		boyut /= 2;
	}
	return value;
}
void smain() {
	push(10);
	push(20);
	push(30);
	Write();
	cout << "Poped: " << pop() << endl << "---------------------" << endl;
	Write();
}