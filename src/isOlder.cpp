/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int check(int day, int month, int year)
{
	int ldate[13] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31 };

	if (year % 4 == 0)
		ldate[1] = 29;

	if (day <= ldate[month - 1] && (month >= 1 && month <= 12))
		return 1;
	else
		return 0;
}

int isOlder(char *dob1, char *dob2) {

	int day1 = 0, day2 = 0, month1 = 0, month2 = 0, year1 = 0, year2 = 0, i, c1 = 0, c2 = 0;

	for (i = 0; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		day1 = day1 * 10 + dob1[i] - '0';
		day2 = day2 * 10 + dob2[i] - '0';
	}i++;
	for (i = i; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		month1 = month1 * 10 + dob1[i] - '0';
		month2 = month2 * 10 + dob2[i] - '0';
	}i++;
	for (i = i; dob1[i] >= '0' && dob1[i] <= '9'; i++)
	{
		year1 = year1 * 10 + dob1[i] - '0';
		year2 = year2 * 10 + dob2[i] - '0';
	}i++;
	//printf("%d-%d-%d\n%d-%d-%d",day1,month1,year1,day2,month2,year2);
	c1 = check(day1, month1, year1);
	c2 = check(day2, month2, year2);

	if (c1 == 0 || c2 == 0)
		return -1;
	else if (year1 > year2)
		return 2;
	else if (year1 < year2)
		return 1;
	else if (month1 < month2)
		return 1;
	else if (month1 > month2)
		return 2;
	else if (day1 > day2)
		return 2;
	else if (day1 < day2)
		return 1;
	else
		return 0;
}