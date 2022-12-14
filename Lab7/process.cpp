#include "Header.h"
#include <iostream>

void process(int n, int matrix[100][100])
{
	int massive[3] = { 1, 0, 0 };
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i] == 3)
		{
			massive[1] = 1;
		}
		if (matrix[i][i] == 5)
		{
			massive[2] = 1;
		}
		if (matrix[i][i] < 0)
		{
			massive[0] = 0;
		}
	}
	int indexI = -1;
	int indexJ = -1;
	if (massive[0] + massive[1] + massive[2] == 3)
	{
		for (int i = 0; i < n; i++)
		{
			int min = matrix[i][0];
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] < min)
				{
					min = matrix[i][j];
					indexI = i;
					indexJ = j;
				}
			}
		}
	}
	int Summatrix = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Summatrix = Summatrix + matrix[i][j] * matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[indexI][indexJ] == Summatrix;
		}
	}
	
}