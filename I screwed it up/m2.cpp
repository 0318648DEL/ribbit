#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct shape
{
	int left;
	int right;
	int up;
	int down;
	float length;
	float width;
	float middle_x;
	float middle_y;
};

int main()
{
	shape one = { 0, };
	shape two = { 0, };
	char input = 0;
	float c = 0;
	while (input != 'q'&&input != 'Q')
	{
		printf("충돌 체크 조합 : ");
		scanf_s(" %c", &input);
		if (input == '1')
		{
			while (true)
			{
				printf("첫번째 사각형의 좌표를 입력 : 좌, 하, 우, 상 순\n");
				scanf_s(" %d %d %d %d", &one.left, &one.down, &one.right, &one.up, 4, 4, 4, 4);
				printf("두번째 사각형의 좌표를 입력 : 좌, 하, 우, 상 순\n");
				scanf_s(" %d %d %d %d", &two.left, &two.down, &two.right, &two.up, 4, 4, 4, 4);
				if (one.right<one.left&&one.down>one.up)
				{
					printf("첫번째 값을 다시 입력해주세요!\n");
				}
				else if (two.right<two.left&&two.down>two.up)
				{
					printf("두번째 값을 다시 입력해주세요!\n");
				}
				else
				{
					break;
				}
			}
			while (true)
			{
				if ((one.left <= two.right) && (one.right >= two.left) && (one.down <= two.up) && (one.up >= two.down))
				{
					printf("사각형 충돌!\n");
					break;
				}
				printf("방향키를 입력해주세요. : ");
				scanf_s(" %c", &input);
				switch (input)
				{
				case 'w':
					one.up += 60;
					one.down += 60;
					/*one.length = one.right - one.left;
					one.width = one.up - one.down;*/
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 's':
					one.up -= 60;
					one.down -= 60;
					/*one.length = one.right - one.left;
					one.width = one.up - one.down;*/
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 'a':
					one.left -= 60;
					one.right -= 60;
					/*one.length = one.right - one.left;
					one.width = one.up - one.down;*/
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 'd':
					one.left += 60;
					one.right += 60;
					/*one.length = one.right - one.left;
					one.width = one.up - one.down;*/
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				default:
					printf("다시 입력해주세요!\n");
					break;
				}
			}

		}
		else if (input == '2')
		{
			while (true)
			{
				printf("첫번째 원의 좌표를 입력 : 좌, 하, 우, 상 순\n");
				scanf_s(" %d %d %d %d", &one.left, &one.down, &one.right, &one.up, 4, 4, 4, 4);
				printf("두번째 원의 좌표를 입력 : 좌, 하, 우, 상 순\n");
				scanf_s(" %d %d %d %d", &two.left, &two.down, &two.right, &two.up, 4, 4, 4, 4);
				if (one.right<one.left&&one.down>one.up)
				{
					printf("첫번째 값을 다시 입력해주세요!\n");
				}
				else if (two.right<two.left&&two.down>two.up)
				{
					printf("두번째 값을 다시 입력해주세요!\n");
				}
				else
				{
					break;
				}
			}
			one.length = fabs(one.right - one.left);
			one.width = fabs(one.up - one.down);
			two.length = fabs(two.right - two.left);
			two.width = fabs(two.up - two.down);
			one.middle_x = (one.length / 2) + one.left;
			one.middle_y = (one.width / 2) + one.down;
			two.middle_x = (two.length / 2) + two.left;
			two.middle_y = (two.width / 2) + two.down;
			
			while (true)
			{
				c = sqrtf(powf(one.middle_x - two.middle_x, 2) + powf(one.middle_y - two.middle_y, 2));
				if (c <= (one.width / 2) + (two.width / 2))
				{
					printf("원 충돌!\n");
					break;
				}
				printf("방향키를 입력해주세요. : ");
				scanf_s(" %c", &input);
				switch (input)
				{
				case 'w':
					one.up += 60;
					one.down += 60;
					one.middle_x = ((one.right - one.left) / 2) + one.left;
					one.middle_y = ((one.up - one.down) / 2) + one.down;
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 's':
					one.up -= 60;
					one.down -= 60;
					one.middle_x = ((one.right - one.left) / 2) + one.left;
					one.middle_y = ((one.up - one.down) / 2) + one.down;
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 'a':
					one.left -= 60;
					one.right -= 60;
					one.middle_x = ((one.right - one.left) / 2) + one.left;
					one.middle_y = ((one.up - one.down) / 2) + one.down;
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				case 'd':
					one.left += 60;
					one.right += 60;
					one.middle_x = ((one.right - one.left) / 2) + one.left;
					one.middle_y = ((one.up - one.down) / 2) + one.down;
					printf("첫 번째 도형 : (%d, %d), (%d, %d)\n", one.left, one.up, one.right, one.down);
					printf("두 번째 도형 : (%d, %d), (%d, %d)\n", two.left, two.up, two.right, two.down);
					break;
				default:
					printf("다시 입력해주세요!\n");
					break;
				}
			}

		}
	}

}