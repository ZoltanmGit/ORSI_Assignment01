// ORSI_Assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <future>
#include <string>
#include <algorithm>


std::string Print(std::vector<std::vector<std::pair<int, int>>>& b, std::string X, int i, int j)
{
	std::string returnvalue = "";
	if (i == 0 || j == 0)
	{
		return "";
	}
	if (b[i][j].first == i - 1 && b[i][j].second == j - 1)
	{
		returnvalue = Print(b, X, i - 1, j - 1);
		if (X[i-1] != '\0')
		{
			//-1 to adjust
			returnvalue = returnvalue + X[i-1];
		}
	}
	else
	{
		if (b[i][j].first == i - 1 && b[i][j].second == j)
		{
			returnvalue = Print(b, X, i - 1, j);
		}
		else
		{
			returnvalue = Print(b, X, i, j-1);
		}
	}
	return returnvalue;
}
std::string longestCommonSubstring(std::string X, int n, std::string Y, int m)
{
	//Declare c n+1 and m+1 sized because of c[i,j] : 0 <= i <= n && 0 <= j <= m
	std::vector<std::vector<int>> c(n+1, std::vector<int>(m+1));
	for (int i = 0; i <= n; i++)
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
		for (int j = 1 ; j <= m; j++)
		{
			//-1 to check the first index
			if (X[i-1] == Y[j-1])
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
	return  Print(b, X, n, m);
}

int main()
{
	//Read inputs
	int linenumber;
	std::string pattern;
	std::ifstream iFile("input01.txt"); //CHANGE BACK
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
			oFile << threads[i].get();
			if (i != linenumber - 1)
			{
				oFile << std::endl;
			}
		}
		oFile.close();
	}
	// TEST01
	/*std::string X = "vWjxvfUBMmRDAVV";
	std::string Y = "dlKBILGZWJAqXzAGFRHZMitzLyOax";
	std::string Z = "tcZfEPRIETXGEtsHcKwZ";
	std::string O = "ZzUzRqpVkElpuPuaIsCFXGLeVDYWVOtKcmjRmpjuWUQre";
	std::string P = "GFRHZMitzLyOaxtcZfWhfQEaktRmE";
	std::cout << longestCommonSubstring(X, X.length(), Y, Y.length()) << std::endl;
	std::cout << longestCommonSubstring(X, X.length(), Z, Z.length()) << std::endl;
	std::cout << longestCommonSubstring(X, X.length(), O, O.length()) << std::endl;
	std::cout << longestCommonSubstring(X, X.length(), P, P.length()) << std::endl;*/
	// TEST02
	/*std::string X = "ClearlyEvolutionDoesNotDistributeitsGiftsEqually";
	std::string Y = "CheersLoveTheCavalrysHere";
	std::cout << longestCommonSubstring(X, X.length(), Y, Y.length());*/

	
}