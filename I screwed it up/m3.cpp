#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ROW 30
#define COL 30

int main()
{
	int x[2] = { 0, };
	int y[2] = { 0, };
	int shape = 0;
	char input = 0;
	printf("���� �Է����ּ��� : ");
	scanf_s(" %d %d %d %d %d", &shape, &x[0], &x[1], &y[0], &y[1],4,4,4,4,4);
	while (input != 'q'&&input != 'Q')
	{
		for (int b = 0; b < ROW; ++b)
		{
			for (int a = 0; a < COL; ++a)
			{
				if (a >= x[0] && a <= y[0]&&b>=x[1]&&b<=y[1])
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

		printf("��ɾ �Է��ϼ���. : ");
		scanf_s(" %c", &input);
		system("cls");
		switch (input)
		{
		case 'x':
			if (x[0] < COL&&y[0] < COL)
			{
				x[0] += 1;
				y[0] += 1;
			}
			break;
		case 'X':
			if (x[0] > 0&&y[0] > 0)
			{
				x[0] -= 1;
				y[0] -= 1;
			}
			break;
		case 'y':
			if (x[1] < ROW&&y[1] < ROW)
			{
				x[1] += 1;
				y[1] += 1;
			}
			break;
		case 'Y':
			if (x[1] > 0 && y[1] > 0)
			{
				x[1] -= 1;
				y[1] -= 1;
			}
			break;
		case 's':
			if (y[0]-x[0] > 0 && y[1]-x[1] > 0)
			{
				y[0] -= 1;
				y[1] -= 1;
			}
			break;
		case 'S':
			if (y[0] < COL&&y[1] < ROW)
			{
				y[0] += 1;
				y[1] += 1;
			}
			break;
		case 'i':
			if (y[0] - x[0] > 0)
			{
				y[0] -= 1;
			}
			break;
		case 'j':
			if (y[0] < COL)
			{
				y[0] += 1;
			}
			break;
		case 'k':
			if (y[1] - x[1] > 0)
			{
				y[1] -= 1;
			}
			break;
		case 'l':
			if (y[1] < ROW)
			{
				y[1] += 1;
			}
			break;
		case 'r':
			printf("���� �Է����ּ��� : ");
			scanf_s(" %d %d %d %d %d", &shape, &x[0], &x[1], &y[0], &y[1], 4, 4, 4, 4, 4);
			break;
		default:
			printf("�ٽ� �Է����ּ���!\n");
			break;
		}
	}
}