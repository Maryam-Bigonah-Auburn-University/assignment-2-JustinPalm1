#include<iostream>
#include<string>

using namespace std; 

bool isleapYear(int year); // Function to check if a year is a leap year
int getCenturyValue (int year); // Function to get the century value from the year
int getYearValue(int year); // Function to get the year value from the year
int getMonthValue(int month, int year); // Function to get the month value from the month and year

int main() {
  
    int month,
        day = 0, 
        year = 0, 
        sum = 0,
        day_of_week = 0;
    string day_string = ""; 

    cout << "enter the month"<< endl; 

    cin >> month; // Read month input from user

    while (month < 1 || month > 12){

        cout << "please give a valid month";
        cin >> month; // Prompt again if invalid
    }

    cout << "enter a day" << endl;

    cin >> day; // Read day input from user

    // Validate the day input for months with 30 days
    if (month == 4 || month == 6|| month == 9 || month ==11 ){

        while (day < 1 || day > 30) {
			cout << "Enter a value between 1 and 30:";
			cin  >> day; // Prompt again if invalid
		}

}
    // Prompt for the year input
    cout << "Enter the year: ";
    
    cin >> year;

    // Calculate the day of week
	sum = day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year);
	day_of_week = sum % 7;
	
	// Find corresponding day name
	switch(day_of_week) {
	
	case 0: 
           day_string = "Sunday"; 
           break; 
	case 1:
	   day_string = "Monday"; 
	   break;	
        case 2: 
	   day_string = "Tuesday"; 
	   break;
        case 3: 
	   day_string = "Wednesday"; 
	   break;
	case 4: 
	   day_string = "Thursday"; 
 	   break;
	case 5: 
	   day_string = "Friday"; 
	   break;
	case 6: 
	   day_string = "Saturday"; 
	   break;
		
    }
    
    // Output the result to the user
    cout << "The day of the week is: " << day_string << endl;
    return 0; // End of the program

}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
	// Leap year is divisible by 400 or divisible by 4 and not 100
	return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// Function to calculate the century value based on the year
int getCenturyValue(int year) {
	int century = 0,
	    century_value = 0;
	
	century = year / 100; // Determine the century
	century_value = (3 - (century % 4)) * 2; // Calculate the century value
	return century_value;
}

// Function to calculate the year value based on the year
int getYearValue(int year) {
	int year_value = 0;

	year_value = year % 100; // Get the last two digits of the year
	return year_value + (year_value / 4); // Return year value considering leap years
	
}

// Function to calculate the month value based on the month and year
int getMonthValue(int month, int year) {
	switch(month) {
		case 1: //January
			if (isLeapYear(year))
				return 6;
			else
				return 0;
		case 2: //Febuary
			if (isLeapYear(year))
				return 2;
			else
				return 3;
		case 3: //March
			return 3;
		case 4: //April
			return 6;
		case 5: //May
			return 1;
		case 6: //June
			return 4;
		case 7: //July
			return 6;
		case 8: //August
			return 2;
		case 9: //September
			return 5;
		case 10: //October
			return 0;
		case 11: //November
			return 3;
		case 12: //December
			return 5;
	}			
}



