#include <iostream>
#include <chrono>

using namespace std;

int main() {
	
	const int max = 10000;
	
	int **mat = new int*[max];
	for (int i = 0; i < max; ++i)
		mat[i] = new int[max];
	
	int *x = new int[max];
	int *y = new int[max] {0};
	
	
	
	int **mat2 = new int*[max];
	for (int i = 0; i < max; ++i)
		mat2[i] = new int[max];
	
	int *x2 = new int[max];
	int *y2 = new int[max] {0};
	
	
	
	auto start = chrono::steady_clock::now();
	
	for (int i = 0; i < max; ++i){
		for (int j = 0; j < max; ++j){
		y[i] += mat[i][j] * x[j];
		}
	}
	
	
	auto end = chrono::steady_clock::now();
	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	
	
	
	
	start = chrono::steady_clock::now();
	
	for (int j = 0; j < max; ++j){
		for (int i = 0; i < max; ++i){
			y2[i] += mat2[i][j] * x2[j];
		}
	}
	
	end = chrono::steady_clock::now();
	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	
	
}
