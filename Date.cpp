// Course: CSC 236 Data Structures
    // Name: Carlos Andres Berejnoi Bejarano
    // Final Project: Reusing the Date class and expanding it to create a date calculator
    /*
       Purpose: This class gives has the capability of:
       - Adding or subtracting days from a date and getting a new date as a result.
       - Determining if a year is a leap year
       - Calculating the years in between two dates
       - Calculating the days in between two dates

    */

#include "Date.h"
#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

bool isLeap(int year) {
// postcondition: returns true if year is a leap year, else returns false

    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    return false;
}

int daysInMonth(int month, int year) {
// postcondition: returns # of days in month in year

    // Start with 31 days and lower it to 30 for April, June, September
    // and November. Then handle February.
    int days = 31;

    if( month == 4 || month == 6 || month == 9 || month == 11 ) {
        days = 30;
   	}
    else if (month == 2) {          // handle February
        days = 28;
        if (isLeap(year)) {        // add 1 for leap years
            days += 1;
       	}
    }
    return days;
}

Date::Date()
//Do not worry about understanding the contents of this constructor yet.
//Getting the current date uses ideas we have not yet learned...
// postcondition: date initialized to default date of today
{
    static struct tm timeHolder;
    static struct tm *date = &timeHolder;
    time_t tloc;

    time(&tloc);

    date = localtime(&tloc);

    myMonth = date->tm_mon + 1;
    myDay   = date->tm_mday;
    myYear  = date->tm_year + 1900;             // struct tm based on 1900
}
Date::Date(int m, int d, int y) {
// postcondition: date properly initialized for date m/d/y
// exception:  if m isn't between 1 and 12, converted to 1
//             if d out of range for month, converted to 1
//			   if year is 2 digits, 1900 is added
    checkDate(m,d,y);
}


int Date::getMonth() const {
// postcondition: returns month of Date
    return myMonth;
}

int Date::getDay() const {
// postcondition: returns day of Date
    return myDay;
}

int Date::getYear() const {
// postcondition: returns year of Date
    return myYear;
}


void Date::print() const {
//postcondition: cout a date in the 1/1/2003 format
    cout << myMonth << "/" << myDay << "/" << myYear;
}


void Date::checkDate( int m, int d, int y ) {
// postcondition: adjusts out-of-range dates before setting member variables
    if (m < 1 || 12 < m) {               // If the month is out of range, set it to January
    	m = 1;
    	cout << "WARNING: Invalid month set to January." << endl;
    }
    myMonth = m;

    if (d < 1 || daysInMonth(m,y) < d) { // If the day is out of range, set it to 1.
    	d = 1;
    	cout << "WARNING: Invalid day set to 1." << endl;
    }
    myDay = d;

    if (y < 100) {                       // If the year is given in 2 digits, add 1900.
    	y = y + 1900;
    }
    myYear = y;
}

//---------------------The code below is my own implementation-----------------------

int Date::absoluteDate(){
/*This function returns an integer that is the absolute day
number in a year.
Example: January 1st will return 1, February 1st will return 32,
December 31st will  return 365 (or 366 if it is a leap year)
*/
    int m = 0;                           //This variable holds the value of the total number of days that are contained in the past and current months
    for (int i = 1; i < getMonth()+1; i++){     //The loop repeats until it gets to the

        m += daysInMonth(i, getYear());
    }

    int remaining_days = (daysInMonth(getMonth(), getYear()) - getDay());   // the number of days left to get to the end of the current month form the current day

    int day_in_year = (m - remaining_days);         // The actual number of days passed since the beginning of the year
    cout << "The absolute day is: " << day_in_year <<"."<< endl;
    return day_in_year;
}

