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
	int last_num = 0;
	int begin_num = 0;
	char input = 0;
	int in_x, in_y, in_z;
	char empty[10] = { 0, };
	
	while (input != 'q'&&input != 'Q')
	{
		scanf_s(" %c", &input);
		switch (input)
		{
		case '+':
			scanf_s(" %d %d %d", &in_x, &in_y, &in_z,4,4,4);
			list[last_num].x = in_x;
			list[last_num].y = in_y;
			list[last_num].z = in_z;
			list[last_num].length = sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
			last_num += 1;
			break;
		case 'e':
			scanf_s(" %d %d %d", &in_x, &in_y, &in_z,4,4,4);
			for (int eyy = last_num; eyy >= 0; eyy--)
			{
				list[eyy + 1].x = list[eyy].x;
				list[eyy + 1].y = list[eyy].y;
				list[eyy + 1].z = list[eyy].z;
				list[eyy + 1].length = list[eyy].length;
			}
			list[begin_num].x = in_x;
			list[begin_num].y = in_y;
			list[begin_num].z = in_z;
			list[begin_num].length= sqrt(pow((double)in_x, 2) + pow((double)in_y, 2) + pow((double)in_z, 2));
			break;
		}
		for (int att = 9; att >= 0; --att)
		{
			printf("|%d|%d %d %d  l: %d|\n", att, list[att].x, list[att].y, list[att].z, list[att].length);
		}
	}
}