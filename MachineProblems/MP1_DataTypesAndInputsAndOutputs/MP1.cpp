/**
		MP1 
		
		Created by Matt Hole 27 January 2020
			
		This program is created to do basic geometry calculations.  In this program the user is prompted to put in a length in centimeters.
		The centimeters is then converted into meters.  Once the length is converted into meters the program calculates the area of a square (L*W),
		and area of a circle (pi*radius^2).  After the areas are calculated it then gives the difference of the two areas (Area of square - area of circle).
		The program then uses the floor and ceil functions to round the length to the nearest integer value above and below the current length.
		These values are then used to calculate the area of a cube.  

*/



#include <iostream>		// I/O cin and cout																						
#include <iomanip>		// setw, setprecision
#include <cmath>		// ceil(), floor()

using namespace std;

const double PI = 3.14159;																									// This constant double declaration and assignment is used for the value of pi.

int main()

{				
	double lengthInCentimeters, lengthInMeters,	radiusOfCircle;																// Declarations for length and radius.
	double areaOfSquareInMetersSquared, areaOfCircleInMetersSquared;														// Declaration for area of square and circle.
	double volumeOfCubeInMetersCubed, differenceInAreas;																	// Declaration for volume of cube.
	int lengthInMetersRoundedDown, lengthInMetersRoundedUp;																	// Declaration for rounded lengths.
	double volumeOfCubeWithLowNumber, volumeOfCubeWithHighNumber;															// Declaration for volumes of cubes based off of rounded numbers.


	cout << "Geometery formulas by Matt Hole" << endl;																		// This output is for the tile for the output.

	cout << "" << endl;																										// This output is to print a blank line between the title and the user prompt.
	
	cout << "Input a floating point number for length  ";																	// This output instructs the user to input a length.
	
	cin >> lengthInCentimeters;																								// This input takes the data input by the user and places it in the lenthInCentimeters variable.

	cout << "" << endl;																										// This output prints a blank line between the user prompt and the echo prompt.
		
	lengthInMeters = lengthInCentimeters / 100;																				// This declaration converts the length input by the user into meters.

	radiusOfCircle = (lengthInMeters / 2);																					// This declaration is used to have a variable for calculating area of the circle.

	areaOfSquareInMetersSquared = (lengthInMeters * lengthInMeters);														// This expression calculates the area of the square in meters squared.

	areaOfCircleInMetersSquared = (PI * (radiusOfCircle * radiusOfCircle));													// This expression calculates the area of a circle (pi * radius^2) in meters squared.

	differenceInAreas = (areaOfSquareInMetersSquared - areaOfCircleInMetersSquared);										// This expression calculates the difference in areas (Area of square - Area of circle) in meters squared.

	lengthInMetersRoundedDown = floor(lengthInMeters);																		// This floor function is used to round down the length and store in a variable for volume calculation.

	volumeOfCubeWithLowNumber = (lengthInMetersRoundedDown * lengthInMetersRoundedDown * lengthInMetersRoundedDown);		// This expression calculates the volume of a cube with the rounded down lentgh in meters cubed.

	lengthInMetersRoundedUp = ceil(lengthInMeters);																			// This ceil function is used to round the length up to the nearest integer, and then store it in a variable for volume calculation.

	volumeOfCubeWithHighNumber = (lengthInMetersRoundedUp * lengthInMetersRoundedUp * lengthInMetersRoundedUp);				// This expression calculates the volume of a cube with the rouded up length in meters cubed.

	cout << fixed << setprecision(4);																						// This is used to manipulate the appearance of the output data.

	cout << "You entered " << lengthInCentimeters << "cm or " << lengthInMeters << "m. " << endl;							// This output "echos" the user input.

	cout << "" << endl;																										// This output statement is used to print a blank space in between the echo and the answers.

	cout << "Area of the square is " << setprecision(7) << areaOfSquareInMetersSquared << " sq. m. " << endl;				// This output statement prints out the area of the square.

	cout << "Area of the circle is " << areaOfCircleInMetersSquared << " sq. m. " << endl;				// This output statment prints out the area of a circle.

	cout << "The difference in areas is " << setprecision(8) << differenceInAreas << " sq. m." << endl;					// This output statement prints out the difference between the area of the square and area of the circle.

	cout << "The volume of the cube with rounded down length is " << volumeOfCubeWithLowNumber << " cu. m." << endl;		// This output statement prints out the volume of the cube with the rounded down length.

	cout << "The volume of the cube with the length rounded up is " << volumeOfCubeWithHighNumber << " cu. m." << endl;		// This output statement prints out the voulume of the cube with the rounded up length.

	
	return 0;

		


}
