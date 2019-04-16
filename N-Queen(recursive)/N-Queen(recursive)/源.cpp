#include <windows.h>
#include <iostream>
#include <math.h>  
using namespace std;

#define N 13 
//�����ά����chessBoard�������������Ϣ�����Żʺ���ֵΪ1������Ϊ0
int chessBoard[N][N] = { 0 };
//count����ͳ�Ʒ�������
//int count = 0;
//��������
void print(int array[N][N]);
bool judge(int x, int y);
void NQueen(int x, int y);

int main()
{
	DWORD star_time = GetTickCount();
	NQueen(0, 0);
	//cout << "�˻ʺ�������" << count << "�ַ���" << endl;
	DWORD end_time = GetTickCount();
	cout << "�����������ʱ��Ϊ��" << (end_time - star_time) << "ms." << endl;
	system("pause");
	return 0;
}
//����˻ʺ󷽰��İڷŽ��
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
//�ж�ĳλ���ܹ����ûʺ�
bool judge(int x, int y)
{
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chessBoard[i][j] == 1)
			{
				//�Ƚ��Ƿ�����ǰ�ʺ���ͬ�С�ͬһֱ��
				if ((y == j) || (x - i == abs(y - j)))
				{
					return false;
				}
			}
		}
	}
	return true;
}


//�˻ʺ���ú���
void NQueen(int x, int y)
{
	//�������λ��������Խ�磬��ֱ�ӽ���
	if (y >= N)
		return;
	if (judge(x, y) == true)
	{
		chessBoard[x][y] = 1;
		//�ж��Ƿ���õ����һ������
		if (x == N - 1)
		{
			//count++;
			print(chessBoard);
		}
		if (x < N - 1)
			NQueen(x + 1, 0);
	}
	/*����judge�Ƿ�Ϊtrue������Ҫִ�������亯����
	��judgeΪtrueʱ����һֱ�ݹ�������һ�ַ�����������ɺ󣬻ص���x�У��ı��x��ѡ���λ�ã���ԭ��ѡ�е�λ�����㣬�����Ҳ�λ�ÿ��з񣩣�������������
	��judgeΪfalseʱ���ѵ�ǰλ��ֵ��Ϊ0����������һ���Ҳ���û�з���Ҫ���λ��*/
	chessBoard[x][y] = 0;
	NQueen(x, y + 1);
}
