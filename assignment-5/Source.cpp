#include <iostream>
using namespace std;

void BinaryToDecimal(int arr[50], double n2, long num2, int ChoiceConvert);
void DecimalToBinary(int arr2[50], long num3);
void OctalToDecimal(int arr3[50], double n3, long num4, int choice);
void DecimalToOctal(int arr4[50], long num5);

void main()
{
	long num = 0;
	double n = 0.0;
	int choice;
	int ChoiceConvert;
	int array[50]{};

	cout << "Please choose the type of number you will enter: " << endl
		<< "1- Binary numbers: " << endl << "2- Decimal numbers: " << endl << "3- Octal number: " << endl;
	cin >> choice;
	while (choice > 3 || choice < 1)
	{
		cout << "Please enter number between 1 and 4 only: " << endl;
		cin >> choice;
	}

	cout << "Please choose the type of number you want to convert to: " << endl
		<< "1- Binary numbers: " << endl << "2- Decimal numbers: " << endl << "3- Octal number: " << endl;
	cin >> ChoiceConvert;
	while (ChoiceConvert > 3 || ChoiceConvert < 1)
	{
		cout << "Please enter number between 1 and 4 only: " << endl;
		cin >> ChoiceConvert;
	}

	switch (choice)
	{
	case 1:
		cout << "Please enter the Binary number: " << endl;
		cin >> num;
		break;
	case 2:
		cout << "Please enter the Decimal number: " << endl;
		cin >> num;
		break;
	case 3:
		cout << "Please enter the Octal number: " << endl;
		cin >> num;
		break;
	case 4:
		cout << "Please enter the Hexadecimal number: " << endl;
		cin >> num;
		break;
	}

	switch (ChoiceConvert)
	{
	case 1:
		if (choice == 2)
		{
			DecimalToBinary(array, num);
		}
		if (choice == 3)
		{
			OctalToDecimal(array, n, num, choice);
		}
		break;
	case 2:
		if (choice == 1)
		{
			BinaryToDecimal(array, n, num, ChoiceConvert);
		}
		if (choice == 3)
		{
			OctalToDecimal(array, n, num, choice);
		}
		break;
	case 3:
		if (choice == 2)
		{
			DecimalToOctal(array, num);
		}
		if (choice == 1)
		{
			BinaryToDecimal(array, n, num, ChoiceConvert);
		}
		break;

	}
}


void BinaryToDecimal(int arr[50], double n2, long num2, int ChoiceConvert)
{
	int y = num2;
	if (y == 0)
	{
		n2 = 1;
	}
	while (y != 0)
	{
		y /= 10;
		n2++;
	}
	n2--;

	for (int j = n2; j >= 0; j--)
	{
		arr[j] = num2 % 10;
		num2 /= 10;
	}

	double decimal = 0.0;
	int x = n2;
	for (int i = 0; i <= x; i++)
		{
			decimal += (arr[i] * pow(2.0, n2));
			n2--;
		}
	int array2[50]{};
	if (ChoiceConvert == 3)
	{
		DecimalToOctal(array2, decimal);
	}
	else
	{
		cout << "the Decimal number is: " << decimal << endl;
	}
}

void DecimalToBinary(int arr2[50], long num3)
{
	int counter = 0;
	while (num3 != 0)
	{
		if ((num3 % 2) == 0)
		{
			arr2[counter] = 0;
			num3 /= 2;
		}
		else
		{
			arr2[counter] = 1;
			num3 /= 2;
		}
		counter++;
	}
	
	cout << "The Binary number is: ";
	for (int i = counter - 1; i >= 0; i--)
	{
		cout << arr2[i];
	}
	cout << endl;
}

void OctalToDecimal(int arr3[50],double n3, long num4, int choice)
{
	int y = num4;
	if (y == 0)
	{
		n3 = 1;
	}
	while (y != 0)
	{
		y /= 10;
		n3++;
	}
	n3--;

	for (int j = n3; j >= 0; j--)
	{
		arr3[j] = num4 % 10;
		num4 /= 10;
	}

	double decimal = 0.0;
	int x = n3;
	for (int i = 0; i <= x; i++)
	{
		decimal += (arr3[i] * pow(8.0, n3));
		n3--;
	}
	int array3[50]{};
	if (choice == 3)
	{
		DecimalToBinary(array3, decimal);
	}
	else
	{
		cout << "the Decimal number is: " << decimal << endl;
	}
}

void DecimalToOctal(int arr4[50], long num5)
{
	int remainder = 0;
	long octal = 0, z = 1;

	while (num5 != 0)
	{
		remainder = num5 % 8;
		num5 = num5 / 8;
		octal = octal + (remainder * z);
		z = z * 10;
	}
	cout << "The octal number is: " << octal << endl;
}