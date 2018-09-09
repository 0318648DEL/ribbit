#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <ctime>

#define WIDTH 25
#define HEIGHT 25

using namespace std;

int maze[WIDTH][HEIGHT];
void init_maze();
void print_maze();
void make_maze(int x, int y);

int main()
{
	char input = 0;
	while (true)
	{
		init_maze();
		maze[0][0] = 1;
		make_maze(0, 0);
		print_maze();
		cout << "계속 진행하시려면 'q'와 'Q'를 제외한 키를 입력해주세요. : ";
		cin >> input;
		if (input == 'q' || input == 'Q')
		{
			break;
		}
	}
	
}

void init_maze()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < HEIGHT; ++x)
		{
			maze[y][x] = 0;
		}
	}
}

void print_maze()
{
	system("cls");
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			switch (maze[y][x])
			{
			case 1:
				cout << "□";
				break;
			default:
				cout << "■";
				break;
			}
		}
		cout << endl;
	}
}

void make_maze(int x, int y)
{
	vector<int> move{ 0,1,2,3 };

	shuffle(move.begin(), move.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

	for (int att = 0; att < 4; ++att)
	{
		int move_y = 0;
		int move_x = 0;

		switch (move[att])
		{
		case 0:
			move_y = -1;
			break;
		case 1:
			move_y = 1;
			break;
		case 2:
			move_x = -1;
			break;
		case 3:
			move_x = 1;
			break;
		default:
			break;
		}

		int xposTest = x + move_x * 2;
		int yposTest = y + move_y * 2;

		if ((xposTest >= 0 && xposTest < WIDTH) && (yposTest >= 0 && yposTest < HEIGHT))
		{
			if (maze[yposTest][xposTest] == 0)
			{
				maze[yposTest][xposTest] = 1;
				maze[yposTest - move_y][xposTest - move_x] = 1;

				//system("cls");
				//print_maze();
				make_maze(xposTest, yposTest);
			}
			else
			{
				if (maze[yposTest - move_y][xposTest - move_x] == 0)
				{
					maze[yposTest - move_y][xposTest - move_x] = 2;
				}
			}
		}
	}

}