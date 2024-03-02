#include<iostream>
#include<windows.h>
using namespace std;
void kt(int table[100][100]) {
//	for (int i = -9; i<= 9; i++) {
//	cout << "\n";
		for (int j = 0 ; j < 9; j ++){
			for (int o = 0; o < 9 ; o++) {
				cout << table[j][9 - o] << " ";
							}
		}
	}

int main() {
	int ch = 0;
    int table[100][100] = {};
    for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
    	++ch;
	table[j][i] = ch; 
	}
}
    for (int j = 0; j < 9; j++) {
    	cout << "\n";

    for (int i = 0; i < 9; i++) {
	cout << " " << table[j][i]; 
	}
}
cout << "\n";
kt(table);
  
	return 0;
}
