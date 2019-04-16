#include <windows.h>
#include <iostream>
#include <math.h>  
using namespace std;

#define N 13 
//定义二维数组chessBoard用来存放棋盘信息，若放皇后则值为1，否则为0
int chessBoard[N][N] = { 0 };
//count用来统计方案个数
//int count = 0;
//函数声明
void print(int array[N][N]);
bool judge(int x, int y);
void NQueen(int x, int y);

int main()
{
	DWORD star_time = GetTickCount();
	NQueen(0, 0);
	//cout << "八皇后问题有" << count << "种方案" << endl;
	DWORD end_time = GetTickCount();
	cout << "这个程序运行时间为：" << (end_time - star_time) << "ms." << endl;
	system("pause");
	return 0;
}
//输出八皇后方案的摆放结果
void print(int array[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
//判断某位置能够放置皇后
bool judge(int x, int y)
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chessBoard[i][j] == 1)
			{
				//比较是否与先前皇后在同列、同一直线
				if ((y == j) || (x - i == abs(y - j)))
				{
					return false;
				}
			}
		}
	}
	return true;
}


//八皇后放置函数
void NQueen(int x, int y)
{
	//如果所在位置在列上越界，则直接结束
	if (y >= N)
		return;
	if (judge(x, y) == true)
	{
		chessBoard[x][y] = 1;
		//判断是否放置到最后一个函数
		if (x == N - 1)
		{
			//count++;
			print(chessBoard);
		}
		if (x < N - 1)
			NQueen(x + 1, 0);
	}
	/*不论judge是否为true，均需要执行这两句函数。
	当judge为true时，会一直递归调用完成一种方案。方案完成后，回到第x行，改变第x行选择的位置（将原来选中的位置清零，考虑右侧位置可行否），尝试其他方案
	当judge为false时，把当前位置值设为0，继续找这一行右侧有没有符合要求的位置*/
	chessBoard[x][y] = 0;
	NQueen(x, y + 1);
}
