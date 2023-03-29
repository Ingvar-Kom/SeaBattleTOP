#include <iostream>
#include <Windows.h>
#include "BattleFoo.h"
#include <mmsystem.h>
#include <stdlib.h>
#include <fstream>
#include <locale>
#include <cctype>
#include<conio.h>

//#pragma comment(lib, "winmm.lib")

using namespace std;


//COLOR
template<int txt = 7, int bg = 0>
ostream& color(ostream& text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}



//////////MAIN///////////
int main()
{
	//ПОДКЛЮЧЕНИЕ РУССКОГО ЯЗЫКА
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	//размер карты
	int cells = 0;
	///ПЕРЕМЕННЫЕ/////
	//координаты (x,y)
	int X = 0;//номера
	int Y = 0;//буквы
	//
	//переменная для хранения количества точек(клеток кораблей)
	int NumberOfShipCells = 0;
	//
	//переменные
	bool def = 0;
	int NumS;
	int vsegoShip = 10;
	int rund = 0;
	int bo = 0;
	int boq = 0;
	bool ohered = 0;
	bool oheredV = 0;
	//
	//переменная с путём к аудео файлу
	//wchar_t nyTb[] = L"G.wav";
	//wchar_t nyTbpobed[] = L"B.wav";
	//wchar_t nyTbover[] = L"F.wav";
	//wchar_t nyTbM[] = L"MENU.wav";
	//
	//
	//int num;
	char ch = ' ';
	int numCh = 0;
	//
	//по горезонтали/по вертикали
	int coor = 0;
	///местоположения флота игрока
	//переменная отабражения локации кораблей игрока
	//char PlayerShipLocation[15][15];
	char** PlayerShipLocation = new char* [15];
	for (int i = 0; i < 15; i++)PlayerShipLocation[i] = new char[15];

	//переменная для хранения номера расположения корабля игрока
	//int PlayerShipLocationNumber[15][15] = { 0 };
	int** PlayerShipLocationNumber = new int* [15];
	for (int i = 0; i < 15; i++)PlayerShipLocationNumber[i] = new int[15];
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			PlayerShipLocationNumber[i][j] = 0;
		}
	}
	//
	///местоположение флота противника
	//переменная отаброжения локации кораблей противника
	//char EnemyShipLocation[15][15];
	char** EnemyShipLocation = new char* [15];
	for (int i = 0; i < 15; i++)EnemyShipLocation[i] = new char[15];
	//переменная для хранения номера располажения корабля противника
	//int EnemyShipLocationNumber[15][15] = { 0 };
	int** EnemyShipLocationNumber = new int* [15];
	for (int i = 0; i < 15; i++)EnemyShipLocationNumber[i] = new int[15];
	//
	// эмитация загрузки
	string h = "###############################################";
	/////////////////////////////////////////////////////////////////////////////////////////




	//ДИСКЛЕЙМЕР
	cout << color<4, 0> << "\t\t\t  !ВНИМАНИЕ!" << color<2, 0> \
		<< "\n\tрасстановка кораблей (с верху в низ\\с лева на право)\n ввод координат по оси Y производится Английскими заглавными буквами" << color << endl\
		<< color<6, 0> << "\t  БУДЬТЕ ВНЕМАТЕЛЬНЫ ПРИ РАССТАНОВКИ КОРАБЛЕЙ!" << color << endl;
	system("pause>0");
	//system("cls");
	//////////СЩЗДАНИЕ ПОЛЕЙ/////////

	////////МЕНЮ/выбор режима игры/выбор размера карты/////////
	menu(NumberOfShipCells, cells);
	///////////////////////////////////////////////////////////
	//вычисление общего количества кораблей
	vsegoShip = NumberOfShips[0] + NumberOfShips[1] + NumberOfShips[2] + NumberOfShips[3] + NumberOfShips[4];


	//создание поля игрока
	init(PlayerShipLocation, cells);
	//создание поля противника
	init(EnemyShipLocation, cells);
	/////////////////////////////////

	//PlaySound(nyTbM, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//system("cls");
	//расстановка кораблей игрока
	bool cook = 0;
	for (int i = 0; i < vsegoShip; i++)
	{
		bool CHPOK = 0;
		//вывод количества кораблей
		system("cls");
		TheBattlefield(PlayerShipLocation, cells);
		cout << "\nВаш флот" << endl;
		cout\
			<< " 1 " << " однопалубные" << "      кол-во: " << NumberOfShips[0] << endl\
			<< " 2 " << " двухпалубные" << "      кол-во: " << NumberOfShips[1] << endl\
			<< " 3 " << " трёхпалубные" << "      кол-во: " << NumberOfShips[2] << endl\
			<< " 4 " << " четырёхпалубные" << "   кол-во: " << NumberOfShips[3] << endl\
			<< " 5 " << " пятипалубные" << "      кол-во: " << NumberOfShips[4] << endl\
			<< endl << endl;
		do
		{
			cook = 0;
			cout << "Выбирите номер корабля: ";
			cin >> NumS;
			if (NumberOfShips[NumS - 1] == 0)
			{
				cout << color<4, 0> << "\nэти корабли закончились\n" << color;
				cook = 1;
			}
		} while (cook);

		//растановка однопалубного корабля
		if (NumS == 1)
		{

			system("cls");
			for (size_t i = 0; i < 1; i++)
			{

				TheBattlefield(PlayerShipLocation, cells);
				do
				{
					CHPOK = 0;
					coordinate(X, Y, cells);
					if (PlayerShipLocationNumber[Y][X - 1] == 1)
					{
						cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
						system("pause>0");
						CHPOK = 1;
					}
					if (PlayerShipLocationNumber[Y][X - 1] == 2)
					{
						cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
						system("pause>0");
						CHPOK = 1;
					}
				} while (CHPOK == 1);
				if (Y != 0)
				{
					MapVertically(X, Y - 1, PlayerShipLocationNumber, PlayerShipLocation);
				}
				ChangingTheMapVertically(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
				MapVertically(X, Y + 1, PlayerShipLocationNumber, PlayerShipLocation);


				//ChangingTheMap
			}
			NumberOfShips[0]--;
		}
		//расстановка двухпалубного корабля
		if (NumS == 2)
		{

			system("cls");
			cout << "1 по вертикали\n2 по горизонтали\nвертеь в: ";
			cin >> coor;
			for (size_t i = 0; i < 2; i++)
			{
				system("cls");

				if (coor == 1)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if (Y == cells - 1 && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y - 1][X - 1] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && Y != 0)MapVertically(X, Y - 1, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapVertically(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 1)MapVertically(X, Y + 1, PlayerShipLocationNumber, PlayerShipLocation);
				}
				if (coor == 2)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if (X == cells && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y][X - 2] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && X != 1)MapHorizon(X - 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapHorizon(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 1)MapHorizon(X + 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
				}

			}
			NumberOfShips[1]--;
		}
		//расстановка трёхпалубного корабля
		if (NumS == 3)
		{

			system("cls");
			cout << "1 по вертикали\n2 по горизонтали\nвертеь в: ";
			cin >> coor;
			for (size_t i = 0; i < 3; i++)
			{
				system("cls");
				if (coor == 1)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((Y + 1 == cells - 1 || Y == cells - 1) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y - 1][X - 1] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && Y != 0)MapVertically(X, Y - 1, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapVertically(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 2)MapVertically(X, Y + 1, PlayerShipLocationNumber, PlayerShipLocation);
				}
				if (coor == 2)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((X + 1 == cells || X == cells) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y][X - 2] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && X != 1)MapHorizon(X - 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapHorizon(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 2)MapHorizon(X + 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
				}

			}
			NumberOfShips[2]--;
		}
		//расстановка четырёхпалубного корабля
		if (NumS == 4)
		{

			system("cls");
			cout << "1 по вертикали\n2 по горизонтали\nвертеь в: ";
			cin >> coor;
			for (size_t i = 0; i < 4; i++)
			{
				system("cls");
				if (coor == 1)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((Y + 2 == cells - 1 || Y + 1 == cells - 1 || Y == cells - 1) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y - 1][X - 1] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && Y != 0)MapVertically(X, Y - 1, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapVertically(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 3)MapVertically(X, Y + 1, PlayerShipLocationNumber, PlayerShipLocation);
				}
				if (coor == 2)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((X + 2 == cells || X + 1 == cells || X == cells) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y][X - 2] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && X != 1)MapHorizon(X - 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapHorizon(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 3)MapHorizon(X + 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
				}

			}
			NumberOfShips[3]--;
		}
		//расстановка петипалубного корабля
		if (NumS == 5)
		{
			system("cls");
			cout << "1 по вертикали\n2 по горизонтали\nвертеь в: ";
			cin >> coor;
			for (size_t i = 0; i < 5; i++)
			{
				system("cls");
				if (coor == 1)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((Y + 3 == cells - 1 || Y + 2 == cells - 1 || Y + 1 == cells - 1 || Y == cells - 1) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y - 1][X - 1] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && Y != 0)MapVertically(X, Y - 1, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapVertically(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 4)MapVertically(X, Y + 1, PlayerShipLocationNumber, PlayerShipLocation);
				}
				if (coor == 2)
				{
					TheBattlefield(PlayerShipLocation, cells);
					do
					{
						CHPOK = 0;
						coordinate(X, Y, cells);
						if ((X + 3 == cells || X + 2 == cells || X + 1 == cells || X == cells) && i == 0)
						{
							cout << endl << color < 4, 0> << "судно здесь не поместится" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (i > 0 && PlayerShipLocationNumber[Y][X - 2] != 1)
						{
							cout << endl << color < 4, 0> << "нельзя разчелинять судно" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 1)
						{
							cout << endl << color < 4, 0> << "тут уже что то стоит" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
						if (PlayerShipLocationNumber[Y][X - 1] == 2)
						{
							cout << endl << color < 4, 0> << "нельзя так близко расставлять корабли" << color << endl;
							system("pause>0");
							CHPOK = 1;
						}
					} while (CHPOK == 1);
					if (i == 0 && X != 1)MapHorizon(X - 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
					ChangingTheMapHorizon(X, Y, PlayerShipLocationNumber, PlayerShipLocation);
					if (i == 4)MapHorizon(X + 1, Y, PlayerShipLocationNumber, PlayerShipLocation);
				}

			}
			NumberOfShips[4]--;
		}
	}
	//отчистка поля
	ClearingTheField(PlayerShipLocationNumber, PlayerShipLocation, cells);
	//растановка кораблей противника
	initVrag(EnemyShipLocationNumber, NumberOfShipCells, cells);


	//ПРЕДУПРЕЖДЕНИЕ
	cout << endl;
	cout << color<4, 0> << "ВНИМАНИЕ!\nбой может работать не коректно\nпротивник может раставляеть корабли не по правилам " << color << endl;
	Sleep(4000);

	//ПОДКЛЮЧЕНИЯ МУЗЫКИ
	//PlaySound(nyTb, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//бой
	bool doo = 0;
	do
	{
		system("cls");
		cout << color<5, 0> << "ВАШЕ ПОЛЕ" << color << endl;
		TheBattlefield(PlayerShipLocation, cells);
		cout << color<5, 0> << "ПОЛЕ ПРОТИВНИКА" << color << endl;
		TheBattlefield(EnemyShipLocation, cells);
		do
		{
			do
			{
				doo = 0;
				coordinate(X, Y, cells);      //ЗАПРОС КААРДИНАТ
				if (EnemyShipLocation[Y][X - 1] == 'X' || EnemyShipLocation[Y][X - 1] == '.') {
					cout << endl << color<4, 0> << "\n!!!туда уже стреляли!!!" << color << endl;
					doo = 1;
				}
			} while (doo == 1);

			TheMap(bo, ohered, EnemyShipLocationNumber, EnemyShipLocation, X, Y);   //ПРИСВОЕНИЕ КААРДИНАТ НА КАРТЕ
			if (ohered)cout << endl << color<2, 0> << "\n\tВЫ ПОПАЛИ ПО КОРАБЛЮ ПРОТИВНИКА" << color << endl;
			if (!ohered)cout << endl << color<11, 0> << "\n\tПРОМАХ" << color << endl;
		} while (ohered);
		//УВЕДОМЛЕНИЕ О ПОБЕДЕ
		if (bo == NumberOfShipCells) {
			system("cls");
			cout << color<2, 0> << "ВЫ ВЫЙГРАЛИ" << color << endl;
			//PlaySound(nyTbpobed, NULL, NULL);
			Sleep(4000);//иначе выход из цыкла не работает
			rund = 1;
			exit(0);
		}

		do
		{
			cout << "\nХОД ПРОТИВНИКА\n";
			for (int i = 0; i < h.length(); i++)
			{
				Sleep(50);
				cout << h[i];
			}
			cout << endl;
			VragIded(boq, ohered, PlayerShipLocation, PlayerShipLocationNumber, cells);//ХОД ПРОТИВНИКА
			if (ohered)
			{
				cout << endl << color<11, 0> << "\n\tПО ВАШЕМУ СУДНУ ПОПАЛИ" << color << endl;
			}
		} while (ohered);
		//УВЕДОМЛЕНИЕ О ПРОИГРЕШЕ
		if (boq == NumberOfShipCells) {
			system("cls");
			cout << color<4, 0> << "ВЫ ПРОИГРАЛИ" << color << endl;
			//PlaySound(nyTbover, NULL, NULL);
			Sleep(4000);//иначе выход из цыкла не работает
			rund = 1;
			exit(0);
		}
	} while (rund == 0);

	system("pause>0");
	return 0;
}