#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>

struct LIST
{
	int x, y, z;
	int length;
};

void func_func(LIST list[10]);

int main()
{
	LIST saved[10] = { 0, };
	func_func(saved);
}

void func_func(LIST list[10])
{
	int begin_num = 0;
	int last_num = begin_num + 1;
	char input = 0;
	int in_x, in_y, in_z;
	LIST temp = { 0, };
	char empty[10] = { 0, };

	while (input != 'q'&&input != 'Q')
	{
		for (int att = 9; att >= 0; --att)
		{
			printf("|%d|%d %d %d  l: %d|\n", att, list[att].x, list[att].y, list[att].z, list[att].length);
		}
		scanf_s(" %c", &input);
		switch (input)
		{
		case '+':
			scanf_s(" %d %d %d", &in_x, &in_y, &in_z, 4, 4, 4);
			system("cls");
			list[last_num-1].x = in_x;
			list[last_num-1].y = in_y;
			list[last_num-1].z = in_z;
			list[last_num-1].length = sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
			empty[last_num-1] = 1;
			last_num += 1;
			break;
		case 'e':
			scanf_s(" %d %d %d", &in_x, &in_y, &in_z, 4, 4, 4);
			system("cls");
			if (begin_num == 0 && empty[begin_num] == 1)
			{
				for (int eyy = last_num; eyy > begin_num; --eyy)
				{

					list[eyy].x = list[eyy-1].x;
					list[eyy].y = list[eyy-1].y;
					list[eyy].z = list[eyy-1].z;
					list[eyy].length = list[eyy-1].length;
					empty[eyy] = 1;


				}
				list[begin_num].x = in_x;
				list[begin_num].y = in_y;
				list[begin_num].z = in_z;
				list[begin_num].length = sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
				empty[begin_num] = 1;
				last_num += 1;
			}
			else if (begin_num == 0 && empty[begin_num] == 0)
			{
				list[begin_num].x = in_x;
				list[begin_num].y = in_y;
				list[begin_num].z = in_z;
				list[begin_num].length = sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
				empty[begin_num] = 1;
			}
			else
			{
				list[begin_num].x = in_x;
				list[begin_num].y = in_y;
				list[begin_num].z = in_z;
				list[begin_num].length = sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
				empty[begin_num] = 1;
				begin_num -= 1;
			}
			break;
		case '-':
			list[last_num - 1].x = 0;
			list[last_num - 1].y = 0;
			list[last_num - 1].z = 0;
			list[last_num - 1].length = 0;
			//empty[last_num] = 0;
			empty[last_num - 1] = 0;
			last_num -= 1;
			break;
		case 'd':
			list[begin_num].x = 0;
			list[begin_num].y = 0;
			list[begin_num].z = 0;
			list[begin_num].length = 0;
			empty[begin_num] = 0;
			begin_num += 1;
			break;
		case 'l':
			printf("length of the list : %d\n", last_num - begin_num);
			break;
		case 'c':
			for (int clean = 0; clean < 10; ++clean)
			{
				list[clean].x = 0;
				list[clean].y = 0;
				list[clean].z = 0;
				list[clean].length = 0;
				empty[clean] = 0;
			}
			last_num = 0;
			begin_num = 0;
			break;
		case 'm':
			for (int x = 0; x < 10; ++x)
			{
				if (list[x].length > temp.length)
				{
					temp.length = list[x].length;
					temp.x = list[x].x;
					temp.y = list[x].y;
					temp.z = list[x].z;
				}
			}
			printf("가장 먼 거리에 있는 점의 좌표값 : |%d %d %d|\n", temp.x, temp.y, temp.z);
			break;
		case 'n':
			for (int x = 0; x < 10; ++x)
			{
				if (x == 0 && empty[x] == 1)
				{
					temp.length = list[x].length;
					temp.x = list[x].x;
					temp.y = list[x].y;
					temp.z = list[x].z;
				}
				else if ((list[x].length < temp.length) && empty[x] == 1)
				{
					temp.length = list[x].length;
					temp.x = list[x].x;
					temp.y = list[x].y;
					temp.z = list[x].z;
				}
			}
			printf("가장 가까운 거리에 있는 점의 좌표값 : |%d %d %d|\n", temp.x, temp.y, temp.z);
			break;
		}
	}
}