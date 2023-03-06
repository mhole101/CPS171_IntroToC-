//************************************************************************************************************************************************************************************************//
//************************************************************************************************************************************************************************************************//
//                                                                                                                                                                                                //
//																				Machine Problem 3 - Loops                                                                                         //
//                                                                                                                                                                                                //
//																						By: Matt Hole                                                                                             //
//                                                                                                                                                                                                //
//																					Created February 20th, 2020                                                                                   //
//                                                                                                                                                                                                //
//                                                                                                                                                                                                //
//													This program was created to determine the amount of apartment units rented to miximize profits                                                //
//                                                  for a real estate office.  This program will prompt the user to input the total amount of units                                               //
//                                                  in the apartment complex,  the rent rate at which all apartment units are rented, the rent  increase                                          //
//													that results in the loss of a renter, and the average amount to maintain each unit per month.                                                 //
//													The prgram will then take all of these variables and run an algorithm to determine cost of rent,                                              //                           //
//                                                  and how many units are required to maximize profit at this location.                                                                          //                                                                   //
//														Liberal Arts:                                                                                                                             //
//									                                                                                                                                                              //
//																                                                                                                                                  //
//																                                                                                                                                  //
//																                                                                                                                                  //
//																                                                                                                                                  //
//																                                                                                                                                  //
//                                                                                                                                                                                                // 
//														                                                                                                                                          //
//                                                                                                                                                                                                // 
//																                                                                                                                                  //
//																                                                                                                                                  //
//                                                                                                                                                                                                //
//                                                                                                                                                                                                //
//************************************************************************************************************************************************************************************************//
//************************************************************************************************************************************************************************************************//


#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>	
#include <fstream>


using namespace std;

const string INTRO = "This program is written by: Matt Hole ";
const string TOTAL_NUMBER_OF_UNITS_PROMPT = "Please input total number of apartment units: ";
const string RENT_RATE_AT_FULL_OCCUPANCY_PROMPT = "Please enter the rent rate to occupy all units: $";
const string RENT_INCREASE_RATE_PROMPT = "Please enter the increase rate that will lose a renter: $";
const string AVERAGE_COST_OF_MAINTENANCE_PER_UNIT_PROMPT = "Please input the average cost to maintain a unit per month: $";
const string OUTPUT_NUMBER_OF_UNITS_AT_MAXIMUM_PROFIT = "In order to obtain maximum profit you must rent ";
const string OUTPUT_UNITS = " units.";
const string OUTPUT_NUMBER_OF_INCREASES_REQUIRED = "This will require you to increase rent ";
const string OUTPUT_TIMES = " times.";
const string OUTPUT_RENT_RATE_AT_MAXIMUM_PROFIT = "Which will cause rent to cost $";
const string OUTPUT_PER_UNIT = " per unit.";
const string OUTPUT_TOTAL_RENT_COLLECTED_AT_MAXIMIMU_PROFIT = "The total rent collected will be $";
const string OUTPUT_TOTAL_MAINTENANCE_COST_AT_MAXIMUM_PROFIT = "The total maintenance costs for all units will be $";
const string OUTPUT_TOTAL_PROFIT = "Total Profit will be $";
const string PERIOD = ".";
const string TABLE_INTRO = "The table below shows a cost breakdown per unit rented";
const string TABLE_INCREASES_ABRV = "INC = Number of rent increases";
const string TABLE_RENT_RATE_ABRV = "RR = Rent Rate";
const string TABLE_RENT_COLLECTED_ABRV = "RC = Rent Collected";
const string TABLE_MAINTENANCE_COSTS_ABRV = "MC = Maintenance costs";
const string TABLE_PROFIT_ABRV = "PRO = Profit";
const string TABLE_UNITS = "Units";
const string TABLE_INCREASES = "INC";
const string TABLE_RENT_RATE = "RR";
const string TABLE_RENT_COLLECTED = "RC";
const string TABLE_MAINTENANCE_COSTS = "MC";
const string TABLE_PROFIT = "PRO";
const string TABLE_FILE_LOCATION_PROMPT = "A printable cost break down table has been created in your project directory ";



