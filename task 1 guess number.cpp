// task 1 number guessing game
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int guessnum, count = 0, randnum;
	
	srand(time(nullptr));
	randnum = rand() % 100 + 1;
	
	cout << "Welcome to Maheen's Guessing Trivia!" << endl;
	cout << "Guess the number and win! You have unlimited amount of tries." << endl;
		
	do
	{
		cout << "Enter the guess number: ";
	    cin >> guessnum;
	    cout << endl;
	    count++;
	    
		if(guessnum > randnum)
		{
			cout << "Your guessed number is too high! Try again." << endl;
		}
		else if(guessnum < randnum)
		{
			cout << "Your guess is too low! Try again." << endl;
		}
		else
		{
			cout << "YAY!! You guessed the number " << randnum << " in " << count << " tries." << endl;
		}
	}while(guessnum != randnum);
	
	return 0;
}