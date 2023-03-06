//***********************************************************************************************//
//                                                                                               //
//                                                                                               //
//                                     Machine Problem 5 - Arrays                                //
//                                                                                               //
//                                         By: Matt Hole                                         //
//                                                                                               //
//             This program was created to take a file that has a keyword along with             //
//             lines of code to be encrypted and decrypted based off of the key word.            //
//             The data is processed and outputs the keyword, the array of the keyword           //
//             used for encryption and decryption, and each line that of the input               //
//             followed by the line after it has been encrypted and decrypted.                   //
//                                                                                               //
//             I decided to create another array to be later printed out to display the          //
//             codekey array.                                                                    //
//                                                                                               //
//***********************************************************************************************//

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const string KEYWORD_OUTPUT = "The keyword is: ";
const int CODEKEY_NUMBER_OF_ROWS = 5;
const int CODEKEY_NUMBER_OF_COLUMNS = 5;
const int CODEKEY_OUTPUT_NUMBER_OF_ROWS = 13;
const int CODEKEY_OUTPUT_NUMBER_OF_COLUMNS = 24;

void get_line(ifstream&, string&, int&);
string check_for_duplicate_letters(string);
string create_keyword_string(string&);
string create_table_string(string);
void input_string_to_array(char[][CODEKEY_NUMBER_OF_COLUMNS], string);
void initilize_codekey_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS]);
void add_column_seperations_to_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS]);
void add_row_seperations_to_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS]);
void add_row_numbers_to_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS]);
void add_column_numbers_to_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS]);
void add_codekey_to_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], string);
void create_codekey_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], string);
void print_codekey_output_array(char[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], int);
int determine_process_type(string);
string create_string_to_process(string);
void process_char(char[][CODEKEY_NUMBER_OF_COLUMNS], char&);
void make_string_lower(string&);
string process_string(char[][CODEKEY_NUMBER_OF_COLUMNS], string&, int);
void print_output_data(string, string, int);




int main()
{
	ifstream inData;
	char codeKeyArray[CODEKEY_NUMBER_OF_ROWS][CODEKEY_NUMBER_OF_COLUMNS];
	char codeKeyOutputArray[CODEKEY_OUTPUT_NUMBER_OF_ROWS][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS];
	string readString = "";
	string keyword = "";
	string tableString = "";
	string stringToProcess = "";
	string processedString = "";
	int stringSize = 0;
	int getLineCounter = 0;
	int processType = 0; // 0 = process type not detected, 1 = Decrypt, 2 = Encrypt


	inData.open("mp5Data.txt"); 

	if (!inData.is_open())
	{
		cout << "mp5Data.txt did not open proplerly" << endl;
		return -1;
	}

	// This output is used to print the title of the program and the author before
	// reading, manipulating, and outputting data.

	cout << "MP5 - Arrays" << endl
		<< "Cryptography" << endl
		<< "Written by: Matt Hole" << endl << endl << endl;

	if (getLineCounter < 1) // loop for processing keyword.
	{
		get_line(inData, readString, getLineCounter); // streams the first line of the input file to a string.

		cout << KEYWORD_OUTPUT << readString << endl << endl; // outputs the keyword to the console.

		keyword = create_keyword_string(readString); // creates a keyword string.

		tableString = create_table_string(keyword); // creates a string to be placed into the array.

		input_string_to_array(codeKeyArray, tableString); // inputs tables string into the codekey array.

		create_codekey_output_array(codeKeyOutputArray, tableString); // creates an array that is used to display the
		                                                              // codekey array on the output consule.  
		
		print_codekey_output_array(codeKeyOutputArray, 12);  // prints out the codekey output on the output consule.
		
	}




	if (getLineCounter >= 1) // check to make sure the keyword has already been streamed.
	{
		while (!inData.eof()) // loops used to read the until the end of the file.
		{
			get_line(inData, readString, getLineCounter); // streams lines from the input file to be processed.
						
		    processType = determine_process_type(readString); // determines the process type of the line to be processed.
			
		    stringToProcess = create_string_to_process(readString); // removes the first two chars from the line and 
			                                                        //creates string to be processed.
			    
			processedString = process_string(codeKeyArray, stringToProcess, processType); // creates a processed string to be displayed.
		   
			print_output_data(stringToProcess, processedString, processType); // displays the data to the console.
	    }
    }

	inData.close();
		
	return 0;
}





