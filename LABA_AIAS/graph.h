#pragma once

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip> 
#include "matrix.h"
#include "heap.h"

class graph {
private:
	int size;
	matrix* m;

public:

	graph(int _size=1):	size(_size)	{
		m = new matrix(size);	
	}

	void random(int _m = 10, int _p = 50) {
		m->random(_m, _p);		
	}

	void empty() {
		m->empty();
	}

	~graph() {
		delete m;
	}

	friend ostream& operator <<(ostream& out, graph& g) {
		out << *(g.m) << '\n';
		return out;
	}

	int* Dikstra_marks(int p=0) {
		int size = m->get_size();
		int* ans = new int[size];
		int* d = new int[size]; // метки
		int* v = new int[size]; // посещенные вершины
		int cur = p;
		for (int i = 0; i < size; i++)
		{
			d[i] = -1;
			v[i] = 1;
		}
		int left = size;
		d[cur] = 0;
		while (left > 0)
		{
			for (int j = 0; j < size; j++) {
				int tmp = m->get(cur, j);
				if (tmp > 0) {
					if (d[j] != -1) {
						d[j] = min(d[j], d[cur] + tmp);
					}
					else d[j] = d[cur] + tmp;
				}
			}
			v[cur] = 0;
			left--;
			int min = 99999999;
			for (int j = 0; j < size; j++) {
				if (v[j] && (d[j] != -1)) {
					if (min > d[j]) {
						min = d[j];
						cur = j;
					}
				}
			}
		}
		return d;
	}
	int* Dikstra_heap(int p = 0) {
		int size = m->get_size();
		bool* up = new bool[size];
		int* dist = new int[size];
		TernaryHeap* heap = new TernaryHeap(size);
		for (int i = 0; i < size; i++) {
			up[i] = false;
			dist[i] = 9999999;
			heap->insert(i, 9999999);
		}
		dist[p] = 0;
		heap->insert(p, 0);
		int delta, tmp,r0;
		while (!heap->empty()) {
			r0 = heap->pop_min_int();
			if (up[r0]) continue;
			up[r0] = true;
			for (int i = 0; i < size; i++) {
				if (m->get(r0, i) > 0) {
					int newDist = dist[r0] + m->get(r0, i);
					if (newDist < dist[i]) {
						dist[i] = newDist; 
						heap->insert(i, newDist);
					}
				}
			}
		}
		delete heap;
		return dist;

		
	}
	//int* Dikstra_heap(int p=0, int c=10, int l=5) {
	//	int size = m->get_size();
	//	int* d = new int[size]; // метки
	//	int* v = new int[size]; // посещенные вершины
	//	int cur = p;
	//	TernaryHeap* heap = new TernaryHeap(size, c ,l);
	//	heap->insert(cur, 0);
	//	for (int i = 0; i < size; i++)
	//	{
	//		d[i] = -1;
	//		v[i] = 1;
	//	}
	//	d[p] = 0;
	//	int left = size;
	//	d[cur] = 0;



	//	while (!heap->empty())
	//	{
	//		for (int j = 0; j < size; j++) {
	//			int tmp = m->get(cur, j);
	//			if (tmp > 0) {
	//				int dj = d[j];
	//				if ((dj == -1) || (dj > d[cur] + tmp)) {
	//					d[j] = d[cur] + tmp;
	//					heap->insert(j, d[j]);
	//				}
	//			}
	//		}
	//		v[cur] = 0;
	//		left--;
	//		while ((v[cur] == 0) && (!heap->empty()))
	//			cur = heap->pop_min_int();
	//	}
	//	delete heap;
	//	return d;
	//}

};