#pragma once
#include<iostream>

using namespace std;



/////////////////////////////////////////////////////////ФУНКЦИИ/////////////////////////////////////////////////////

char letter[15]{ 'A','B','C','D','E','F','G','H','J','K','M','N','O','P','Q' };//координата 

int NumberOfShips[5] = { 0 };

//МЕНЮ
void menu(int& NumberOfShipCells, int& cells) {
	int N;
	cout << "# sea battle" << endl;
	cout << "выбирете формат карты \n1 - 6x6\n2 - 10x10\n3 - 15x15" << endl << "cells: ";
	cin >> N;
	if (N == 1) {
		cells = 6;
		NumberOfShipCells = 10;
		NumberOfShips[0] = 3;
		NumberOfShips[1] = 2;
		NumberOfShips[2] = 1;
		NumberOfShips[3] = 0;
		NumberOfShips[4] = 0;
	}
	if (N == 2) {
		cells = 10;
		NumberOfShipCells = 23;
		NumberOfShips[0] = 4;
		NumberOfShips[1] = 2;
		NumberOfShips[2] = 2;
		NumberOfShips[3] = 1;
		NumberOfShips[4] = 1;
	}
	if (N == 3) {
		cells = 15;
		NumberOfShipCells = 27;
		NumberOfShips[0] = 4;
		NumberOfShips[1] = 2;
		NumberOfShips[2] = 2;
		NumberOfShips[3] = 2;
		NumberOfShips[4] = 1;
	}
}
//ИНИЦИАЛИЗАЦИЯ
void init(char** arr, int cells) {
	for (int i = 0; i < cells; i++)
	{
		for (int j = 0; j < cells; j++)
		{
			arr[i][j] = '    ';
		}
	}
}
//вывод поля в консоли
void TheBattlefield(char** arr, int cells) {
	for (int c = 0; c < cells; c++)
	{
		cout << "   " << c + 1;
	}
	cout << endl;
	for (int i = 0; i < cells; i++) {
		cout << " ";
		for (int c = 0; c < cells; c++)
		{
			cout << "----";
		}
		cout << endl;
		cout << letter[i] << "| ";
		for (int j = 0; j < cells; j++)
		{
			cout << arr[i][j] << " | ";
		}
		cout << endl;


	}
	cout << " ";
	for (int c = 0; c < cells; c++)
	{
		cout << "----";
	}
	cout << endl << endl;
}
//запрос координат
void coordinate(int& num, int& numCh, int cells) {
	char ch;
	cout << endl;
	cout << "Выбирите клетку\n Номер:";
	cin >> num;
	cout << " Буква:";
	cin >> ch;
	for (numCh = 0; numCh < cells;)
	{
		if (ch == letter[numCh])return;
		numCh++;
	}
}
//присваение местоположения корабля игрока по горизонтали
void ChangingTheMapHorizon(int& num, int& numCh, int** arr, char** ShipLocation) {
	ShipLocation[numCh][num - 1] = '*';
	arr[numCh][num - 1] = 1;
	if (numCh != 0)
	{
		if (num != 1 && arr[numCh - 1][num] != 2 && arr[numCh - 1][num] != 1)
		{
			ShipLocation[numCh - 1][num] = ':';
			arr[numCh - 1][num] = 2;
		}
		if (arr[numCh - 1][num - 1] != 2 && arr[numCh - 1][num - 1] != 1)
		{
			ShipLocation[numCh - 1][num - 1] = ':';
			arr[numCh - 1][num - 1] = 2;
		}
		if (arr[numCh - 1][num - 2] != 2 && arr[numCh - 1][num - 2] != 1)
		{
			ShipLocation[numCh - 1][num - 2] = ':';
			arr[numCh - 1][num - 2] = 2;
		}

	}
	if (arr[numCh + 1][num] != 2 && arr[numCh + 1][num] != 1)
	{
		ShipLocation[numCh + 1][num] = ':';
		arr[numCh + 1][num] = 2;
	}
	if (arr[numCh + 1][num - 1] != 2 && arr[numCh + 1][num - 1] != 1)
	{
		ShipLocation[numCh + 1][num - 1] = ':';
		arr[numCh + 1][num - 1] = 2;
	}
	if (arr[numCh + 1][num - 2] != 2 && arr[numCh + 1][num - 2] != 1)
	{
		ShipLocation[numCh + 1][num - 2] = ':';
		arr[numCh + 1][num - 2] = 2;
	}
}

