#include"Stdafx.h"
using namespace std;

/*
Создать бинарный файл, компонентами которого является структура, содержащая  следующие поля: 
	 фамилия и инициалы покупателя; 
	 дата покупки; 
	 общая стоимость приобретенного товара;
	 начальный процент скидки на последующие приобретаемые товары. 
Переписать бинарный файл так, чтобы процентная скидка была бы увеличена на 5%, если покупатель
заплатил за предыдущий товар 5000 грн
*/
#ifndef _customer
#define _customer
struct Сustomer // Покупатель
{
	string		   fio;				 //	фамилия и инициалы покупателя; 
	int		   date;			//дата покупки
	unsigned int   total_coast;    //общая стоимость приобретенного товара
	unsigned short start_discount;//начальный процент скидки на последующие приобретаемые товары
} dat;
#endif // !_customer
void CheckDigit(int& anydigit);

Book* FillStruct(Сustomer* mas_book, int count)  //Всего лишь заполняет масив структур
{
	if (mas_book == nullptr)
		mas_book = new Book[count];
	for (size_t i = 0; i < count; i++)
	{
		mas_Сustomer[i].fio  = "FIO" + to_string(i+1);
		mas_Сustomer[i].date =   "date" + to_string(i + 1);
		mas_Сustomer[i].total_coast       =  100 + rand() % 1000;
		mas_Сustomer[i].start_discount      =  1 + rand() % 100;
	}
	return mas_Сustomer;
} 
void ShowBooks(Сustomer* mas_books, int count)
{
	cout << "\nИнформация о всех книах: \n";
	for (size_t i = 0; i < count; i++)
	{
		printf("\nИнформация о %d книге: \n\t", i + 1);
		cout << mas_Сustomer[i].fio << " " ;
		cout << mas_Сustomer[i].date << " ";
		cout << mas_Сustomer[i].total_coast << " " ;
		cout << mas_Сustomer[i].total_coast << "\n";
	}
}
Book* LoadFile( int count)  //Прочитать данные с файла
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Сustomer* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Сustomer));
	f_in.close();
	return buffer;
}
void SaveFile(Сustomer* mas_book, int count)
{
	ofstream f_out; f_out.open("database.bin", ios::binary | ios::out);
	int BufferSize = count * sizeof(Book);
	f_out.write((char*)mas_book, BufferSize);
	f_out.close();
}
int IsSetDiscount(int count) //Установление скидки если соблюдается условие 
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in );
	Сustomer* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Сustomer));
	f_in.close();
	for (size_t i = 0; i < count; i++)
	{
		if (buffer[i].count > 20)
		{
			buffer[i].cost -= buffer[i].cost * 0.05;
		}
	}
	SaveFile(buffer, count);
	return 0;
}
void hard_task()
{
	cout << "\nHard task level: \n";
	int count = 10;
	Сustomer* mas_book = new Сustomer[count];
	mas_Сustomer = FillStruct(mas_Сustomer, count);
	SaveFile(mas_Сustomer, count);
	mas_book = LoadFile( count);
	cout << "\nСодержимое файла до внесенных изминений: \n";
	cout << "\nВ файле хранится масив структур содержащих следущие поля: \n";
	cout << "\t-ФИО автора\n\t-название книги\n\t-цена за ед.\n\t-количетсво экзэмпляров";
	ShowBooks(mas_Сustomer, count);
	cout << "\nСодержимое файла после внесенных изминений: ";
	 IsSetDiscount(count);
	Сustomer* buffer = new Book[count];
	buffer = LoadFile(count);
	SaveFile(buffer, count);
	ShowСustomer(buffer, count);
	cout << "\nНажмите <Enter> для завершения...";
	while (getchar() != '\n')
		continue;
}
void CheckDigit(int& anydigit)
{
	while (true)
	{
		cin >> anydigit;
		if (!cin.good() || cin.fail())
		{
			cin.clear();
			cin.ignore(32567, '\n');
			cout << "\nВведите коректное числовое значение...\n";
			cout << "\nПовторите ввод: ";
		}
		break;
	}
}