// get_line 
//
// This function is passed a input stream object, a string, and an int.
// It verifies that the file is open.  It then grabs a line from the input 
// file and inputs it into a string.  The string is passed by reference to be 
// used later in the program.  Everytime this function is called it increments
// a counter to be used later in the program.
void get_line(ifstream& inData, string& line, int& counter)
{
	

	if (!inData.is_open())
	{
		cout << "File did not open in get_line function" << endl;
		return;
	}

	getline(inData, line);

	counter++;
	
	

}

// check_for_duplicate_letters 
//
// This function is passed a string.  It then checks the string
// for duplicate letters and creates a news string without them.
// The new string is passed back by the function.
string check_for_duplicate_letters(string checkString)
{
	int stringSize = checkString.length();
	int index = 0;
	int checkStringFindIndex = 0;
	string newString = "";

	while (index < stringSize)
	{
		checkStringFindIndex = newString.find(checkString[index]);

		if (checkStringFindIndex == -1)
			newString = newString + checkString[index];

		index = index++;
	}

	return newString;
}

// create_keyword_string
//
// This function is passed the keyword in a string.
// It then removes duplicate letters and creates a new string.
// The new string is passed back by the function.
string create_keyword_string(string& keyword)
{
	string newKeyword = "";
	newKeyword = check_for_duplicate_letters(keyword);
	keyword = "";
	return newKeyword;
}

// create_table_string
//
// This function is passed a string and returns a string.
// It is passed the keyword without any reoccuring letters and 
// then adds the rest of the letters of the alphabet that have not
// been used yet and returns this as a string.
string create_table_string(string newKeyword)
{
	string alphabetString = "ABCDEFGHIJKLMNOPQRSTUVWXY";
	string tempTableString = newKeyword + alphabetString;
	string tableString = "";
		
	tableString = check_for_duplicate_letters(tempTableString);
	
	return tableString;
}

// input_string_to_array
//
// This function is passed the codekey array and a string to be input into the array.
// It then inputs the string into the array to create the array used for cryptography.
void input_string_to_array(char array[][CODEKEY_NUMBER_OF_COLUMNS], string stringToBeInput)
{
	int stringPos = 0;
	int row;
	int col;
	for (row = 0; row < CODEKEY_NUMBER_OF_ROWS; row++)
		for (col = 0; col < CODEKEY_NUMBER_OF_COLUMNS; col++)
		{
			array[row][col] = stringToBeInput[stringPos];
			stringPos++;
		}

}

// initilize_codekey_output_array
//
// This function is passed the codekey output array.  
// It is used to initialize the array.
void initilize_codekey_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS])
{
	int rows, columns;

	for (rows = 0; rows < CODEKEY_OUTPUT_NUMBER_OF_ROWS; rows++)
		for (columns = 0; columns < CODEKEY_OUTPUT_NUMBER_OF_COLUMNS; columns++)
			outputArray[rows][columns] = ' ';
}

//add_column_seperations_to_output_array
//
// This function is passed the codekey output array and adds the vertical line char to seperate the columns.
// Used for output display.
void add_column_seperations_to_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS])
{
	const char COLUMNS_SEPERATION_CHAR = '|';
	int rows, columns;
	
	for (rows = 1; rows < CODEKEY_OUTPUT_NUMBER_OF_ROWS; rows = rows + 2)
		for (columns = 3; columns <= CODEKEY_OUTPUT_NUMBER_OF_COLUMNS + 1; columns = columns + 4)
			outputArray[rows][columns] = COLUMNS_SEPERATION_CHAR;
}

