#ifndef Payment_h
#define Payment_h

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double PMT() {

// Defining variables: 

	double r, PV, int_paid, amt_paid;
	int n, length;

	double rate, principal, payment, interest_paid, amount_paid;
	int num_periods;

// Ask user for inputs with data sanity check:

//***************************Loan Principal:**********************************************************
	cout << endl << endl;
	cout << "******************************Computing the Payments:***************************************" << endl;
	cout << endl << endl;
	cout << "1. Please enter the total amount of the loan:  ";
	while (!(cin >> principal) || principal < 0)
	{
		cout << "Please enter only positive numbers. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	//**************************Interest Rate:***********************************************************
	cout << endl << endl;
	cout << "2. Please provide the yearly interest rate of the loan in percentage (%):  ";
	while (!(cin>>rate) || rate < 0 )
	{
		cout << "Please enter only positive rates in Percentage. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	cout << endl << endl;
	//***************************Number of Periods:**********************************************************
	cout << "3. Please specify the number of years in the loan:  ";
	while (!(cin >> num_periods) || num_periods < 0)
	{
		cout << "Please enter only positive integers. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	
	PV = principal;
	n = num_periods ;
	r = rate/100;
	
// Computing the loan payment:

	payment = r*(1 + (1 / (pow((1+r), n) -1)))*PV;

//Computing additional informations:
	amt_paid = n * payment;
	int_paid = (n * payment) - PV;
	interest_paid= int_paid ;
	amount_paid= amt_paid;
	cout << endl << endl;

// Displaying the results:
	cout << "************************************" << endl;
	cout << setprecision(2) << fixed << endl;

	cout << left << setw(30)<< "Loan Amount: ";
	cout << right<< setw(30) <<"$" << right << setw(10) << PV <<endl;

	cout << left << setw(30) << "Annual Interest Rate:";
	cout << right << setw(30) << "%" << right << setw(10)<< rate  << endl;

	cout << left << setw(30) << "Annual Periods:";
	cout << right << setw(30) << " " << right << setw(10) << n << endl;

	cout << left << setw(30) << "Annual Payment:";
	cout << right << setw(30) << "$" << right << setw(10) << payment <<endl;

	cout << left << setw(30) << "Amount Paid Back:";
	cout << right << setw(30) << "$" << right << setw(10) << amt_paid <<  endl;

	cout << left << setw(30) << "Interest Paid:";
	cout << right << setw(30) << "$" << right << setw(10) << interest_paid << endl;

	cout << endl << endl;
	cout << "************************************" << endl;

// Terminate Program
	return 0;
}

#endif 
