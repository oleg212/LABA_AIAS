#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int index;
    int distance;
    node(int i=0, int d=0) : index(i), distance(d) {
    }
    node(const node& other)
    {
        index = other.index;
        distance = other.distance;
    }
    node& operator=(const node& x) {
        index = x.index;
        distance = x.distance;
        return *this;
    }
    bool operator<(const node& other) const {
        if (distance == -1) {// (-1) - типа бесконечность
            if (other.distance == -1) return false;
            else return true;
        }
        if (other.distance == -1) return false;
        return distance < other.distance;
    }
    bool operator<=(const node& other) const {
        if ((distance == other.distance))
            return true;
        else 
            return (*this < other);
    }
    bool operator>=(const node& other) const {
        return !(*this < other);
    }
    bool operator>(const node& other) const {
        
        return !(*this<=other);
    }
};


class TernaryHeap {
private:
    vector<node> heap; // Вектор для хранения элементов 3-кучи
    int heapSize;
    void emerge(int ind) {
        int p = parent(ind);
        while ((ind != 0) && (heap[ind] < heap[p])) {
            tr(ind, p);
            ind = p;
            p = parent(ind);
        }
    }
    int minchild(int ind) {
        int ch = child(ind);
        int tmp = heapSize - ch;
        int min = -1;
        if (tmp < 1)return min;
        if (tmp == 1) min = ch;
        else {
            if (tmp == 2) {
                if (heap[ch] < heap[ch + 1]) min = ch;
                else min = ch + 1;
            }
            else {
                if ((heap[ch] <= heap[ch + 1]) && (heap[ch] <= heap[ch + 2])) min = ch;
                else {
                    if ((heap[ch + 1] <= heap[ch]) && (heap[ch + 1] <= heap[ch + 2])) min = ch + 1;
                    else min = ch + 2;
                }
            }
        }
        return min;
    }

    void submerge(int ind) {
        int min = minchild(ind);
        while ((min != -1)&&(heap[ind]>heap[min])) {
            tr(min, ind);
            ind = min;
            min = minchild(min);

        }
    }
    int parent(int ind) {
        return (ind - 1) / 3;
    }
    int child(int ind) {
        return (ind) * 3 + 1;
    }
    void tr(int i, int j) {
        node tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
    void del(int ind) {
        heap[ind] = heap[heapSize-1];
        heapSize--;
        heap.pop_back();
        if ((ind != 0) && (heap[ind] < heap[parent(ind)])) emerge(ind);
        else submerge(ind);
    }
public:
    TernaryHeap() {
        heap = vector<node>(0);
        heapSize = 0;
    }
    bool empty() {
        return heapSize == 0;
    }
    void insert(node n) {
        heap.push_back(n);
        emerge(heapSize++);
    }
    void insert(int ind, int d) {
        node n = node(ind, d);
        heap.push_back(n);
        emerge(heapSize++);
    }
    node pop_min() {
        if (heapSize == 0) throw - 1;
        node ans = heap[0];
        del(0);
        return ans;
    }
    int pop_min_int() {
        if (heapSize == 0) throw - 1;
        int ans = heap[0].index;
        del(0);
        return ans;
    }
};