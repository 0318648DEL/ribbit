#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main()
{
	int vec_x[3] = { 0, };
	int vec_y[3] = { 0, };
	char input = 0;

	while (input != 'q'&&input != 'Q')
	{
		printf("input vector1: ");
		scanf_s("%d %d %d", &vec_x[0], &vec_x[1], &vec_x[2], 4, 4, 4);
		printf("input vector2: ");
		scanf_s("%d %d %d", &vec_y[0], &vec_y[1], &vec_y[2], 4, 4, 4);
		printf("명령어를 입력하세요. : ");
		scanf_s(" %c", &input);
		system("cls");
		switch (input)
		{
		case '+':
			printf("(%d, %d, %d) + (%d, %d, %d) = (%d, %d, %d)\n", vec_x[0], vec_x[1], vec_x[2], vec_y[0], vec_y[1], vec_y[2], vec_x[0] + vec_y[0], vec_x[1] + vec_y[1], vec_x[2] + vec_y[2]);
			break;
		case '-':
			printf("(%d, %d, %d) - (%d, %d, %d) = (%d, %d, %d)\n", vec_x[0], vec_x[1], vec_x[2], vec_y[0], vec_y[1], vec_y[2], vec_x[0] - vec_y[0], vec_x[1] - vec_y[1], vec_x[2] - vec_y[2]);
			break;
		case 'd':
			printf("(%d, %d, %d) • (%d, %d, %d) = %d\n", vec_x[0], vec_x[1], vec_x[2], vec_y[0], vec_y[1], vec_y[2], (vec_x[0] * vec_y[0]) + (vec_x[1] * vec_y[1]) + (vec_x[2] * vec_y[2]));
			break;
		case 'c':
			printf("(%d, %d, %d) x (%d, %d, %d) = (%d, %d, %d)\n", vec_x[0], vec_x[1], vec_x[2], vec_y[0], vec_y[1], vec_y[2], (vec_x[1] * vec_y[2]) - (vec_x[2] * vec_y[1]), (vec_x[2] * vec_y[0]) - (vec_x[0] * vec_y[2]), (vec_x[0] * vec_y[1]) - (vec_x[1] * vec_y[0]));
			break;
		case 'l':
			printf("root (%d, %d, %d) = root (%d)\n", vec_x[0], vec_x[1], vec_x[2], (int)(pow((double)vec_x[0], 2) + pow((double)vec_x[1], 2) + pow((double)vec_x[2], 2)));
			printf("root (%d, %d, %d) = root (%d)\n", vec_y[0], vec_y[1], vec_y[2], (int)(pow((double)vec_y[0], 2) + pow((double)vec_y[1], 2) + pow((double)vec_y[2], 2)));
			break;
		}
	}
}