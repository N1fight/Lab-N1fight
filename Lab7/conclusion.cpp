#include <iostream>


void conclusion(int n, int matrix[100][100])
{

	std::cout << "Измененная матрица:" << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}