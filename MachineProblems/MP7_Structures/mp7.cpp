//*****************************************************************************//
//                                                                             //
//                                                                             //
//                Machine Problem  - Structures                                //
//                                                                             //
//                             By : Matt Hole                                  //
//                                                                             //
//    This program reads an input file.  The input file has number of          //
//    divers on the first line.  The following lines contain the name          //
//    of the divers, difficulty of their dive, scores by the judges,           //
//    and their final scores.  This program sorts the scores of the            //
//    divers in increasing order, and displays all the information in          //
//    a table.  It also sorts through the total scores to find the winner.     //
//    it then prints out the table and the winner.                             //
//                                                                             //
//*****************************************************************************//

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>

using namespace std;

const int NUMBER_OF_JUDGES = 9;

struct scoringData
{
	string diversName;
	double diff;
	double scores[NUMBER_OF_JUDGES];
	double total;
};


int get_number_of_divers(ifstream&);
void output_data(scoringData[], int, int, int);
void read_data_to_struct(ifstream&, scoringData[], int&, int);
void sort_scores(scoringData[], int, int);
int find_winner(scoringData[], int);





int main()
{
	ifstream inData;
	scoringData diversScoringData[7];
	int numOfDivers = 7;
	int numOfScores = NUMBER_OF_JUDGES;
	int winnersPos;
	inData.open("m7dive.txt");
	if (!inData.is_open()) // Checks if input is open
	{
		cout << "\"m7dive.txt\" did not open" << endl;
		return -1;
	}
		
	numOfDivers = get_number_of_divers(inData); // gets number of divers from file
		
	read_data_to_struct(inData, diversScoringData, numOfDivers, numOfScores); // moves data from input file into struct
	
	winnersPos = find_winner(diversScoringData, numOfDivers); // finds winner
	
	sort_scores(diversScoringData, numOfDivers, numOfScores); // sorts the scores in increasing order

	output_data(diversScoringData, numOfDivers, numOfScores, winnersPos); // outputs data to screen

	
	return 0;
}
// This function gets the number of divers from the input file
int get_number_of_divers(ifstream& inData)
{
	string numOfDiversString;
	int numOfDivers;
	getline(inData, numOfDiversString);
	numOfDivers = stoi(numOfDiversString); // converts stirng int to int only if compiler supports C++11 or above.

	return numOfDivers;
}
// This function outputs the table and the winner to the screen
void output_data(scoringData diversScoringData[], int numberOfElements, int numberOfJudges, int winnersPos)
{
	cout << "MP7 - Structures" << endl
		<< "By: Matt Hole" << endl << endl;
	
	cout << setw(12) << left << "NAME"
		<< "DIFF" << "\t\t"
		<< setw(36) << left << "SORTED SCORES"
		<< "POINTS" << endl;

	
	for (int j = 0; j < numberOfElements; j++)
	{
		cout << setw(12) << left
			<< diversScoringData[j].diversName;
		cout << setprecision(1) << fixed << diversScoringData[j].diff << "\t\t";
		for (int k = 0; k < numberOfJudges; k++)
			cout << setw(4) << diversScoringData[j].scores[k] << " ";
		cout << diversScoringData[j].total << endl;

	}

	cout << endl << "The winner is: " << diversScoringData[winnersPos].diversName << "!" << endl;

}
// This function moves the data to the struct from the input file
void read_data_to_struct(ifstream& inData, scoringData diversScoringData[], int& numberOfElements, int numberOfJudges)
{

	
	for (int i = 0; i < numberOfElements; i++)
	{
		inData >> diversScoringData[i].diversName;
		inData >> diversScoringData[i].diff;
		for (int j = 0; j < numberOfJudges; j++)
			inData >> diversScoringData[i].scores[j];
		inData >> diversScoringData[i].total;

	}
		
} 
// This function sorts the scores in increasing order
void sort_scores(scoringData diversScoringData[], int numOfDivers, int numOfJudges)
{	
	int firstOutOfOrder, location;
	double temp;
	for (int i = 0; i < numOfDivers; i++)
	{
		for (firstOutOfOrder = 1; firstOutOfOrder < numOfJudges; firstOutOfOrder++)
			if (diversScoringData[i].scores[firstOutOfOrder] < diversScoringData[i].scores[firstOutOfOrder - 1])
			{
				temp = diversScoringData[i].scores[firstOutOfOrder];
				location = firstOutOfOrder;
				do
				{
					diversScoringData[i].scores[location] = diversScoringData[i].scores[location - 1];
					location--;
				} while (location > 0 && diversScoringData[i].scores[location - 1] > temp);
				diversScoringData[i].scores[location] = temp;
			}
	}
}
// This function searches through the struct to find the winner and returns the position
int find_winner(scoringData diversScoringData[], int numOfDivers)
{
	int winnersPos = 0;
	double tempHighScore = diversScoringData[0].total;
	
	for (int i = 1; i < numOfDivers; i++)
	{
		if (diversScoringData[i].total > tempHighScore)
		{
			tempHighScore = diversScoringData[i].total;
			winnersPos = i;
		}
	}
	return winnersPos;
}


