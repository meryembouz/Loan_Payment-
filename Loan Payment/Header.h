#ifndef Num_periods_h
#define Num_periods_h

#include<iostream>
#include<iomanip>
#include<cmath>


using namespace std;

double N() {

	double r, pmt, int_paid, amt_paid, PV;
	int n;

	double rate, principal, payment, interest_paid, amount_paid;
	int num_periods;

	// Ask user for inputs:
	cout << "What is the yearly interest rate of the loan in %? ";
	cin >> rate;
	cout << "What is the yearly payment of the loan?";
	cin >> payment;
	cout << "What is the total amount of the loan? ";
	cin >> principal;

	pmt = payment;
	r = rate / 100;
	PV = principal;

	// Computation:

	n = log(1 + (PV* r) / (pmt - PV* r)) - log(1 + r);
	num_periods= n;
	amt_paid = n * payment;
	int_paid = (n * payment) - principal;


	interest_paid = int_paid;
	amount_paid = amt_paid;

	cout << endl << endl;

	// Display:

	cout << "************************************" << endl;
	cout << setprecision(2) << fixed << endl;

	cout << endl << endl;

	cout << "Loan Amount:";
	cout << principal << endl;

	cout << "Annual Interest Rate:";
	cout << rate << endl;

	cout << "Num of Monthly Payments:";
	cout << n * 12 << endl;

	cout << "Monthly Payment:";
	cout << payment / 12 << endl;

	cout << "Annual Payment:";
	cout << payment << endl;

	cout << "Amount Paid Back:";
	cout << amt_paid << endl;

	cout << "Interest Paid:";
	cout << interest_paid << endl;

	cout << endl << endl;

	cout << "************************************" << endl;
	// Terminate Program
	
	return n;
}

#endif 