int main()
{
	
	int totalNumberOfUnits = 0;
	double rentRateAtFullOccupancy = 0.00;
	double rentIncreaseRate = 0.00;
	double averageCostOfMaintenancePerUnit = 0.00;
	double totalRentAtFullOccupancy = 0.00;
	double totalCostOfMaintenanceAtFullOccupancy = 0.00;
	double profitAtFullOccupancy = 0.00;
	int currentNumberOfUnits = 0;
	double currentRentRate = 0.00;
	double currentTotalRent = 0.00;
	double currentCostOfMaintenance = 0.00;
	double currentProfit = 0.00;
	int bufferedNumberOfUnits = 0;
	double bufferedRentRate = 0.00;
	double bufferedTotalRent = 0.00;
	double bufferedCostOfMaintenance = 0.00;
	double bufferedProfit = 0.00;
	int numberOfRentRateIncreases = 0;
	int currentNumberOfRentRateIncreases = 0;
	int numberOfUnitsToPrintInTable = 0;
	int tableNumberOfUnits = 0;
	int tableIncreases = 0;
	double tableRentRate = 0.00;
	double tableRentCollected = 0.00;
	double tableMaintenanceCosts = 0.00;
	double tableProfit = 0.00;

	ofstream outData;


	cout << fixed << setprecision(2);

	cout << INTRO << endl << endl << endl << endl;
	cout << TOTAL_NUMBER_OF_UNITS_PROMPT;
	cin >> totalNumberOfUnits;
	cout << endl << endl << RENT_RATE_AT_FULL_OCCUPANCY_PROMPT;
	cin >> rentRateAtFullOccupancy;
	cout << endl << endl << RENT_INCREASE_RATE_PROMPT;
	cin >> rentIncreaseRate;
	cout << endl << endl << AVERAGE_COST_OF_MAINTENANCE_PER_UNIT_PROMPT;
	cin >> averageCostOfMaintenancePerUnit;
	cout << endl << endl;


	totalRentAtFullOccupancy = totalNumberOfUnits * rentRateAtFullOccupancy;
	totalCostOfMaintenanceAtFullOccupancy = totalNumberOfUnits * averageCostOfMaintenancePerUnit;
	profitAtFullOccupancy = totalRentAtFullOccupancy - totalCostOfMaintenanceAtFullOccupancy;
	bufferedNumberOfUnits = totalNumberOfUnits;
	bufferedRentRate = rentRateAtFullOccupancy;
	bufferedTotalRent = totalRentAtFullOccupancy;
	bufferedCostOfMaintenance = totalCostOfMaintenanceAtFullOccupancy;
	bufferedProfit = profitAtFullOccupancy;

	do
	{
		currentProfit = bufferedProfit;
		numberOfRentRateIncreases += 1;
		bufferedNumberOfUnits = totalNumberOfUnits - numberOfRentRateIncreases;
		bufferedRentRate = rentRateAtFullOccupancy + (numberOfRentRateIncreases * rentIncreaseRate);
		bufferedTotalRent = bufferedNumberOfUnits * bufferedRentRate;
		bufferedCostOfMaintenance = bufferedNumberOfUnits * averageCostOfMaintenancePerUnit;
		bufferedProfit = bufferedTotalRent - bufferedCostOfMaintenance;
	} while (currentProfit < bufferedProfit); 


	currentNumberOfRentRateIncreases = (numberOfRentRateIncreases - 1);
	currentRentRate = (rentRateAtFullOccupancy + (currentNumberOfRentRateIncreases * rentIncreaseRate));
	currentNumberOfUnits = (totalNumberOfUnits - currentNumberOfRentRateIncreases);
	currentTotalRent = (currentNumberOfUnits * currentRentRate);
	currentCostOfMaintenance = (currentNumberOfUnits * averageCostOfMaintenancePerUnit);
	currentProfit = (currentTotalRent - currentCostOfMaintenance);


	
		cout << OUTPUT_NUMBER_OF_UNITS_AT_MAXIMUM_PROFIT << currentNumberOfUnits << OUTPUT_UNITS << endl << endl;
		cout << OUTPUT_NUMBER_OF_INCREASES_REQUIRED << currentNumberOfRentRateIncreases << OUTPUT_TIMES << endl << endl;
		cout << OUTPUT_RENT_RATE_AT_MAXIMUM_PROFIT << currentRentRate << PERIOD << endl << endl;
		cout << OUTPUT_TOTAL_RENT_COLLECTED_AT_MAXIMIMU_PROFIT << currentTotalRent << PERIOD << endl << endl;
		cout << OUTPUT_TOTAL_MAINTENANCE_COST_AT_MAXIMUM_PROFIT << currentCostOfMaintenance << PERIOD << endl << endl;
		cout << OUTPUT_TOTAL_PROFIT << currentProfit << PERIOD << endl << endl;
		cout << TABLE_FILE_LOCATION_PROMPT << endl << endl << endl;


		numberOfUnitsToPrintInTable = currentNumberOfUnits + 5; 

		outData.open("CostBreakDownTable.txt");
				

		outData << TABLE_INTRO << endl << endl << endl
			    << TABLE_INCREASES_ABRV << endl
			    << TABLE_RENT_RATE_ABRV << endl
			    << TABLE_RENT_COLLECTED_ABRV << endl
			    << TABLE_MAINTENANCE_COSTS_ABRV << endl
			    << TABLE_PROFIT_ABRV << endl << endl << endl;

		outData << left 
			    << setw(10) << TABLE_UNITS
			    << setw(10) << TABLE_INCREASES 
			    << setw(10) << TABLE_RENT_RATE 
			    << setw(10) << TABLE_RENT_COLLECTED
			    << setw(10) << TABLE_MAINTENANCE_COSTS 
			    << setw(10) << TABLE_PROFIT << endl << endl;

		for (int tableIndex = 0; tableIndex <= numberOfUnitsToPrintInTable; tableIndex++)
		{
			tableNumberOfUnits = totalNumberOfUnits - tableIndex;
			tableIncreases = tableIndex;
			tableRentRate = (rentRateAtFullOccupancy + (tableIncreases * rentIncreaseRate));
			tableRentCollected = tableRentRate * tableNumberOfUnits;
			tableMaintenanceCosts = averageCostOfMaintenancePerUnit * tableNumberOfUnits;
			tableProfit = tableRentCollected - tableMaintenanceCosts;
						
			outData << setw(10) << tableNumberOfUnits
				    << setw(10) << tableIncreases
				    << setw(10) << tableRentRate
				    << setw(10) << tableRentCollected
				    << setw(10) << tableMaintenanceCosts
				    << setw(10) << tableProfit
				    << endl << endl;
		}

		outData.close();

			   


	return 0; 



}