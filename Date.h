int daysInMonth(int month,int year); 	// # of days in month in year
bool isLeap(int year);   				// is year a leap year

//This is an example of a small C++ class that handles dates
class Date {
  private:
 	//private member variables
    int myDay;                    	// day of week
    int myMonth;                  	// month
    int myYear;                   	// year in four digits, e.g., 2003

    //private member function
    void checkDate(int m, int d, int y); 	// make sure that date is valid

  public:
    // constructors
    Date();                       	// construct date with default value
    Date(int m,int d,int y);      	// construct date with specified values

    // public member functions called accessors since they are used
    // to access the contents of private member variables
    Date finalDate(int DaysChange);
    int absoluteDate();  //Returns the absolute day in the year, without considering months
    int differenceYear(const Date Date_to_compare);             //returns integer with the number of years in between the parameter date object and the calling date object
    int differenceInDays(const Date date_to_compare);           //Takes a Date object as a parameter and calculates the number of days in between them and returns it as an integer
    int getMonth()	const;     // return month corresponding to date
    int getDay()	const;     // return day corresponding to date
    int getYear()	const;     // return year corresponding to date



    //public member function
    void print()	const; //Will cout a date in the 1/1/2003 format

}; // Note the need for a semicolon just like ending a structure
