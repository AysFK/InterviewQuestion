/*#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

int bufA[15][3] = { 0 };
string bufB[15] = {};

void DataParse()
{
	FILE* fp;
	char ch;
	int i = 0, j = 0;
	fp = fopen("DataParse.txt", "r");
	rewind(fp);
	if (fp == 0) 
	{ 
		printf("Open file error"); 
		exit(1);
	}
	while ((ch = fgetc(fp)) != EOF)
	{
		while (ch != '\n' && ch != EOF)
		{
			for (j = 0; j < 3; j++)
			{
				while (ch != ' ')
				{
					bufA[i][j] = bufA[i][j] * 10 + (ch - '0');
					ch = fgetc(fp);
				}
				ch = fgetc(fp);
			}
			//fp--;
			//bufB[i] = fgets(fp);
			while (ch != '\n' && ch != EOF)
			{
				bufB[i] += ch;
				ch = fgetc(fp);
			}
			bufB[i] += '\0';
		}
		i++;
	}
	fclose(fp);
}*/

#include<stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string BufA[20][3] = {};
void DataParse()
{
	ifstream fin;
	fin.open(("data.txt"));
	string s;
	int j = 0;
	int x = 8;
	for (int i = 0; i < 2; i++)
	{
		while (fin >> s)
		{
			BufA[i][j] = s;
			cout << s << " ";
			if (j == 3)
			{
				cout << endl;
				break;
			}
		}
		j = 0;
	}
	fin.close();
}

int main()
{
	DataParse();
	return 0;
}