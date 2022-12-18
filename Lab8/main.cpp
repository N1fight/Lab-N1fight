#include <iostream>

using namespace std;

int main() {
	unsigned long long a; //Занимает 8 байт
	cout << "Enter number "; cin >> a; cout << endl;

	unsigned char* p = (unsigned char*)&a; // unsigned char (диапозон значений от 0 до 255)


	for (int i = 0; i < sizeof(unsigned long long); i++)
	{
		cout << "Byte " << i << ": " << (int)p[i] << endl;
	}

	return 0;
}