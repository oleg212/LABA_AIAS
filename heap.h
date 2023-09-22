#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int index;
    int distance;
    node(int i=0, int d=0) : index(i), distance(d) {
    }

    node& operator=(const node& x) {
        node a(x.index, x.distance);
        return a;
    }
    bool operator<(const node& other) const {
        if (distance == -1) {// (-1) - типа бесконечность
            if (other.distance == -1) return false;
            else return true;
        }
        if (other.distance == -1) return false;
        return distance < other.distance;
    }
    bool operator>(const node& other) const {
        
        return !(*this<other);
    }
};

#include <iostream>
#include <vector>

class TernaryHeap {
private:
    std::vector<node> heap; // Вектор для хранения элементов 3-кучи
    int heapSize;
public:
    TernaryHeap() {
        heap = vector<node>();
        heapSize = 0;
    }
    bool empty() {
        return heapSize==0;
    }
    void insert(int _index, int _distance) {
        heap.push_back(node(_index,_distance));
        floatUp(heapSize);
        heapSize++;
    }
    int extractMin()
    {
        int min = heap[0].index;

        if (min == 99) {
            int a = 1;
        }

        heapSize -= 1;
        node tmp= heap[heapSize];
        heap[0].index = tmp.index;
        heap[0].distance = tmp.distance;
        heap.pop_back();
        if (heapSize)
        sinkDown(0);
        return min;

    };

    void floatUp(int currIndex)
    {

        if (currIndex == 0)
        {
            return;
        }


        int parentPosition = (currIndex - 1) / 3;

        if (heap[currIndex] < heap[parentPosition])
        {
            node temp = heap[currIndex];
            heap[currIndex] = heap[parentPosition];
            heap[parentPosition] = temp;
            floatUp(parentPosition);
        }
    };

    void sinkDown(int currentIndex)
    {   
        int left = 3 * currentIndex + 1;
        int mid = 3 * currentIndex + 2;
        int right = 3 * currentIndex + 3;

        int min = currentIndex;
        //node tmp1 = heap[min];
        //node tmp2 = heap[left];


        if (left < heapSize && heap[left] < heap[min])
        {
            min = left;
        }
        if (right < heapSize && heap[right] < heap[min])
        {
            min = right;
        }
        if (mid < heapSize && heap[mid] < heap[min])
        {
            min = mid;
        }

        node temp = heap[min];
        heap[min].index = heap[currentIndex].index;
        heap[min].distance = heap[currentIndex].distance;
        heap[currentIndex].index = temp.index;
        heap[currentIndex].distance = temp.distance;

        if (min != currentIndex)
        {
            sinkDown(min);
        }
    };
};