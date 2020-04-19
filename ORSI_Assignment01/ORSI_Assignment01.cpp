// ORSI_Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <future>
#include <string>


std::string Print(std::vector<std::vector<std::pair<int, int>>>& b, std::string X, int i, int j)
{
	std::string returnvalue = "";
	if (i == 0 || j == 0)
	{
		return returnvalue;
	}
	if (b[i][j].first == i - 1 && b[i][j].second == j - 1)
	{
		returnvalue = returnvalue + Print(b, X, i - 1, j - 1);
		//X[i] a JÓ ÉRTÉK
		returnvalue = returnvalue + X[i];
		//print xi
	}
	else
	{
		if (b[i][j].first == i - 1 && b[i][j].second == j)
		{
			returnvalue = returnvalue + Print(b, X, i - 1, j);
		}
		else
		{
			returnvalue = returnvalue + Print(b, X, i, j-1);
		}
	}
	return returnvalue;
}
std::string longestCommonSubstring(std::string X, const int n, std::string Y, const int m)
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
	return Print(b, X, n, m);
}

int main()
{
	//Read inputs
	int linenumber;
	std::string pattern;
	std::ifstream iFile("input.txt");
	iFile >> linenumber >> pattern;
	//start threads
	std::vector<std::future<std::string>> threads(linenumber);
	std::string line;
	std::getline(iFile, line);
	for (int i = 0; i < linenumber; i++)
	{
		std::getline(iFile, line);
		threads[i] = std::async(std::launch::async, longestCommonSubstring, pattern, pattern.length(), line, line.length());
	}
	iFile.close();
	//Create output file and wait threads
	std::ofstream oFile("output.txt");
	if (linenumber == 0)
	{
		oFile.close();
	}
	else
	{
		for (int i = 0; i < linenumber; i++)
		{
			oFile << threads[i].get() << std::endl;
		}
		oFile.close();
	}
}