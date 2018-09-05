#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
	int maze[25][25] = { 0, };
	int curr_x = 0;
	int curr_y = 0;
	int same_move = 1;
	int p_move = -1;
	int c_move = 0;
	char input = 0;
	srand((unsigned int)time(NULL));

	while (input != 'q'&&input != 'Q')
	{
		same_move = 1;
		curr_y = 0;
		curr_x = 0;
		for (int init_y = 0; init_y < 25; ++init_y)
		{
			for (int init_x = 0; init_x < 25; ++init_x)
			{
				maze[init_y][init_x] = 0;
			}
		}
		while (curr_x < 25 && curr_y < 25)
		{
			if (curr_x <= 18 /*&& curr_y < 18*/)
			{
				c_move = rand() % 2;
				switch (c_move)
				{
				case 0:
					if (same_move > 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else if (same_move <= 5 && p_move == c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						++same_move;
						break;
					}
					else if (same_move <= 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else
					{
						break;
					}
				case 1:
					if (curr_x != 24)
					{
						if (same_move > 5 && p_move != c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							same_move = 0;
							break;
						}
						else if (same_move <= 5 && p_move == c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							++same_move;
							break;
						}
						else if (same_move <= 5 && p_move != c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							same_move = 0;
							break;
						}
						else
						{
							break;
						}
					}

				}
			}
			else if (curr_x > 18 /*&& curr_y > 18*/)
			{
				c_move = rand() % 3;
				switch (c_move)
				{
				case 0:
					if (same_move > 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else if (same_move <= 5 && p_move == c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						++same_move;
						break;
					}
					else if (same_move <= 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						++curr_y;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else
					{
						break;
					}
				case 1:
					if (curr_x != 24)
					{
						if (same_move > 5 && p_move != c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							same_move = 0;
							break;
						}
						else if (same_move <= 5 && p_move == c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							++same_move;
							break;
						}
						else if (same_move <= 5 && p_move != c_move)
						{
							maze[curr_y][curr_x] = 1;
							++curr_x;
							p_move = c_move;
							same_move = 0;
							break;
						}
						else
						{
							break;
						}
					}
					
				case 2:
					if (same_move > 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						--curr_x;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else if (same_move <= 5 && p_move == c_move)
					{
						maze[curr_y][curr_x] = 1;
						--curr_x;
						p_move = c_move;
						++same_move;
						break;
					}
					else if (same_move <= 5 && p_move != c_move)
					{
						maze[curr_y][curr_x] = 1;
						--curr_x;
						p_move = c_move;
						same_move = 0;
						break;
					}
					else
					{
						break;
					}
				}
			}


		}

		for (int y = 0; y < 25; ++y)
		{
			for (int x = 0; x < 25; ++x)
			{
				if (maze[y][x] == 1)
				{
					printf("��");
				}
				else
				{
					printf("��");
				}
			}
			printf("\n");
		}
		printf("����Ϸ��� 'q'�� 'Q'�� ������ �ƹ� Ű�� �����ּ���. : ");
		scanf_s(" %c", &input);
		system("cls");


	}

}