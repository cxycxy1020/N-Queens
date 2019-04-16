//���ǵݹ�͵ݹ�ı�������
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> solveNQueens(int n) {
	int check(vector<int> aa, int n);
	vector<vector<string>> resu;
	vector<int> tmp;

	//tmp��ʼ��
	for (int k = 0; k < n; ++k)
		tmp.push_back(-1);

	int i = 0;
	//Ϊʲô��i����-1,������һ�У�i=0���Ҳ������ʵ�λ�÷���Ҫ���ݣ�i--����˵�������ڰڷŷ���
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
				//�ʺ�������ܲ�ֻһ�ֽⷨ����ֹ֮ǰ�洢�������ⷨ�Ա��νⷨ����
				tmp[i] = -1;
			}
		}
		else
		{
			--i;
			//��ǰ���ݲ���Ҫ��tmp[i] = -1;����Ϊ��һ��һ���Ǵ�ǰһ�����ģ���ʱǰһ�е�ȡֵ���Ƕ�Ӧ���νⷨ��ȡֵ
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
	cout << "�����������ʱ��Ϊ��" << (float)(end_time - star_time)/1000 << "s." << endl;
	system("pause");
}


