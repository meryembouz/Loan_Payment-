#ifndef Numperiods_h
#define Numperiods_h

#include<iostream>
#include<iomanip>
#include<cmath>


using namespace std;

double N() {

// Defining Variables: 

	double r, pmt, int_paid, amt_paid, PV;
	double n;

	double rate, principal, payment, interest_paid, amount_paid;
	int num_periods;

// Ask user for inputs with data sanity check:

//***************************Loan Principal:**********************************************************
	cout << endl << endl;
	cout << "****************************Computing Number of Periods:*****************************************" << endl;
	cout << endl << endl;
	cout << "1. Please enter the total amount of the loan:  ";
	while (!(cin >> principal) || principal < 0)
	{
		cout << "Please enter only positive numbers. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	cout << endl << endl;
//**************************Interest Rate:***********************************************************
	cout << "2. Please provide the yearly interest rate of the loan in percentage (%):  ";
	while (!(cin >> rate) || rate < 0)
	{
		cout << "Please enter only positive rates in Percentage. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	cout << endl << endl;
//***************************Loan Payment:**********************************************************
	cout << "3. Please provide the yearly payment on the loan:  ";
	while (!(cin >> payment) || payment < 0)
	{
		cout << "Please enter only positive rates in Percentage. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}

// Computating the number of periods:
	pmt = payment;
	r = rate / 100;
	PV = principal;

	n = log(1 + ((PV* r) / (pmt - PV* r)) )/ log(1 + r);

	amt_paid = n * payment;
	int_paid = (n * payment) - principal;
	interest_paid = int_paid;
	amount_paid = amt_paid;

	cout << endl << endl;

// Displaying the results:

	cout << "************************************" << endl;
	cout << setprecision(2) << fixed << endl;
	cout << endl << endl;

	cout << left << setw(30) << "Loan Amount: ";
	cout << right << setw(30) << "$" << right << setw(10) << principal << endl;

	cout << left << setw(30) << "Annual Interest Rate:";
	cout << right << setw(30) << "%" << right << setw(10) << rate << endl;

	cout << left << setw(30) << "Annual Periods:";
	cout << right << setw(30) << " " << right << setw(10) << ceil(n) << endl;

	cout << left << setw(30) << "Annual Payment:";
	cout << right << setw(30) << "$" << right << setw(10) << payment << endl;

	cout << left << setw(30) << "Amount Paid Back:";
	cout << right << setw(30) << "$" << right << setw(10) << amt_paid << endl;

	cout << left << setw(30) << "Interest Paid:";
	cout << right << setw(30) << "$" << right << setw(10) << interest_paid << endl;

	cout << endl << endl;
	cout << "************************************" << endl;

// Terminate Program
	return 0;
}

#endif 

