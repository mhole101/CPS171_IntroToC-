//*******************************************************************************************************************//
//*******************************************************************************************************************//
//                                                                                                                   //
//                                                                                                                   //
//                                                 MP4 - Functions                                                   //
//                                                                                                                   //
//                                                  By: Matt Hole                                                    //
//                                                                                                                   //
//                                           Created:   March 13th, 2020                                             //
//                                                                                                                   //                                          
//         This program was created to make a roman numeral calculator.  In this program roman numerals are          //
//         converted into integers and then integer operations are made to get the answer in integer form.           //
//         The final answer in integer form is then converted back into roman numeral form.  This program            //
//         is to use functions to perform its tasks and these functions will be called in the main function.         //
//                                                                                                                   //
//                                                                                                                   //
//                                                                                                                   //
//*******************************************************************************************************************//
//*******************************************************************************************************************//

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

// Function prototypes

int convert_from_Roman_to_Decimal(char);
char get_Oper(ifstream&);
void get_Data(ifstream&, int&, int&);
void calc_Romans(int, int, char, int&);
string convert_from_Decimal_to_Roman(int);
void print_Results(ofstream&, string&, string&, int&, int&, int&, char&);



int main()
{
	ifstream inData("mp4romanletrdata.txt");
	ofstream outData("mp4Output.txt");

	int romanNumeralValue1 = 0;
	int romanNumeralValue2 = 0;
	int romanNumeralSolution = 0;
	char operatorSign = ' ';
	char romanNumeralChar = ' ';
	char endWhileLoop = ' ';
	string romanNumeralString1 = "";
	string romanNumeralString2 = "";
	string romanNumeralSolutionString = "";

	// This output stream is used to print the title of the program and the author before
	// reading, manipulating, and outputting data.

	outData << "MP4 - Functions" << endl
		<< "Roman Numeral Calculator" << endl
		<< "Written by: Matt Hole" << endl << endl << endl;
	

	while (!inData.eof())
	{
		// get_Data call recieves input file (mp4romanletrdata.txt), recieves both roman numeral values,  
		// converts roman numerals to integer values and passes integer values back 
		// to romanNumeralValue1 and romanNumeralValue2

		get_Data(inData, romanNumeralValue1, romanNumeralValue2); 

		// get_Oper(inData) recieves the input file and uses it to extract the operator
		// sign.  This functions passes back a char and sets it to operatorSign to be
		// used later in the program to do the calculations.

		operatorSign = get_Oper(inData);

		// convert_from_Decimal_to_Roman recieves the romanNumeralValue (integer)
		// it then convert the integer back into a roman numeral in a string format
		// and returns the string to be sent to the print_Results function and 
		// printed in the output file later.

		romanNumeralString1 = convert_from_Decimal_to_Roman(romanNumeralValue1);
		romanNumeralString2 = convert_from_Decimal_to_Roman(romanNumeralValue2);

		// calc_Romans is passed the two roman numeral values, and operator sign.  
		// it then calculates the solution,  and passes the solution back by reference
		// using the romanNumeralSolution variable.

        calc_Romans(romanNumeralValue1, romanNumeralValue2, operatorSign, romanNumeralSolution);

		// print_Results recieves the output file (mp4Output.txt), both roman numeral strings, 
		//both roman numeral values (integer), romanNumeralSolution (integer), and operatorSign(char).
		//
		print_Results(outData, romanNumeralString1, romanNumeralString2, romanNumeralValue1, romanNumeralValue2, romanNumeralSolution, operatorSign);
		
		// This is used to peek at the input file for the EOF to properly end the while loop.
		endWhileLoop = inData.peek();
						
	}

	// Closes file streams
	inData.close();
	outData.close();

	

	return 0;
}


// convert_from_Roman_to_Decimal function definition
//  
// This integer type funtion is used to convert char 
// data of the roman numeral to integer data and return
// the data to be used in calulations.
//
// Parameters:
//
// char romanNumeralChar       receives roman numeral to be converted; is passed by value.

int convert_from_Roman_to_Decimal(char romanNumeralChar)
{
	int romanNumeralValue = 0;
	
	switch (romanNumeralChar)
	{
	case 'I':
		romanNumeralValue = 1;
		break;
	case 'V':
		romanNumeralValue = 5;
		break;
	case 'X':
		romanNumeralValue = 10;
		break;
	case 'L':
		romanNumeralValue = 50;
		break;
	case 'C':
		romanNumeralValue = 100;
		break;
	case 'D':
		romanNumeralValue = 500;
		break;
	case 'M':
		romanNumeralValue = 1000;
		break;
	default:
		romanNumeralValue = 0;
		cout << "Not a roman numeral" << endl;
		
	}

	return romanNumeralValue;
	
}

