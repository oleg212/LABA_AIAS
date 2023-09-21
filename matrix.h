#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 

using namespace std;

class matrix {
	int size;
	int** m;
public:
	matrix(int _size) : size(_size) {
		m = new int* [size];
		for (int i = 0; i < size; i++) {
			m[i] = new int[i + 1];
			m[i][i] = 0;
		}
	}
	int& get(int x, int y) {
		int& a = m[max(x, y)][min(x, y)];
		return a;
	}
	void random(int m = 10, int p = 50) {//m - максимальная длина пути, p плотность от 0 до 100
		srand(time(nullptr));
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				int a = rand() % 100;
				if (a <= p) {
					get(i, j) = rand() % (m - 1) + 1;
				}
				else {
					get(i, j) = -1;
				}
			}
		}
	}
	void empty() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				get(i, j) = -1;
			}
		}
	}
	friend ostream& operator <<(ostream& out, matrix& v) {
		out << setw(4) << " ";
		for (int i = 1; i < v.size + 1; i++) {
			out << setw(4) << i << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < v.size; i++) {
			out << setw(4) << i + 1;
			for (int j = 0; j < v.size; j++) {

				out << setw(4) << v.get(i, j) << " ";
			}
			std::cout << std::endl;
		}
		return out;
	}
	int get_size() {
		return size;
	}
	~matrix() {
		for (int i = 0; i < size; i++) {
			delete[] m[i];
		}
		delete[] m;
	}
};