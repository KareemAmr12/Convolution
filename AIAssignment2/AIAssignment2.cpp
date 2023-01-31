#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> convolution(vector<vector<int>> filter, vector<vector<int>> window) //this function is completely generic, the input in main is user input.
{
	vector<vector<int>> feature;

	for (int i = 0; i < feature.size(); i++)
	{
		for (int j = 0; j < feature[i].size(); j++)
		{
			feature[i][j] = 0;
		}

	}
	int d = filter.size();
	int n = window.size();
	feature.resize(n - d + 1, vector<int>(n - d + 1));
	for (int Down = 0; Down < n-d+1; Down++) //for down
	{
		for (int Right = 0; Right < n-d+1; Right++) //for right movement
		{
			for (int i = 0; i < d; i++)
			{
				for (int j = 0; j < d; j++)
				{
					feature[Right][Down] = feature[Right][Down] + (filter[i][j] * window[i + Right][j + Down]);
				}
			}

		}
		
	}
	return feature;
	
}

int main()
{
	vector<vector<int>> filter
	{
		{2,0,-2},
		{1,0,-1},
		{-1,0,-2}
	};
	vector<vector<int>> feature;
	for (int i = 0; i < feature.size(); i++)
	{
		for (int j = 0; j < feature[i].size(); j++)
		{
			feature[i][j] = 0;
		}
		
	}
	vector<vector<int>> window
	{
	{ 3,4,0,2,5,7 },
	{ 1,4,3,5,6,0 },
	{ 6,8,2,0,4,3 },
	{ 5,2,3,4,1,7 },
	{ 2,8,4,3,5,4 },
	{ 0,6,4,2,5,1 }
	};
	
	feature = convolution(filter, window);

	for (int i = 0; i < feature.size(); i++)
	{
		for (int j = 0; j < feature[i].size(); j++)
		{
			cout << feature[i][j] << " ";
		}
		cout << endl;
	}
	system("PAUSE");
	return 0;
}




