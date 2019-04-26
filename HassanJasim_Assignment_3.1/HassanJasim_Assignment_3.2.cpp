// HassanJasim_Assignment_3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct DNAnt
{
	int a, c, g, t;
	char strand[100];
};

void data2DNA (DNAnt*);
void countDNAnt(DNAnt*);
void DNAtoRNA(DNAnt*);

int _tmain(int argc, _TCHAR* argv[])
{
	DNAnt allDNA[80];

	data2DNA (allDNA);
	countDNAnt (allDNA);
	DNAtoRNA (allDNA);

	cin.ignore();
	cin.get();
	return 0;
}//============================================================================


void data2DNA (DNAnt allDNA[])
{
	ifstream InFile;
	InFile.open("Data.txt");
	ofstream OutFile;
	OutFile.open("DNA.txt");

	int currentValue = 0;

	for(int i = 0 ; i < 80 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++)
		{
			InFile>>currentValue;

			if(currentValue == 1)
			{
				allDNA[i].strand[j] = 'A';
				OutFile<<'A';
			}
			else if(currentValue == 2)
			{
				allDNA[i].strand[j] = 'C';
				OutFile<<'C';
			}
			else if(currentValue == 3)
			{
				allDNA[i].strand[j] = 'G';
				OutFile<<'G';
			}
			else if(currentValue == 4)
			{
				allDNA[i].strand[j] = 'T';
				OutFile<<'T';
			}
		}
		OutFile<<endl;
	}
	InFile.close();
	OutFile.close();
}//===================================================================================


void countDNAnt(DNAnt allDNA[])
{

	cout<<"Line\t A\t C\t G\t T"<<endl;
	for(int i = 0 ; i < 80 ; i++)
	{
		allDNA[i].a = 0;
		allDNA[i].c = 0;
		allDNA[i].g = 0;
		allDNA[i].t = 0;

		for(int j = 0 ; j < 100 ; j++)
		{

			if(allDNA[i].strand[j] == 'A')
			{
				allDNA[i].a++;
			}
			else if(allDNA[i].strand[j] == 'C')
			{
				allDNA[i].c++;
			}
			else if(allDNA[i].strand[j] == 'G')
			{
				allDNA[i].g++;
			}
			else if(allDNA[i].strand[j] == 'T')
			{
				allDNA[i].t++;
			}
		}
		cout<<i+1<<"\t"<<allDNA[i].a<<"\t"<<allDNA[i].c<<"\t"<<allDNA[i].g<<"\t"<<allDNA[i].t<<endl;
	}
}//==============================================================================================================================================


void DNAtoRNA(DNAnt allDNA[])
{
	ofstream Outfile;
	Outfile.open("RNA.txt");

	for(int i = 0 ; i < 80 ; i++)
	{
		if(allDNA[i].t > 25)
		{
			for(int j = 0 ; j < 100 ; j++)
			{
				if(allDNA[i].strand[j] == 'T')
				{
					allDNA[i].strand[j] = 'U';
				}
			}
		}
	}

	for(int i = 0 ; i < 80 ; i++)
	{
		for(int j = 0 ; j < 100 ; j++)
		{
			Outfile<<allDNA[i].strand[j];
		}
		Outfile<<endl;
	}
}
