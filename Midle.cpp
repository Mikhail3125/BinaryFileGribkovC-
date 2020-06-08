#include "Stdafx.h"
using namespace std;

/*
Ввести  некоторое количество символов русского алфавита и записать их в бинарный файл. Переписать 
бинарный файл так, чтобы все символы были записаны прописными буквами. Распечатать символы до и 
после изменения данных в файле
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
	cout << "\nÑîäåðæèìîå ôàéëà <<symbolfile.dat>> äî âíåñåíèÿ èçìåíåíèé ïî óñëîâèÿ çàäàíèÿ: \n";
	for (size_t i = 0; i < count_sym
		/* buffer[i] != '\0'*/; i++) 
	{
		cout << ( buffer[i] = 224 + rand() % 17) <<" ";
		
	}
	fwrite(buffer, sizeof(char), count_sym, f_out);
	fclose(f_out);

	f_out = fopen(path, "rb");
	fread(buffer, sizeof(char), count_sym, f_out);
	cout << "\nÑàäåðæèìîå ôàéëà ïîñëå èçìåíåíèé: \n";
	for (size_t i = 0; i<count_sym/*buffer[i] != '\0'*/ ; i++)
	{
		if (buffer[i] >= 'à' && buffer[i] <= 'ÿ')
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
