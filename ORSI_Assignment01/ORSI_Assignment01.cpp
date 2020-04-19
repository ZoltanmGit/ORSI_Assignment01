// ORSI_Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
//#include <thread>
//#include <future>
//Reads the input file(input.txt) and starts the threads
//Collects the results achieved by the started threads
//Writes the results in the output.txt-


int Print(std::vector<std::vector<std::pair<int, int>>>& b, std::string X, int i, int j)
{
	if (i == 0 || j == 0)
	{
		return 0;
	}
	if (b[i][j].first == i - 1 && b[i][j].second == j - 1)
	{
		Print(b, X, i - 1, j - 1);
		//print xi
		std::cout << X[i];
	}
	else
	{
		if (b[i][j].first == i - 1 && b[i][j].second == j)
		{
			Print(b, X, i - 1, j);
		}
		else
		{
			Print(b, X, i, j-1);
		}
	}
	return 0;
}
void longestCommonSubstring(std::string X, const int n, std::string Y, const int m)
{
	//Declare c n+1 and m+1 sized because of c[i,j] : 0 <= i <= n && 0 <= j <= m
	std::vector<std::vector<int>> c(n+1, std::vector<int>(m+1));
	for (int i = 1; i <= n; i++)
	{
		c[i][0] = 0;
	}
	for (int j = 0; j <= m ; j++)
	{
		c[0][j] = 0;
	}
	//Declare b in the same way
	std::vector<std::vector<std::pair<int,int>>> b(n+1, std::vector<std::pair<int,int>>(m+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (X[i] == Y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = std::make_pair(i-1,j-1);
			}
			else
			{
				if (c[i - 1][j] >= c[i][j-1])
				{
					c[i][j] = c[i - 1][j];
					b[i][j] = std::make_pair(i - 1, j);
				}
				else
				{
					c[i][j] = c[i][j - 1];
					b[i][j] = std::make_pair(i, j - 1);
				}
			}
		}
	}
	Print(b, X, n, m);
	std::cout << std::endl << "_____" << std::endl;
}

int main()
{
	std::string X = "vWjxvfUBMmRDAVV";
	std::string Y = "dlKBILGZWJAqXzAGFRHZMitzLyOax";
	std::string Z = "tcZfEPRIETXGEtsHcKwZ";
	std::string O = "ZzUzRqpVkElpuPuaIsCFXGLeVDYWVOtKcmjRmpjuWUQre";
	std::string P = "GFRHZMitzLyOaxtcZfWhfQEaktRmE";
	longestCommonSubstring(X, X.length(), Y, Y.length());
	longestCommonSubstring(X, X.length(), Z, Z.length());
	longestCommonSubstring(X, X.length(), O, O.length());
	longestCommonSubstring(X, X.length(), P, P.length());
}