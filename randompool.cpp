#include<iostream>
#include<map>
#include<string>
using namespace std;

class Randompool
{

public:
	int size = 0;//哈希表长度
	int k = -1;//哈希值从1出发
	void insert(map<int, string>& m1, map<string, int>& m2, string cur)
	{
		if (m2.find(cur) == m2.end())
		{
			m2[cur] = ++k;
			m1[k] = cur;
			size++;
		}
	}
	void  delete_s(map<int, string>& m1, map<string, int>& m2, string cur)
	{
		//将待删除的字符与最后一个哈希值对应的字符互换
		if (m2.find(cur) != m2.end())
		{
			int idx = m2[cur];//待删除的字符对用的哈希值
			m1[idx] = m1[size - 1];//
			//m1[size - 1] = cur;
			m2[cur] = size;
			m2[m1[idx]] = idx;
			size--;
		}
	};
	string rand_num(map<int, string>& m1)
	{
		int idx = rand() % size;//[0,size-1]范围的随机数
		return m1[idx];
	}
};

int main()
{
	map<int, string> M1;
	map<string, int> M2;
	Randompool RP;
	RP.insert(M1,M2,"feng");
	RP.insert(M1,M2,"zhang");
	RP.insert(M1, M2, "su");
	RP.delete_s(M1, M2, "feng");
	cout << M2["su"] << endl;
	return 0;

}