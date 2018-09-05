#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct shape
{
	int left;
	int right;
	int up;
	int down;
	int length = right - left;
	int width = up - down;
	float middle_x = ((right - left) / 2) + left;
	float middle_y = ((up - down) / 2) + down;
};

int main()
{
	shape one = { 0, };
	shape two = { 0, };
	char input = 0;
	int c = 0;
	while (input != 'q'&&input != 'Q')
	{
		printf("�浹 üũ ���� : ");
		scanf_s(" %c", &input);
		if (input == '1')
		{
			printf("ù��° �簢���� ��ǥ�� �Է� : ");
			scanf_s(" %d %d %d %d", &one.left, &one.up, &one.right, &one.down, 4, 4, 4, 4);
			printf("�ι�° �簢���� ��ǥ�� �Է� : ");
			scanf_s(" %d %d %d %d", &two.left, &two.up, &two.right, &two.down, 4, 4, 4, 4);
			if ((one.left <= two.left + two.length) && (one.left + one.length >= two.left) && (one.up - one.width <= two.up) && (one.up >= two.up - two.width))
			{
				printf("�簢�� �浹!\n");
			}
		}
		else if (input == '2')
		{
			printf("ù��° ���� ��ǥ�� �Է� : ");
			scanf_s(" %d %d %d %d", &one.left, &one.up, &one.right, &one.down, 4, 4, 4, 4);
			printf("�ι�° ���� ��ǥ�� �Է� : ");
			scanf_s(" %d %d %d %d", &two.left, &two.up, &two.right, &two.down, 4, 4, 4, 4);
			c = sqrtf((one.middle_x - two.middle_x)*(one.middle_x - two.middle_x) + (one.middle_y - two.middle_y)*(one.middle_y - two.middle_y));
			if (c <= ((one.up - one.down) / 2) + ((two.up - two.down) / 2))
			{
				printf("�� �浹!\n");
			}
		}
	}

}