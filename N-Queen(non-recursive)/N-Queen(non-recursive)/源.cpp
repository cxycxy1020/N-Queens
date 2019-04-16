//？非递归和递归的本质区别
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> solveNQueens(int n) {
	int check(vector<int> aa, int n);
	vector<vector<string>> resu;
	vector<int> tmp;

	//tmp初始化
	for (int k = 0; k < n; ++k)
		tmp.push_back(-1);

	int i = 0;
	//为什么是i大于-1,即当第一行（i=0）找不到合适的位置放需要回溯（i--），说明不存在摆放方案
	while (i > -1)
	{
		for (++tmp[i]; tmp[i] < n; ++tmp[i])
		{
			if (check(tmp, i))
				break;
		}
		if (tmp[i] < n)
		{
			if (i == n - 1)
			{
				vector<string> retm;
				for (int k = 0; k < n; ++k)
				{
					string ss = "";
					for (int l = 0; l < n; ++l)
						ss += '.';

					ss[tmp[k]] = 'Q';
					retm.push_back(ss);
				}
				resu.push_back(retm);
			}
			else
			{
				++i;
				//皇后问题可能不只一种解法，防止之前存储的其他解法对本次解法干扰
				tmp[i] = -1;
			}
		}
		else
		{
			--i;
			//向前回溯不需要加tmp[i] = -1;是因为后一行一定是从前一行来的，此时前一行的取值就是对应本次解法的取值
		}
			
	}
	return resu;
}

int check(vector<int> aa, int n)
{
	for (int i = 0; i < n; ++i)
		if (abs(aa[n] - aa[i]) == n - i || aa[n] == aa[i])
			return 0;
	return 1;
}

void reverse_with_iterator(vector<vector<string>> vec)
{
	if (vec.empty())
	{
		cout << "The vector is empty!" << endl;
		return;
	}

	vector<string>::iterator it;
	vector<vector<string>>::iterator iter;
	vector<string> vec_tmp;

	//cout << "Use iterator : " << endl;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		vec_tmp = *iter;
		for (it = vec_tmp.begin(); it != vec_tmp.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}

void main()
{
	DWORD star_time = GetTickCount();
	int n;
	cin >> n;
	vector<vector<string>> res = solveNQueens(n);
	reverse_with_iterator(res);
	DWORD end_time = GetTickCount();
	cout << "这个程序运行时间为：" << (float)(end_time - star_time)/1000 << "s." << endl;
	system("pause");
}