// get_Oper function definition
//
// This char type function recieves is passed the input stream,
// and retrieves the operator sign which is then returned by the funtion.
//
// Parameters:
//
// ifstream& inData            receives the input file to be read; is passed by reference.

char get_Oper(ifstream& inData)
{
	char operatorSign = ' ';
	
	// checks if input file is open

	if (!inData.is_open())
	{
		cout << "get_Oper function did not open file" << endl;
		return operatorSign;
	}
	
	inData >> operatorSign;
	
	return operatorSign;
}

// get_Data function definition
//
// This void function receives the input file, reads the roman numerals,
// calls the convert_from_Roman_to_Decimal fucntion which converts them to integer format. 
// The values are passed back to the main program through reference parameters.
//
// Parameters:
//
// ifstream& inData            receives input file to be read; is passed by reference.
// int& romanNumeral1          passes back the first roman numeral value as an integer; passed by reference.
// int& romanNumeral2          passes back the second roman numeral value as an integer; passed by reference.


void get_Data(ifstream& inData, int& romanNumeral1, int& romanNumeral2)
{
	char characterTemp = ' ';
	int whiteSpaceCounter = 0;
	int romanNumeralIntegerValueTemp = 0;
	
	// checks if inData is open

	if (!inData.is_open())
	{
		cout << "get_data Function did not open file" << endl;
		return;

	}
		
	inData >> characterTemp;
		

		if (characterTemp != ' ')
		{
			
			if (whiteSpaceCounter == 0)
			{
				while (characterTemp != ' ')
				{
					romanNumeralIntegerValueTemp = convert_from_Roman_to_Decimal(characterTemp);
					romanNumeral1 = romanNumeral1 + romanNumeralIntegerValueTemp;
					inData.get(characterTemp);
				}

				whiteSpaceCounter = whiteSpaceCounter++;
			
			}
			if (whiteSpaceCounter == 1)
			{
				inData >> characterTemp;
				while (characterTemp != ' ')
				{
					romanNumeralIntegerValueTemp = convert_from_Roman_to_Decimal(characterTemp);
					romanNumeral2 = romanNumeral2 + romanNumeralIntegerValueTemp;
					inData.get(characterTemp);		     			    
				}
				
				whiteSpaceCounter = whiteSpaceCounter++;
								
			} 
									
		}

	return;
}

// convert_from_Decimal_to_Roman funtion definition
//
// This string type funtion receives a roman numeral value in integer format,  converts it into
// a roman numeral string.  
//
// Parameters:
//
//int romanNumeralValue        inputs roman numeral value to be converted to roman numeral string; passed by value.

string convert_from_Decimal_to_Roman(int romanNumeralValue)
{
	string romanNumeralString = "";
	int numberOfM = 0;
	int numberOfD = 0;
	int numberOfC = 0;
	int numberOfL = 0;
	int numberOfX = 0;
	int numberOfV = 0;
	int numberOfI = 0;
		
	if (romanNumeralValue >= 1000)
	{
		numberOfM = romanNumeralValue / 1000;
		romanNumeralValue = romanNumeralValue % 1000;
		while (numberOfM > 0)
		{
			romanNumeralString = romanNumeralString + "M";
			numberOfM = numberOfM--;
		}

	}
	
	if (romanNumeralValue >= 500)
	{
		numberOfD = romanNumeralValue / 500;
		romanNumeralValue = romanNumeralValue % 500;
		while (numberOfD > 0)
		{
			romanNumeralString = romanNumeralString + "D";
			numberOfM = numberOfD--;
		}

	}

	if (romanNumeralValue >= 100)
	{
		numberOfC = romanNumeralValue / 100;
		romanNumeralValue = romanNumeralValue % 100;
		while (numberOfC > 0)
		{
			romanNumeralString = romanNumeralString + "C";
			numberOfM = numberOfC--;
		}

	}

	if (romanNumeralValue >= 50)
	{
		numberOfL = romanNumeralValue / 50;
		romanNumeralValue = romanNumeralValue % 50;
		while (numberOfL > 0)
		{
			romanNumeralString = romanNumeralString + "L";
			numberOfL = numberOfL--;
		}

	}

	if (romanNumeralValue >= 10)
	{
		numberOfX = romanNumeralValue / 10;
		romanNumeralValue = romanNumeralValue % 10;
		while (numberOfX > 0)
		{
			romanNumeralString = romanNumeralString + "X";
			numberOfX = numberOfX--;
		}

	}

	if (romanNumeralValue >= 5)
	{
		numberOfV = romanNumeralValue / 5;
		romanNumeralValue = romanNumeralValue % 5;
		while (numberOfV > 0)
		{
			romanNumeralString = romanNumeralString + "V";
			numberOfV = numberOfV--;
		}

	}

	if (romanNumeralValue >= 1)
	{
		numberOfI = romanNumeralValue / 1;
		romanNumeralValue = romanNumeralValue % 1;
		while (numberOfI > 0)
		{
			romanNumeralString = romanNumeralString + "I";
			numberOfI = numberOfI--;
		}
			   
	}

	if (romanNumeralValue != 0)
	{
		cout << "convert_from_Decimal_to_Roman Function did not execute properly \n"
			<< "romanNumeralValue = " << romanNumeralValue << endl
			<< "romanNumeralString = " << romanNumeralString;

		romanNumeralString = "";

	}
	
	return romanNumeralString;
}