//add_row_seperations_to_output_array
//
// This function is passed the codekey output array and adds dash chars to it to seperate the rows.  
// Used for output display.
void add_row_seperations_to_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS])
{
	const char ROWS_SEPERATION_CHAR = '-';
	int rows, columns;
	
	for (rows = 0; rows < CODEKEY_OUTPUT_NUMBER_OF_ROWS; rows = rows + 2)
		for (columns = 0; columns < CODEKEY_OUTPUT_NUMBER_OF_COLUMNS; columns++)
			outputArray[rows][columns] = ROWS_SEPERATION_CHAR;	
}

// add_row_numbers_to_output_array
//
// This function is passed the codekey output array and adds row numbers to it.
// Used for output display.
void add_row_numbers_to_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS])
{
	const int columns = 1;
	int rowNumber = 48;
	int rows;

	for (rows = 3; rows < CODEKEY_OUTPUT_NUMBER_OF_ROWS; rows = rows + 2)
	{
		outputArray[rows][columns] = rowNumber;
		rowNumber++;
	}
}

// add_column_numbers_to_output_array
//
// This function is passed the codekey output array and adds column numbers to it.
// Used for output display.
void add_column_numbers_to_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS])
{
	const int rows = 1;
	int columnNumber = 48;
	int columns;

	for (columns = 5; columns < CODEKEY_OUTPUT_NUMBER_OF_COLUMNS; columns = columns + 4)
	{
		outputArray[rows][columns] = columnNumber;
		columnNumber++;
	}
}

// add_codekey_to_output_array
//
// This funtion is passed the codekey output array and the codekey in a string.
// It then adds the codekey string into the proper positions on the codekey output
// template table. 
void add_codekey_to_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], string codekey)
{
	int rows, columns;
	int stringIndex = 0;
	
	for (rows = 3; rows < CODEKEY_OUTPUT_NUMBER_OF_ROWS; rows = rows + 2)
		for (columns = 5; columns < CODEKEY_OUTPUT_NUMBER_OF_COLUMNS; columns = columns + 4)
		{
			outputArray[rows][columns] = codekey[stringIndex];
			stringIndex++;
		}
	
	
}

// create_codekey_output_array
//
// This funtion is passed the codekey output array and the codekey in a string.
// It then uses other functions and creates the codekey output array.
void create_codekey_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], string codekey)
{
	initilize_codekey_output_array(outputArray);
	add_column_seperations_to_output_array(outputArray);
	add_row_seperations_to_output_array(outputArray);
	add_row_numbers_to_output_array(outputArray);
	add_column_numbers_to_output_array(outputArray);
	add_codekey_to_output_array(outputArray, codekey);
		

}

// print_codekey_output_array
//
// This function is passed the codkey output array and int value containing the number of rows.
// It then prints out the codekey output array followed by two blank lines to keep data seperated.
void print_codekey_output_array(char outputArray[][CODEKEY_OUTPUT_NUMBER_OF_COLUMNS], int noOfRows)
{
	int row, col;
	for (row = 0; row < noOfRows; row++)
	{
		for (col = 0; col < CODEKEY_OUTPUT_NUMBER_OF_COLUMNS; col++)
			cout << outputArray[row][col];
		cout << endl;
	}
	cout << endl << endl;
}

// determine_process_type
//
// This function takes the line recieved by the input file in string format.
// It then looks at the first char to determine if the string needs to be encrypted,
// decripted, or if not process type has been found.  It then returns an int that specifies
// the process type to be used later in the program.
int determine_process_type(string dataString)
{
	char firstCharInDataString;
	int processType; // 0 = process type not detected, 1 = Decrypt, 2 = Encrypt

	firstCharInDataString = dataString[0];
		
	if (firstCharInDataString == 'D')
	{
		processType = 1;
	}
	else if (firstCharInDataString == 'E')
	{
		processType = 2;
	}
	else
	{
		processType = 0;
	}
		
	return processType;
}

