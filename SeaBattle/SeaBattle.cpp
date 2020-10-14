#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <clocale>
using namespace std;

const int SIZE = 10;

void setShipRandom(int map[SIZE][SIZE], int sizeShip, int numShips)
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

		x = rand() % SIZE;
		y = rand() % SIZE;

		int temp_x = x;
		int temp_y = y;

		bool settinIsPossible = 1;

		dir = rand() % 4;

		for (int i = 0; i < sizeShip; i++)
		{
			if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
			{
				settinIsPossible = 0;
				break;
			}

			if (map[x][y] == 1 ||
				map[x][y + 1] == 1 ||
				map[x][y - 1] == 1 ||
				map[x + 1][y] == 1 ||
				map[x + 1][y + 1] == 1 ||
				map[x + 1][y - 1] == 1 ||
				map[x - 1][y] == 1 ||
				map[x - 1][y + 1] == 1 ||
				map[x - 1][y - 1] == 1)
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
		if (settinIsPossible)
		{
			x = temp_x;
			y = temp_y;

			for (int i = 0; i < sizeShip; i++)
			{
				map[x][y] = 1;
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
			countShip++;
		}
	}
}



int main() 
{

	setlocale(LC_CTYPE, "Russian");
	
	int map[SIZE][SIZE] = {0};

	setShipRandom(map, 4, 1);
	setShipRandom(map, 3, 2);
	setShipRandom(map, 2, 3);
	setShipRandom(map, 1, 4);

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (map[i][j] == 0)
			{
				cout << '-';
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}

	while (true)
	{
		int x, y;
		cout << endl;
		cout << "Введите коардинаты цела: " << endl;
		cin >> x;
		cin >> y;

		if (map[x][y] == 1)
		{
			cout << "Попал" << endl;
			map[x][y] = 3;

			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					cout << map[i][j];
				}
				cout << endl;
			}

			bool detectShip = false;

			for (int i = 0; i < SIZE; i++)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (map[i][j] == 1)
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
			cout << "Промах" << endl;
	}

	
}