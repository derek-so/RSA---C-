#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
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

	//take in all my inputs first
	cout << "What file are we trying to encrypt?" << endl;
	cin >> filename;
	cout << "Please enter the public key m" << endl;
	cin >> modd;
	cout << "Please enter the public key k" << endl;
	cin >> exponent;

	//ifstream.open() takes in char[] input,
	//following code converts string to char[]
	char nameArray[filename.size()];
	strcpy(nameArray, filename.c_str());

	//open our file
	ifstream myfile;
	myfile.open(nameArray);

	//create a new .txt file
	ofstream newfile;
	newfile.open("encryptedfile.txt");

	//loop through each line of file
	while(getline(myfile,line))
	{	
		//variables in the loop
		int length = line.size();
		char array[length];
		strcpy(array,line.c_str());
		int encryptArray[length];
		int counter = 0;
		char ascii;
		int numeric;

		//loop through each line which are now char[]s
		//turn each char to ascii and encrypt with key
		while(counter < length)
		{	
			ascii = (int) array[counter];
			encryptArray[counter] = mod(ascii,exponent,modd);
			newfile << encryptArray[counter];
			counter++;
			if(counter <= length)
			{
				newfile << " ";
			}
			
		}
		newfile << mod(10,exponent,modd) << "\n";
	}
}
