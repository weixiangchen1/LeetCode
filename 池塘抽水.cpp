#include <stdio.h>
int m, n;
int count = 0;
char board[1050][1050];

int check(int x, int y)
{
	return (((x >= 1) && (x <= n)) && ((y >= 1) && (y <= m))) && board[x][y] == '@';
}

void dfs(int x, int y)
{
	if (!check(x, y))
	{
		return;
	}
	board[x][y] = '*';

	int x_add[8] = { -1,-1,-1,0,0,1,1,1 };
	int y_add[8] = { 0,-1,1,1,-1,0,-1,1 };

	for (int i = 0; i < 8; i++)
	{
		x = x + x_add[i];
		y = y + y_add[i];
		dfs(x, y);
		x = x - x_add[i];
		y = y - y_add[i];
	}
}

int main()
{

	while (~scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		count = 0;
		for (int i = 1; i <= n; i++)
		{
			getchar();
			for (int j = 1; j <= m; j++)
			{
				scanf("%c", &board[i][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (board[i][j] == '@')
				{
					count++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", count);

	}
	
	return 0;
}
