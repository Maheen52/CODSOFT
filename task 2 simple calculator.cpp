// task 2 simple calculator
#include<iostream>
using namespace std;

int main()
{
	double num1, num2;
	double result;
	cout << "Welcome to Maheen's Calculator!" << endl;
	cout << "Enter your first number: ";
	cin >> num1;
	cout << "Enter your second number: ";
	cin >> num2;
	cout << endl;
	
	int choice;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << endl;
	
	cout << "Please enter your choice of number from the above to perform the specified calculation: ";
	cin >> choice;
	cout << endl;
	
	switch(choice)
	{
		case 1:
			result = num1+num2;
			break;
		case 2:
			result = num1-num2;
			break;
		case 3:
			result = num1*num2;
			break;
		case 4:
			if(num2 != 0)
			{
				result = num1/num2;
			}
			else
			{
				cout << "Error! Division by zero." << endl;
				return 0;
			}
			break;
	}
	
	cout << "Result: " << result << endl;
	
	return 0;
}