// calc_Romans function definition
//
// This void type function receives two roman numeral values(in integer format), and an operator sign.
// Then uses this data to perform a calculation, and uses a parameter to return the solution(integer).
//
// Parameters:
//
// int romanNumeralValue1      inputs first roman numeral value to be used for calculation; passed by value.
// int romanNumeralValue2      inputs second roman numeral value to be used for calculation; passed by value.
// char operatorSign           inputs operator sign to determine which operation to be used for calculation; passed by value.
// int& romanNumeralSolution   passes back the solution in integer format; passed by reference. 

void calc_Romans(int romanNumeralValue1, int romanNumeralValue2, char operatorSign, int& romanNumeralSolution)
{
	if (operatorSign == '/')
	{
		romanNumeralSolution = romanNumeralValue1 / romanNumeralValue2;
		return;
	}
	
	if (operatorSign == '*')
	{
		romanNumeralSolution = romanNumeralValue1 * romanNumeralValue2;
		return;
	}

	if (operatorSign == '-')
	{
		romanNumeralSolution = romanNumeralValue1 - romanNumeralValue2;
		return;
	}

	if (operatorSign == '+')
	{
		romanNumeralSolution = romanNumeralValue1 + romanNumeralValue2;
		return;
	}
}

// print_Results function definition
//
// This void type function receives the output file, two roman numeral strings, three roman numeral values, 
// and an operator sign.  Then sends this data to the output file.
//
// Parameters:
//
// ofstream& outData             recieves output file that the data is placed in; passed by reference.
// string& romanNumeralString1   receives the first roman numeral(string format) and is sent to output file; passed by reference.
// string& romanNumeralString2   receives the second roman numeral(string format) and is sent to output file; passed by reference.
// int& romanNumeralValue1       receives the first roman numeral(integer format) and is sent to output file; passed by reference.
// int& romanNumeralValue2       receives the second roman numeral(integer format) and is sent to output file; passed by reference.
// int& romanNumeralSolution     receives the roman numeral solution(integer format) and is sent to output file; passed by reference.
// char& operatorSign            receives the operator sign(character format) and is sent to output file; passed by reference.

void print_Results(ofstream& outData, string& romanNumeralString1, string& romanNumeralString2, int& romanNumeralValue1,  int& romanNumeralValue2, int& romanNumeralSolution, char& operatorSign)
{
	// variables and declarations
	
	string firstNumberOutString = "The first number is ";
	string secondNumberOutString = "The second number is ";
	string operatorOutString = "The operator is ";
	string resultOutString = "The result is ";
	string romanNumeralSolutionString = "";
	int romanNumeral1 = 0;
	int romanNumeral2 = 0;
    
	// romanNumeralSolution(integer) is converted to a string, and placed into
	// romanNumeralSolutionString which is used later to print out solution in
	// roman numeral format. 

	romanNumeralSolutionString = convert_from_Decimal_to_Roman(romanNumeralSolution);

	// outData instructions prints out the results into mp4Output.txt
	
	outData << firstNumberOutString << romanNumeralString1 << " (" << romanNumeralValue1 << ")." << endl 
		 << secondNumberOutString << romanNumeralString2 << " (" << romanNumeralValue2 << ")." << endl 
		 << operatorOutString << operatorSign << endl 
		 << resultOutString << romanNumeralSolution << " (" << romanNumeralSolutionString << ")." << endl
	     << "************************************************" << endl << endl;

	// Initilize variables after data manipulation.

	romanNumeralValue1 = 0;
	romanNumeralValue2 = 0;
	romanNumeralSolution = 0;
	operatorSign = ' ';
	romanNumeralString1 = "";
	romanNumeralString2 = "";
	romanNumeralSolutionString = "";
		
	return;
	
}









