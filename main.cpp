#include <iomanip> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include "graph.h"
#include <string>
using namespace std;







int main(int argc, char* argv[]) {//algorythm, size1, size2, step, count, p, m, save, filename (sep: 0-, 1-.)
	int algorythm = 1, size1 = 10, size2 = 100, step = 1, count = 100, p = 50, m = 100, save = 1, sep=1;
	cout << argc << "; ";
	for (int i = 0; i < argc; i++) 
		cout << argv[i]<<' ';
	string filename = "test.csv";
	if (argc == 11) {
		algorythm = stoi(argv[1]);
		size1 = stoi(argv[2]);
		size2 = stoi(argv[3]);
		step = stoi(argv[4]);
		count = stoi(argv[5]);
		p = stoi(argv[6]);
		m = stoi(argv[7]);
		save = stoi(argv[8]);
		filename = (argv[9]);
		filename +=".csv";
		sep= stoi(argv[10]);

		
	}

	cout << '\n';

	ofstream MyFile(filename);
	MyFile <<( (algorythm == 1) ? "Marked algorythm;" : "3-Heap algorythm;" )<< " size : {"<<size1<<":"<<size2<<"}; step = "<<step<<"; count = "<<count<<"; p = "<<p<<"; m = "<< m<<";\n";
	for (int ii = size1; ii <size2; ii +=step) {
		auto start = std::chrono::high_resolution_clock::now();

		int size = ii;
		int p1 = p, m1 = m;

		for (int m = 0; m < count; m++) {

			graph* a = new graph(size);
			a->random(m1, p1);
			int* ans = a->Dikstra_marks();
			delete a;
			delete[] ans;
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		string tmp = to_string(duration.count()/ count);
		if(sep==0)
			tmp.replace(tmp.find("."), 1, ",");
		if (save == 0) {
			cout<< size << ';' << tmp << '\n';
		}
		else
		MyFile << size << ';' << tmp  <<'\n';
		//cout <<"size: "<<size << " time: " << duration.count() / count << " seconds" << std::endl;
	}
	MyFile.close();

	return 0;
}