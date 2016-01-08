#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;

//function to do big mod
int mod(int base,int exponential,int modd)
{
	int ans = 1;
	int counter = 0;

	while(counter < exponential)
	{
		ans = (ans * base) % modd;
		counter++;
	}
	return ans;
}

//where all the magic happens
int main()
{
	//all my input variable
	string filename;
	int base;
	int exponent;
	int modd;

	//rest of the needed variables
	string line;

	//take in all my inputs
	cout << "Enter the file to decrypt:";
	cin >> filename;
	cout << "Enter the value of m:";
	cin >> modd;
	cout << "Enter the private key:";
	cin >> exponent;

	//ifstream.open() takes in char[] input,
	//following code converts string to char[]
	char nameArray[filename.size()];
	strcpy(nameArray, filename.c_str());

	//open our file
	ifstream myfile;
	myfile.open(nameArray);

	//creat a new .txt file
	ofstream newfile;
	newfile.open("decryptedfile.txt");

	//loop through each line of file
	while(getline(myfile,line))
	{
		//variables in the loop
		int length = line.size();
		int counter = 0;
		int tracker = 0;
		int i = 0;
		char ascii;
		bool yes = true;

		//loop through each line and encrypt
		while(counter < length)
		{
			if(line[counter] == ' ')
			{
				string myString = line.substr (tracker,i+2);
				int value = atoi(myString.c_str());
				value = mod(value,exponent,modd);
				ascii = static_cast<char>(value);
				newfile << ascii;
				tracker = counter;
				i = 0;
			}

			else if(line.find(" ",counter + 1) == -1)
			{
				string myString = line.substr (tracker);
				int value = atoi(myString.c_str());
				value = mod(value,exponent,modd);
				ascii = static_cast<char>(value);
				newfile << ascii;
				break;
			}
			i++;
			counter++;
		}
		yes = true;

		//for later - int array[length];
	}


}
