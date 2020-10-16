#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <clocale>
#include <windows.h>
#include <math.h>

using namespace std;

const int SZ = 10;

int shipsId = 1;

int ships[10] = {0};

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

void setShipRandom(int map[SZ][SZ], int sizeShip, int numShips)
{
	int x, y;
	int dir = 0;
	int countShip = 0;
	int countTact = 0;

	while (countShip < numShips)
	{
		countTact++;
		if (countTact > 1000)
			break;

		x = rand() % SZ;
		y = rand() % SZ;

		int temp_x = x;
		int temp_y = y;

		bool settinIsPossible = 1;

		//dir = rand() % 4;

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
			countShip++;
		}
	}
}

void mapShow(int map[SZ][SZ], int mask[SZ][SZ])
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
			// if (mask[j][i] == 1) // Вкл, выкючить туман войны
			{
				if (map[j][i] == 0)
				{
					cout << '-';
				}
				else if (map[j][i] == -1)
				{
					cout << 'X';
				}
					
				else
				{
					cout << map[j][i];
				}
			}
			//else
			//{
			//	cout << ' ';   // Вкл, выкючить туман войны
			//} 
		}
		cout << endl;
	}
}

int main()

{

	setlocale(LC_CTYPE, "Russian");
	
	int map[SZ][SZ] = {0};
	int mask[SZ][SZ] = {0};

	/*setShipRandom(map, 4, 1);
	setShipRandom(map, 3, 2);
	setShipRandom(map, 2, 3);
	setShipRandom(map, 1, 4);*/


	
	int x = 0, y = 0;
	int dir = 1;
	int sizeShip = 4;
	int ch;

	while (true)
	{
		mapShow(map, mask);
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
					sizeShip--;
				}
				break;
			}

		if (!shipInMap(x, y, dir, sizeShip))
		{
			x = temp_x;
			y = temp_y;
			dir = temp_dir;
		}

		system("cls");
		
	}


	while (true)
	{

		mapShow(map, mask);
		
		cout << "Введите коардинаты цела: " << endl;
		cin >> x;
		cin >> y;

		if (map[x][y] >= 1)
		{
			ships[map[x][y]]--;
			
			if (ships[map[x][y]] <= 0)
			{
				cout << "Потоплен" << endl;
			}
			else
			{
				cout << "Поврежден" << endl;
			}
				
			map[x][y] = -1;

			bool detectShip = false;

			for (int i = 0; i < SZ; i++)
			{
				for (int j = 0; j < SZ; j++)
				{
					if (map[i][j] >= 1)
					{
						detectShip = true;
					}
				}
			}

			if (detectShip == false) 
			{
				cout << "Вы победили!" << endl;
				break;
			}
		}

		else 
		{
			cout << "Промах" << endl;
		}
			
		
		mask[x][y] = 1;
		
		Sleep(1000);
		system("cls");
		_getch();
		
	}
	system("pause");
	return 0;
	
}