Date Date::finalDate(int DaysChange)
/*  Takes an integer as parameter. The integer is the number of days that the input date must be increased by.
    Post-condition: It will return a Date object with the new date based on the input date from user and the
    number of days that the date must be increased by. It also handles the case when the input parameter is a negative number,
    meaning that it will return a date that is in the past.
*/
{
    int newMonth = getMonth();
    int newDay = getDay();
    int newYear = getYear();

    int day_absolute = absoluteDate();                      //This is the absolute day number based on the user input date

    int newAbsolute = day_absolute + DaysChange;            //It adds the absolute plus any number that the user wants to increase that date to

    if (DaysChange > 0 || DaysChange == 0){
        while (newAbsolute > 365){                  //This while loop will make sure that the sum of the numbers is in the range of 366, and it will also increment the current year if more than one year was added
            if (isLeap(newYear)){               //If the year is a leap year, it reduces the absolute number by 366
                newAbsolute -= 366;
                newYear += 1;                   //Increase the final year by one each time
            }
            else{                               //If the year is a normal year, it reduces the absolute number by 365
                newAbsolute -= 365;
                newYear += 1;
            }
        }
    }
    else{
        if (newAbsolute == 0){                  // This deals with the case of the absolute value being 0 after adding the negative input value
                                            //in that case, the value of newAbsolute will be equal to the maximum number of days that the previous year could hold
            if (isLeap(newYear-1)){
                newAbsolute = 366;
                newYear -= 1;
            }
            else{
                newAbsolute = 365;
                newYear -= 1;
            }

        }
        while (newAbsolute < 0){                  //This while loop will make sure that the sum of the numbers is in the range of 366, and it will also increment the current year if more than one year was added
            if (isLeap(newYear-1)){               //If the year is a leap year, it reduces the absolute number by 366
                    newAbsolute += 366;
                    newYear -= 1;                   //Increase the final year by one each time
            }
            else{                               //If the year is a normal year, it reduces the absolute number by 365
                    newAbsolute += 365;
                    newYear -= 1;
                cout << "The absolute value minus is: "<<newAbsolute<<"."<<endl;
            }
        }
    }

    for (int i = 1; i< 13; i++){                          //This gets the new month and new day based on the value increased. This for loop is equivalent to a recursive function call
        if (daysInMonth(i, newYear) >= newAbsolute){         //If the number of months of the current month "i" is bigger or equal than the absolute number, then the current month is i and the day is the absolute day.
            newMonth = i;                               //Set the final month to i
            newDay = newAbsolute;
            break;                                      // Break out of the for loop. This if clause if equivalent to the base case of a recursive function
        }
        else{
            newAbsolute -= daysInMonth(i, newYear);     //Reduces the absolute value by the number of days in the month, as long as the number of days in the month is smaller than the absolute number of days
        }
    }
    Date newDate(newMonth, newDay, newYear);            // Creates a Date object with the values found through the coding part

    return newDate;

    }

int Date::differenceYear(const Date Date_to_compare){
//The argument is a Date object
//Pre: Date_to_compare is a valid date object
//Post: Returns an integer with the difference in years between the two date objects

    int this_year, compare_year, years_between;
    this_year = getYear();
    compare_year = Date_to_compare.getYear();

    if (this_year>compare_year){                            //Compare the year value of the two date Objects. If the Caller's year is bigger, the difference in year will the following:
        years_between = this_year-compare_year;
    }
    else{                                                   //The following is executed when compare_year is bigger than this_year
        years_between = compare_year - this_year;
    }
    return years_between;                                   //returns the difference in years as an integer

}

int Date::differenceInDays(Date date_to_compare)
/*It will calculate the difference in days between the current Date object and the parameter date_to_compare
    Pre: date_to_compare is a valid Date object
    Post: The difference in days between the two dates will be returned as an integer*/
{
    int lower, bigger;
    lower = getYear();                                      //The year name for the lower date
    bigger = date_to_compare.getYear();                     //Getting the year number for the second, bigger date
//-------------------------------------------------------
    bool lower_leap=false, bigger_leap=false;
    if (isLeap(lower)){
        lower_leap = true;                          //This value will be used in determining if the days in years should be reduced by 365 or 366
    }
    if (isLeap(bigger)){
        bigger_leap = true;
    }
//--------------------------------------------------------------

    int years_to_day = 0;                           //This will contain the number of days
    for (lower=lower; lower<bigger+1; lower++){           //it loops for as many times as the difference in years is between the dates
        if (isLeap(lower)){                         //if the year is leap, it adds 366 days to the variable, otherwise, 365 are added.
            years_to_day += 366;
        }
        else{
            years_to_day += 365;
        }
    }
//-----------------------------------------------------------------

    int under_days, over_days;
    under_days = absoluteDate();                        //The absolute number of days of the lower date year
    over_days = date_to_compare.absoluteDate();         //The absolute number of days of the end date year


//------------------------Adjusting for the boundary years---------------------------------------------------
    if (lower_leap){
        under_days = 366 - under_days;
        years_to_day = years_to_day - 366;                  //this is adjusting for the number of days at the boundaries that was added in the loop. Since not all of those days happened, it is necessary to subtract them
    }
    else{
        under_days = 365 - under_days;
        years_to_day = years_to_day - 365;
    }
    if (bigger_leap){
        years_to_day = years_to_day - 366;
    }
    else{
        years_to_day = years_to_day - 365;
    }

    int final_result;
    final_result = years_to_day + under_days + over_days;               //The final result is the summation of the different pieces.
    return final_result;
}

