#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<Windows.h>

int main()
{
	int arr1[3][3] = { 0, };
	int arr2[3][3] = { 0, };
	int arr3[3][3] = { 0, };
	int arr4[4][4] = { 0, };
	int result = 0;
	char input = 0;
	srand((unsigned int)time(NULL));
	while (input != 'q'&&input != 'Q')
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int x = 0; x < 3; ++x)
			{
				arr1[y][x] = rand() % 2;
				arr2[y][x] = rand() % 2;
			}
		}
		printf("명령어를 입력하세요. : ");
		scanf_s(" %c", &input);
		system("cls");
		switch (input)
		{
		case('M'):
		case('m'):
			arr3[0][0] = (arr1[0][0] * arr2[0][0]) + (arr1[0][1] * arr2[1][0]) + (arr1[0][2] * arr2[2][0]);
			arr3[0][1] = (arr1[0][0] * arr2[0][1]) + (arr1[0][1] * arr2[1][1]) + (arr1[0][2] * arr2[2][1]);
			arr3[0][2] = (arr1[0][0] * arr2[0][2]) + (arr1[0][1] * arr2[1][2]) + (arr1[0][2] * arr2[2][2]);
			arr3[1][0] = (arr1[1][0] * arr2[0][0]) + (arr1[1][1] * arr2[1][0]) + (arr1[1][2] * arr2[2][0]);
			arr3[1][1] = (arr1[1][0] * arr2[0][1]) + (arr1[1][1] * arr2[1][1]) + (arr1[1][2] * arr2[2][1]);
			arr3[1][2] = (arr1[1][0] * arr2[0][2]) + (arr1[1][1] * arr2[1][2]) + (arr1[1][2] * arr2[2][2]);
			arr3[2][0] = (arr1[2][0] * arr2[0][0]) + (arr1[2][1] * arr2[1][0]) + (arr1[2][2] * arr2[2][0]);
			arr3[2][1] = (arr1[2][0] * arr2[0][1]) + (arr1[2][1] * arr2[1][1]) + (arr1[2][2] * arr2[2][1]);
			arr3[2][2] = (arr1[2][0] * arr2[0][2]) + (arr1[2][1] * arr2[1][2]) + (arr1[2][2] * arr2[2][2]);
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[0][0], arr1[0][1], arr1[0][2], arr2[0][0], arr2[0][1], arr2[0][2], arr3[0][0], arr3[0][1], arr3[0][2]);
			printf("|%d %d %d|    *		|%d %d %d|	  =		|%d %d %d|\n", arr1[1][0], arr1[1][1], arr1[1][2], arr2[1][0], arr2[1][1], arr2[1][2], arr3[1][0], arr3[1][1], arr3[1][2]);
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[2][0], arr1[2][1], arr1[2][2], arr2[2][0], arr2[2][1], arr2[2][2], arr3[2][0], arr3[2][1], arr3[2][2]);
			break;
		case('A'):
		case('a'):
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[0][0], arr1[0][1], arr1[0][2], arr2[0][0], arr2[0][1], arr2[0][2], arr1[0][0] + arr2[0][0], arr1[0][1] + arr2[0][1], arr1[0][2] + arr2[0][2]);
			printf("|%d %d %d|	  +		|%d %d %d|	  =		|%d %d %d|\n", arr1[1][0], arr1[1][1], arr1[1][2], arr2[1][0], arr2[1][1], arr2[1][2], arr1[1][0] + arr2[1][0], arr1[1][1] + arr2[1][1], arr1[1][2] + arr2[1][2]);
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[2][0], arr1[2][1], arr1[2][2], arr2[2][0], arr2[2][1], arr2[2][2], arr1[2][0] + arr2[2][0], arr1[2][1] + arr2[2][1], arr1[2][2] + arr2[2][2]);
			break;

		case('D'):
		case('d'):
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[0][0], arr1[0][1], arr1[0][2], arr2[0][0], arr2[0][1], arr2[0][2], arr1[0][0] - arr2[0][0], arr1[0][1] - arr2[0][1], arr1[0][2] - arr2[0][2]);
			printf("|%d %d %d|	  -		|%d %d %d|	  =		|%d %d %d|\n", arr1[1][0], arr1[1][1], arr1[1][2], arr2[1][0], arr2[1][1], arr2[1][2], arr1[1][0] - arr2[1][0], arr1[1][1] - arr2[1][1], arr1[1][2] - arr2[1][2]);
			printf("|%d %d %d|			|%d %d %d|			|%d %d %d|\n", arr1[2][0], arr1[2][1], arr1[0][2], arr2[2][0], arr2[2][1], arr2[2][2], arr1[2][0] - arr2[2][0], arr1[2][1] - arr2[2][1], arr1[2][2] - arr2[2][2]);
			break;

		case('R'):
		case('r'):
			result = (arr1[0][0] * arr1[1][1] * arr1[2][2]) + (arr1[0][1] * arr1[1][2] * arr1[2][0]) + (arr1[0][2] * arr1[1][0] * arr1[2][1]) - (arr1[2][0] * arr1[1][1] * arr1[0][2]) - (arr1[2][1] * arr1[1][2] * arr1[0][0]) - (arr1[2][2] * arr1[1][0] * arr1[0][1]);
			printf("|%d %d %d|\n", arr1[0][0], arr1[0][1], arr1[0][2]);
			printf("|%d %d %d|		=		%d\n", arr1[1][0], arr1[1][1], arr1[1][2], result);
			printf("|%d %d %d|\n", arr1[2][0], arr1[2][1], arr1[2][2]);
			break;
		case('H'):
		case('h'):
			for (int y = 0; y < 4; ++y)
			{
				for (int x = 0; x < 4; ++x)
				{
					if (x > 2 && y < 3)
					{
						arr4[y][x] = 0;
					}
					else if (x < 3 && y>2)
					{
						arr4[y][x] = 0;
					}
					else if (x == 3 && y == 3)
					{
						arr4[y][x] = 1;
					}
					else
					{
						arr4[y][x] = arr1[y][x];
					}
				}
			}
			printf("|%d %d %d|			|%d %d %d %d|\n", arr1[0][0], arr1[0][1], arr1[0][2], arr4[0][0], arr4[0][1], arr4[0][2], arr4[0][3]);
			printf("|%d %d %d|			|%d %d %d %d|\n", arr1[1][0], arr1[1][1], arr1[1][2], arr4[1][0], arr4[1][1], arr4[1][2], arr4[1][3]);
			printf("|%d %d %d|	  =		|%d %d %d %d|\n", arr1[2][0], arr1[2][1], arr1[2][2], arr4[2][0], arr4[2][1], arr4[2][2], arr4[2][3]);
			printf("			|%d %d %d %d|\n", arr4[3][0], arr4[3][1], arr4[3][2], arr4[3][3]);
			break;
		default:
			printf("다시 입력해주세요!\n");
		}
	}


}