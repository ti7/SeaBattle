#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <clocale>
#include <windows.h>
#include <math.h>

using namespace std;

const int SZ = 10;
const int NUMSHIPS = 9;
int shipsId = 1;
int ships[10] = { 0 };

void gotoxy(int x, int y)
{
	COORD p = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void shipShow(int x, int y, int dir, int sizeShip)
{
	for (int i = 0; i < sizeShip; i++)
	{
		gotoxy(x+1, y+1);
		cout << '#';
		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		}
	}
}

bool shipInMap(int x, int y, int dir, int sizeShip)
{
	bool inMap = 1;

	for (int i = 0; i < sizeShip; i++)
	{
		if (x < 0 || y < 0 || x >= SZ || y >= SZ)
		{
			inMap = 0;
			break;
		}

		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		}
	}
	return inMap;
}

bool setShip(int map[SZ][SZ], int x, int y, int dir, int sizeShip) 
{
	int temp_x = x;
	int temp_y = y;

	bool settinIsPossible = 1;

	for (int i = 0; i < sizeShip; i++)
	{
		if (x < 0 || y < 0 || x >= SZ || y >= SZ)
		{
			settinIsPossible = 0;
			break;
		}

		/*if (map[x][y] >= 1 ||
			map[x][y + 1] >= 1 ||
			map[x][y - 1] >= 1 ||
			map[x + 1][y] >= 1 ||
			map[x + 1][y + 1] >= 1 ||
			map[x + 1][y - 1] >= 1 ||
			map[x - 1][y] >= 1 ||
			map[x - 1][y + 1] >= 1 ||
			map[x - 1][y - 1] >= 1)
		{
			settinIsPossible = 0;
			break;
		}*/

		if (map[x][y] >= 1)
		{
			settinIsPossible = 0;
			break;
		}

		if (y < SZ - 1) 
		{
			if (map[x ][y+1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (y > 0)
		{
			if (map[x ][y - 1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (x < SZ-1)
		{
			if (map[x+1][y] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (x < SZ - 1 && y < SZ -1)
		{
			if (map[x + 1][y+1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (x < SZ - 1 && y > 0)
		{
			if (map[x + 1][y - 1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (x > 0)
		{
			if (map[x - 1][y] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		if (x > 0 && y  > 0)
		{
			if (map[x - 1][y-1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}
		}

		switch (dir)
		{
		case 0:
			x++;
			break;
		case 1:
			y++;
			break;
		case 2:
			x--;
			break;
		case 3:
			y--;
			break;
		}
	}
	if (settinIsPossible == 1)
	{
		x = temp_x;
		y = temp_y;

		for (int i = 0; i < sizeShip; i++)
		{
			map[x][y] = shipsId;

			switch (dir)
			{
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
		}
		ships[shipsId] = sizeShip;
		shipsId++;
		
	}
	return settinIsPossible;
}

void setShipRandom(int map[SZ][SZ], int sizeShip, int shipsIdNew) // Установко кораблей автоматически рандомно
{
	int x, y;
	int dir = 0;
	int countShip = 0;
	int countTact = 0;

	while (countShip < 1)
	{
		countTact++;
		if (countTact > 1000)
			break;

		x = rand() % SZ;
		y = rand() % SZ;

		int temp_x = x;
		int temp_y = y;

		bool settinIsPossible = 1;
				
		for (int i = 0; i < sizeShip; i++)
		{
			if (x < 0 || y < 0 || x >= SZ || y >= SZ)
			{
				settinIsPossible = 0;
				break;
			}

			if (map[x][y] >= 1 ||
				map[x][y + 1] >= 1 ||
				map[x][y - 1] >= 1 ||
				map[x + 1][y] >= 1 ||
				map[x + 1][y + 1] >= 1 ||
				map[x + 1][y - 1] >= 1 ||
				map[x - 1][y] >= 1 ||
				map[x - 1][y + 1] >= 1 ||
				map[x - 1][y - 1] >= 1)
			{
				settinIsPossible = 0;
				break;
			}

			switch (dir)
			{
			case 0:
				x++;
				break;
			case 1:
				y++;
				break;
			case 2:
				x--;
				break;
			case 3:
				y--;
				break;
			}
		}
		if (settinIsPossible == 1)
		{
			x = temp_x;
			y = temp_y;

			for (int i = 0; i < sizeShip; i++)
			{
				map[x][y] = shipsIdNew;

				switch (dir)
				{
				case 0:
					x++;
					break;
				case 1:
					y++;
					break;
				case 2:
					x--;
					break;
				case 3:
					y--;
					break;
				}
			}
			/*ships[shipsId] = sizeShip;*/

			/*shipsId++;*/
			countShip++;
		}
	}
}

void mapShow(int map[SZ][SZ], int mask[SZ][SZ], bool useMask) // Показать поле
{
	cout << ' ';
	for (int i = 0; i < SZ; i++)
	{
		cout << i;
	}

	cout << endl;

	for (int i = 0; i < SZ; i++)
	{
		cout << i;

		for (int j = 0; j < SZ; j++)
		{
			//if (mask[j][i] == 1 || useMask == 0) // Вкл, выкючить туман войны
			{
				if (map[j][i] == 0)
				{
					cout << '-';
				}
				else if (map[j][i] == -1)
				{
					cout << 'X';
				}

				else if (map[j][i] == -2)
				{
					cout << '.';
				}
					
				else
				{
					cout << map[j][i];
				}
			}
			//else
			//{
			//cout << ' ';   // Вкл, выкючить туман войны
			//} 
		}
		cout << endl;
	}
}

int shoot(int map[SZ][SZ], int x, int y, int ships[NUMSHIPS+1], int mask[SZ][SZ])
{
	int result = 0;

	if (map[x][y] >= 1)
	{
		ships[map[x][y]]--;

		if (ships[map[x][y]] <= 0)
		{
			result = 2;
			
		}
		else
		{
			result = 1;
			
		}

		map[x][y] = -1;

	}

	else
	{
		map[x][y] = -2;
	}
		
	mask[x][y] = 1;

	return result;

}

void setShipsPlayers(int map[SZ][SZ], int sizeShip, int shipsIdNew)
{
	int dir = 1;
	int ch;
	int x = 0;
	int y = 0;
	int mask[SZ][SZ];
	int numberOfShips = 1;
		
	while (numberOfShips < 2)
	{
		mapShow(map, mask, 0);;
		shipShow(x, y, dir, sizeShip);
		
		int temp_x = x;
		int temp_y = y;
		int temp_dir = dir;

		ch = _getch();
		switch (ch)
			{
			case 100: //d вправо
				x++;
				break;
			case 115: //s вниз
				y++;
				break;
			case 97: //a влево
				x--;
				break;
			case 119: //w вверх
				y--;
				break;
			case 114:
				dir = !dir; //r -  поворот
				break;
			case 13:
				dir = !dir; //ентер -  установка корабля
				if (setShip(map, x, y, dir, sizeShip))
				{
					x = 0, y = 0;
					dir = 1;
					/*sizeShip--;*/
					numberOfShips++;
				}
				break;
			}

		if (!shipInMap(x, y, dir, sizeShip))
		{
			x = temp_x;
			y = temp_y;
			dir = temp_dir;
			numberOfShips++;
		}

		system("cls");
		

	}
	
}

int main()

{
	setlocale(LC_CTYPE, "Russian");
	
	int paramOne = 0;
	int paramTwo = 0;

	int map1[SZ][SZ] = { 0 };
	int map2[SZ][SZ] = { 0 };

	int ships1[NUMSHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 }; // Жизни кораблей первого поля
	int ships2[NUMSHIPS + 1] = { 0, 4, 3, 3, 2, 2, 2, 1, 1, 1 }; // Жизни кораблей второго поля

	int mask1[SZ][SZ] = { 0 };
	int mask2[SZ][SZ] = { 0 };

		cout << "_____________________¶____________¶¶¶¶____________" << endl;
		cout << "__________________¶¶¶¶¶¶¶_________¶_______________" << endl;
		cout << "__________________¶__¶__¶_______¶¶¶¶¶_____________" << endl;
		cout << "____________¶_____¶__¶__¶_______¶_¶_¶_____________" << endl;
		cout << "____________¶¶___¶¶¶¶¶¶¶¶¶_____¶¶¶¶¶¶¶____________" << endl;
		cout << "____¶¶______¶¶¶__¶___¶___¶_____¶__¶__¶____________" << endl;
		cout << "____¶¶¶______¶___¶___¶____¶___¶___¶___¶___________" << endl;
		cout << "____¶¶¶¶__¶¶¶¶__¶___¶¶¶___¶__¶____¶____¶__________" << endl;
		cout << "____¶¶¶¶¶__¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________" << endl;
		cout << "_____¶__¶¶__¶¶¶______¶______¶_____¶____¶____¶¶_¶__" << endl;
		cout << "_____¶¶¶¶____¶_______¶______¶_____¶_____¶__¶¶¶¶___" << endl;
		cout << "___¶¶¶¶¶¶¶___¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__" << endl;
		cout << "___¶¶¶¶¶¶¶¶¶¶¶¶¶_____¶_________¶¶¶¶¶¶¶__¶¶¶__¶¶¶__" << endl;
		cout << "____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___¶¶¶__¶¶¶¶¶¶¶¶¶¶¶_________" << endl;
		cout << "____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___________" << endl;
		cout << "____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________" << endl;



	cout << "Добро пожаловать на морское поле битвы, моряк!" << endl;
	cout << "Введите - '1' если будете играть с компьютером, или '2' если будет играть компьютор против компьютера: " << endl;
	cin >> paramOne;
	cout << "Здравствуйте, введте '1' если хотите ввести корабли на поле игрока вручную, или '2' для автоматической расстановки: " << endl;
	cin >> paramTwo;

	if (paramOne == 1 && paramTwo == 1)
	{
		for (int i = 1; i <= NUMSHIPS; i++) // Ручная расстанова кораблей на поле игока
		{
			setShipsPlayers(map1, ships1[i], i);
		}
	
		for (int i = 1; i <= NUMSHIPS; i++) // Авоматическая расстановка кораблей на поле ИИ
		{
			setShipRandom(map2, ships2[i], i);
		}
	}
	
	else if (paramOne == 1 && paramTwo == 2)
	{
		for (int i = 1; i <= NUMSHIPS; i++)  // Автоматическая расстановка кораблей на поле игрока
		{
			setShipRandom(map1, ships1[i], i);
		}

		for (int i = 1; i <= NUMSHIPS; i++) // Авоматическая расстановка кораблей на поле ИИ
		{
			setShipRandom(map2, ships2[i], i);
		}

	}
	
	
				
	int x = 0, y = 0;
	
	bool turn = 1; //  Флаг выбора чей ход

	while (true) // Главный цикл игры
	{
		int resultShoot = 0;

		do 
		{
			mapShow(map1, mask1, 0);
			cout << endl;
			mapShow(map2, mask1, 1);
			
			if (turn == 1)
			{
				cout << endl;
				cout << "Введите коардинаты цела: " << endl;
				cin >> x;
				cin >> y;
				resultShoot = shoot(map2, x, y, ships2, mask2);
				cout << resultShoot;
			}
			else
			{
				cout << endl;
				cout << "Ход компьютера" << endl;
				Sleep(2000);
				x = rand() % SZ;
				y = rand() % SZ;
				resultShoot = shoot(map1, x, y, ships1, mask1);
				cout << resultShoot;
			}

			if (resultShoot == 1) cout << "Попал" << endl;
			else if (resultShoot == 2) cout << "Потоплен" << endl;
			else cout << "Промах" << endl;
			
			Sleep(2000);
			system("cls");

		} while (resultShoot != 0);
		
		turn = !turn;
	}
	
	_getch();
	system("cls");
	
	
}