void MapHorizon(int num, int numCh, int** arr, char** ShipLocation) {
	if (arr[numCh][num - 1] != 2 && arr[numCh][num - 1] != 1)
	{
		arr[numCh][num - 1] = 2;
		ShipLocation[numCh][num - 1] = ':';
	}

}

//присваение местоположения корабля игрока по вертикали
void ChangingTheMapVertically(int& num, int& numCh, int** arr, char** ShipLocation) {
	ShipLocation[numCh][num - 1] = '*';
	arr[numCh][num - 1] = 1;
	if (num != 1)
	{
		if (numCh != 0 && arr[numCh - 1][num - 2] != 1 && arr[numCh - 1][num - 2] != 2)
		{


			ShipLocation[numCh - 1][num - 2] = ':';
			arr[numCh - 1][num - 2] = 2;


		}
		if (arr[numCh][num - 2] != 2 && arr[numCh][num - 2] != 1)
		{
			ShipLocation[numCh][num - 2] = ':';
			arr[numCh][num - 2] = 2;
		}
		if (arr[numCh + 1][num - 2] != 2 && arr[numCh + 1][num - 2] != 1)
		{
			ShipLocation[numCh + 1][num - 2] = ':';
			arr[numCh + 1][num - 2] = 2;
		}

	}
	if (numCh != 0 && arr[numCh - 1][num] != 1 && arr[numCh - 1][num] != 2)
	{
		ShipLocation[numCh - 1][num] = ':';
		arr[numCh - 1][num] = 2;


	}
	if (arr[numCh][num] != 1 && arr[numCh][num] != 2)
	{
		ShipLocation[numCh][num] = ':';
		arr[numCh][num] = 2;
	}
	if (arr[numCh + 1][num] != 1 && arr[numCh + 1][num] != 2)
	{
		ShipLocation[numCh + 1][num] = ':';
		arr[numCh + 1][num] = 2;
	}


}
//первые и последние точки судна

void MapVertically(int num, int numCh, int** arr, char** ShipLocation) {
	if (arr[numCh][num - 1] != 1 && arr[numCh][num - 1] != 2)
	{
		arr[numCh][num - 1] = 2;
		ShipLocation[numCh][num - 1] = ':';
	}

}

//
//присваение местополажения корабля противника
void initVrag(int** arr, int NumberOfShipCells, int cells) {
	bool boo = 0;
	int I = 0;
	int J = 0;
	for (int i = 0; i < NumberOfShipCells; i++)
	{
		do
		{
			I = rand() % cells;
			J = rand() % cells;
			if (arr[I][J] == 1)boo = 1;
			if (arr[I][J] != 1) {
				arr[I][J] = 1;
				boo = 0;
			}
		} while (boo == 1);
	}
}
//вычисление местоположения корабля по заданным координатам
void TheMap(int& boi, bool& ohered, int** arr, char** ShipLocation, int num, int numCh) {
	if (arr[numCh][num - 1] == 1)
	{
		ShipLocation[numCh][num - 1] = 'X';
		ohered = 1;
		boi++;
	}
	if (arr[numCh][num - 1] != 1)
	{
		ShipLocation[numCh][num - 1] = '.';
		ohered = 0;
	}

}
//ход противника
void VragIded(int& boiS, bool& Och, char** ShipLocation, int** arr, int cells) {
	int r = 0;
	int num = 0;
	int numCh = 0;
	do {
		r == 0;
		num = rand() % cells;
		numCh = rand() % cells;
		if (ShipLocation[numCh][num] != 'X')
		{
			if (arr[numCh][num] == 1)
			{
				ShipLocation[numCh][num] = 'X';
				Och = 1;
				boiS++;
			}
			if (arr[numCh][num] != 1)
			{
				ShipLocation[numCh][num] = '.';
				Och = 0;
			}
			r = 1;
		}
	} while (r == 0);


}

//отчистка поля от ненужной информации
void ClearingTheField(int** arr, char** ShipLocation, int sz) {
	for (size_t i = 0; i < sz; i++)
	{
		for (size_t j = 0; j < sz; j++)
		{
			if (arr[i][j] == 2)
			{
				arr[i][j] = 0;
				ShipLocation[i][j] = '    ';
			}
		}
	}
}