// create_string_to_process
//
// This function is passed a the line from the input in a string.
// It then removes the first two chars from the string to create a string to be processed.
// It then makes use of the toupper function to make all the chars in the string uppercase
// to be processed through the codekey array.  The to be processed is returned by the function.
string create_string_to_process(string dataString)
{
	string stringToProcess = "";
	char stringChar = ' ';
	char upperCaseChar = ' ';
	char processChar = ' ';
	int dataStringLen = 0;
	int stringToProcessLen = 0;

	dataStringLen = dataString.length();
		
	for (int stringIndex = 2; stringIndex <= dataStringLen; stringIndex++)
	{
		stringChar = dataString[stringIndex];
		stringToProcess = stringToProcess + stringChar;
	}
		
	stringToProcessLen = stringToProcess.length();

	for (int processStringIndex = 0; processStringIndex <= stringToProcessLen; processStringIndex++)
	{
		processChar = stringToProcess[processStringIndex];
		upperCaseChar = toupper(processChar);
		stringToProcess[processStringIndex] = upperCaseChar;
	}
		
		
	return stringToProcess;
}

// process_char
//
// This function is passed the code key array and the char to be processed.
// It then searches the array for the char to be processed.  Once found in the array
// the rows and columns are switch for the encryption/decription process.
void process_char(char array[][CODEKEY_NUMBER_OF_COLUMNS], char& charToProcess)
{
	int row = 0;
	int column = 0;
	int numOfRows = 5;
	int numOfColumns = 5;
	


	for (row = 0; row < numOfRows; row++)                    // indexes through the rows of the array
		for (column = 0; column < numOfColumns; column++)    // indexes through the columns of the arrray
		{

			if (array[row][column] == charToProcess)         // searches for the char to be processed
			{				
				charToProcess = array[column][row];          // switches the rows and columns to select the proper char from the array
				return;
			}

		}



}

// make_string_lower
//
// This function indexes through the string that is passed by refence and changes all the char to lowercase.
void make_string_lower(string& processedString)
{
	char lowerChar;
	int stringLen;

	stringLen = processedString.length();

	for (int index = 0; index <= stringLen; index++)
	{
		lowerChar = tolower(processedString[index]);
		processedString[index] = lowerChar;
	}
		
}
// process_string 
//
// This function is passed the codekey array, string to be processed, and the process type.
// Uses the array to encrypt and decrypt the string to be processed and returns a string that has been processed.
// This function also uses the process type to set either the processed string or string to be processe to lower case
// to later be output.
string process_string(char array[][CODEKEY_NUMBER_OF_COLUMNS], string& stringToProcess, int processType)
{
	string processedString = "";
	char currentStringChar;
	char newStringChar;
	int stringToProcessLen = 0;

	stringToProcessLen = stringToProcess.length();


	for (int stringIndex = 0; stringIndex <= stringToProcessLen; stringIndex++) // indexes through string
	{
		currentStringChar = stringToProcess[stringIndex]; // removes char to be processed from string

		if (currentStringChar > 64 && currentStringChar < 90) // checks to see if char is a letter
		{
			process_char(array, currentStringChar);
			processedString = processedString + currentStringChar; // adds proccessed char to string
		}
		else // copies non processed chars into string
		{
			processedString = processedString + currentStringChar;
		}
	}

	if (processType == 1)
		make_string_lower(processedString);
	else if (processType == 2)
		make_string_lower(stringToProcess);



	return processedString;
}

// print_output_data
//
// This function takes the original string to be processed, the proccessed string, and the process
// type and outputs the data to the screen.
void print_output_data(string originalString, string finalString, int processType)
{
	const string DECRIPTS = "decrypts to: ";
	const string ENCRYPTS = "encrypts to: ";
	const string SEPERATE_OUTPUTS = "********************************************************************************";

	switch (processType)
	{
		case 0:
			cout << "No process type determined";
			break;
		case 1: 
			cout << SEPERATE_OUTPUTS << endl
				<< originalString << endl
				<< DECRIPTS << endl
				<< finalString << endl;
			break;
		case 2:
			cout << SEPERATE_OUTPUTS << endl 
				<< originalString << endl
				<< ENCRYPTS << endl 
				<< finalString << endl;
			break;      

	}
	
}








