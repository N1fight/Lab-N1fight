#include <iostream>

using namespace std;

void read(int& n, int matrix[100][100]) 
{

	setlocale(LC_ALL, "Russian");


	cout << "¬ведите размер матрицы: "; cin >> n; cout << endl; cout << "¬ведите матрицу:" << endl;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> matrix[i][j];
		}
	}

}
