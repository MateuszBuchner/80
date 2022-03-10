#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 500;
int tab[SIZE];


void wys_boki(int a, int b, int c) {
	cout << a << "/" << b << "/" << c << endl << endl;
}

bool bokiTrojkata(int a, int b, int c) {
	return (a * a + b * b == c * c || a * a + c * c == b * b || c * a + c * b == a * a);
}

void zadanie1() {
	cout << "zad 1:" << endl;
	for (int i = 0; i < SIZE - 2; i++) {
		if (bokiTrojkata(tab[i], tab[i+1], tab[i+2])) {
			wys_boki(tab[i], tab[i+1], tab[i+2]);
		}
	}
}



bool czyJestTrojkatem(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

void zadanie2() {
	cout << "zad 2:" << endl;
	int max = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (czyJestTrojkatem(tab[i], tab[j], tab[k])) {
					int obwod = tab[i] + tab[j] + tab[k];
					if (obwod > max) max = obwod;
				}
			}
		}
	}
	cout << max;
}


int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	
	zadanie1();
	zadanie2();
}
