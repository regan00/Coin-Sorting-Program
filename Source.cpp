/* Final Exam. Sorting coins by diameter, weight, and counting amounts of each denomination.
   Author:  Ryan Regan for CSE 153, Fall 2019

*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const double pDiameter = 19.05;
const double nDiameter = 21.21;
const double dDiameter = 17.91;
const double qDiameter = 24.26;

const double pWeight = 2.5;
const double nWeight = 5.0;
const double dWeight = 2.268;
const double qWeight = 5.670;

const double tolerance = 0.02;

const double penny = .01;
const double nickel = .05;
const double dime = .10;
const double quarter = .25;

double pDiamTol = pDiameter * tolerance;
double nDiamTol = nDiameter * tolerance;
double dDiamTol = dDiameter * tolerance;
double qDiamTol = qDiameter * tolerance;

double pWeightTol = pWeight * tolerance;
double nWeightTol = nWeight * tolerance;
double dWeightTol = dWeight * tolerance;
double qWeightTol = qWeight * tolerance;

double pDTMin = pDiameter - pDiamTol;
double nDTMin = nDiameter - nDiamTol;
double dDTMin = dDiameter - dDiamTol;
double qDTMin = qDiameter - qDiamTol;

double pDTMax = pDiameter + pDiamTol;
double nDTMax = nDiameter + nDiamTol;
double dDTMax = dDiameter + dDiamTol;
double qDTMax = qDiameter + qDiamTol;

double pWTMin = pWeight - pWeightTol;
double nWTMin = nWeight - nWeightTol;
double dWTMin = dWeight - dWeightTol;
double qWTMin = qWeight - qWeightTol;

double pWTMax = pWeight + pWeightTol;
double nWTMax = nWeight + nWeightTol;
double dWTMax = dWeight + dWeightTol;
double qWTMax = qWeight + qWeightTol;


int main(int argc, char* argv[])
{

		cout << "Acceptable width of a penny is from " << pDTMin << " to " << pDTMax << endl;
		cout << "Acceptable weight of a penny is from " << pWTMin << " to " << pWTMax << endl;
		cout << "\n";
		cout << "Acceptable width of a nickel is from " << nDTMin << " to " << nDTMax << endl;
		cout << "Acceptable weight of a nickel is from " << nWTMin << " to " << nWTMax << endl;
		cout << "\n";
		cout << "Acceptable width of a dime is from " << dDTMin << " to " << dDTMax << endl;
		cout << "Acceptable weight of a dime is from " << dWTMin << " to " << dWTMax << endl;
		cout << "\n";
		cout << "Acceptable width of a quarter is from " << qDTMin << " to " << qDTMax << endl;
		cout << "Acceptable weight of a quarter is from " << qWTMin << " to " << qWTMax << endl;
		cout << "\n";


		vector<double> vecX, vecY;
		double x, y;
		
		vector<int> pAmount;
		vector<int> nAmount;
		vector<int> dAmount;
		vector<int> qAmount;
		vector<int> iAmount;
		
		double pWorth;
		double nWorth;
		double dWorth;
		double qWorth;
		
		int pA;
		int nA;
		int dA;
		int qA;
		int iA;

		ifstream inputFile("coinstest.txt");

		while (inputFile >> x >> y)
		{
			vecX.push_back(x);
			vecY.push_back(y);
		}

		for (int i = 0; i < vecX.size(); i++)
		{
			if ((vecX[i] >= pDTMin && vecX[i] <= pDTMax) && (vecY[i] >= pWTMin && vecY[i] <= pWTMax))
			{
				pAmount.push_back(i);
			}
			else if ((vecX[i] >= nDTMin && vecX[i] <= nDTMax) && (vecY[i] >= nWTMin && vecY[i] <= nWTMax))
			{
				nAmount.push_back(i);
			}
			else if ((vecX[i] >= dDTMin && vecX[i] <= dDTMax) && (vecY[i] >= dWTMin && vecY[i] <= dWTMax))
			{
				dAmount.push_back(i);
			}
			else if ((vecX[i] >= qDTMin && vecX[i] <= qDTMax) && (vecY[i] >= qWTMin && vecY[i] <= qWTMax))
			{
				qAmount.push_back(i);
			}
			else if ((vecX[i] < pDTMin || vecX[i] > qDTMax) && (vecY[i] < pWTMin || vecY[i] > qWTMax))
			{
				iAmount.push_back(i);
			}
				 
		}

		pA = pAmount.size();
		nA = nAmount.size();
		dA = dAmount.size();
		qA = qAmount.size();
		iA = iAmount.size();	

		pWorth = pA * penny;
		nWorth = nA * nickel;
		dWorth = dA * dime;
		qWorth = qA * quarter;

		cout << "Number of pennies counted: " << pA << " worth: " << pWorth << endl;
		cout << "Number of nickels counted: " << nA << " worth: " << nWorth << endl;
		cout << "Number of dimes counted: " << dA << " worth: " << dWorth << endl;
		cout << "Number of quarters counted: " << qA << " worth: " << qWorth << endl;
		cout << "Number of invalid coins counted: " << iA << endl;
		
		return 0;
}



		
		
