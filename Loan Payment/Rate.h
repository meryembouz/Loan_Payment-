#ifndef Rate_h
#define Rate_h

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


// In this module we will be using the Secant Method to approximate the interest rate of the loan: 

//1. Defining our first guess for the interest rate: 

double approximateR(double pmt, int n, double PV) {

	double q, q1, q2 ,k ; 
	q = log(1 + 1.00 / n)/ log(2);
	q1 = pow((1 + pmt / PV), 1 / q);
	q2 = pow(q1 - 1, q);
	return (q2 - 1);

}

//2.Defining our Objective Function f, the objective is to find the roots of the function:

double f(double pmt, int n, double PV, double r) {
	double temp;
	temp = r * (1 + (1 / (pow(1 + r, n) - 1))) - pmt/ PV ;
	return temp;

}


//3.Defining our interest rate function that will approximate r using the secant method:

double R(){

	double rate, principal, payment, interest_paid, amount_paid;
	int num_periods;
	double r, rNext;

// Ask user for inputs with data sanity check:

	cout << endl << endl;
	cout << "*****************Computing Interest Rate Using Secant Method:*******************" << endl;
	cout << endl << endl;

//***************************Loan Principal:**********************************************************
	cout << "1. Please enter the total amount of the loan:  ";
	while (!(cin >> principal) || principal < 0)
	{
		cout << "Please enter only positive numbers. Try again!:  ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	cout << endl << endl;
//***************************Loan Payment:**********************************************************
	cout << "2. Please provide the yearly payment on the loan:  ";
	while (!(cin >> payment) || payment < 0)
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
	cout << endl << endl;

// First guess of r:
	r = approximateR(payment, num_periods, principal);
//Second guess of r:
	rNext = 0.99*r;

	while (abs(f(payment, num_periods, principal, rNext)> 0.001)) {
		double temp;
		temp = rNext;
		rNext = rNext - (f(payment, num_periods, principal, rNext)*(rNext - r)) / (f(payment, num_periods, principal, rNext) - f(payment, num_periods, principal, r));
		r = temp;
	}

	interest_paid = (num_periods * payment) - principal;
	amount_paid = num_periods * payment;



// Displaying the results:

	cout << "************************************" << endl;
	cout << endl << endl;
	cout << "The objective function: " << f(payment, num_periods, principal, rNext) << endl;
	
	cout << setprecision(2) << fixed << endl;
	cout << endl << endl;

	cout << left << setw(30) << "Loan Amount: ";
	cout << right << setw(30) << "$" << right << setw(10) << principal << endl;

	cout << left << setw(30) << "Approximated Annual Rate:";
	cout << right << setw(30) << "%" << right << setw(10) << rNext*100 << endl;

	cout << left << setw(30) << "Annual Periods:";
	cout << right << setw(30) << " " << right << setw(10) << num_periods << endl;

	cout << left << setw(30) << "Annual Payment:";
	cout << right << setw(30) << "$" << right << setw(10) << payment << endl;

	cout << left << setw(30) << "Amount Paid Back:";
	cout << right << setw(30) << "$" << right << setw(10) << amount_paid << endl;

	cout << left << setw(30) << "Interest Paid:";
	cout << right << setw(30) << "$" << right << setw(10) << interest_paid << endl;

	cout << endl << endl;
	cout << "************************************" << endl;

//Terminate program

	return 0;
}


#endif 




