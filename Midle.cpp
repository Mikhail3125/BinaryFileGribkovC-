#include "Stdafx.h"
using namespace std;

/*
������  ��������� ���������� �������� �������� �������� � �������� �� � �������� ����. ���������� 
�������� ���� ���, ����� ��� ������� ���� �������� ���������� �������. ����������� ������� �� � 
����� ��������� ������ � �����
*/
 
void Midle()
{
	cout << "\nMidle level\n";
	///224 - 255
	FILE* f_out;
	char path[] = "symbolfile";
	f_out = fopen(path, "wb");
	int count_sym = 1 + rand()%26;
	char* buffer = new char[(++count_sym)];
	//buffer[count_sym] = '\0';
	cout << "\n���������� ����� <<symbolfile.dat>> �� �������� ��������� �� ������� �������: \n";
	for (size_t i = 0; i < count_sym
		/* buffer[i] != '\0'*/; i++) 
	{
		cout << ( buffer[i] = 224 + rand() % 17) <<" ";
		
	}
	fwrite(buffer, sizeof(char), count_sym, f_out);
	fclose(f_out);

	f_out = fopen(path, "rb");
	fread(buffer, sizeof(char), count_sym, f_out);
	cout << "\n���������� ����� ����� ���������: \n";
	for (size_t i = 0; i<count_sym/*buffer[i] != '\0'*/ ; i++)
	{
		if (buffer[i] >= '�' && buffer[i] <= '�')
		{
		//	cout<< 
			(buffer[i] = (char)toupper(buffer[i]));// << " ";
		}
	}
	fclose(f_out);
	f_out = fopen(path, "w+b");
	fwrite(buffer, sizeof(char), count_sym, f_out);
	fclose(f_out);
	f_out = fopen(path, "rb");
	fread(buffer, sizeof(char), count_sym, f_out);
	for (size_t i = 0; i < count_sym; i++)
	{
		cout << buffer[i] << " ";
	}

	fclose(f_out);

}