/* 
 * Author - John Chong
 */ 

#include <iostream>

using namespace std;

int main() {

    double loan = -1; 
    double yearInterest = -1; 
    double monthlyPay = -1; 

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); 

    // Get loan amount
    while (loan < 0) {
        cout << "\nLoan Amount: ";
        cin >> loan;
    }

    // Get yealry interest rate
    while (yearInterest < 0) {
        cout << "Interest Amount: ";
        cin >> yearInterest;
    }
    
    // caluclates monlthy interest and how much interest is each month
    double monthInterest = (yearInterest / 12) / 100;  
    double highestInterestAmount = loan * monthInterest; 

    // Gets monthly payments
    while (monthlyPay <= highestInterestAmount) {
        cout << "Monthly Payments: ";
        cin >> monthlyPay;
    } 

    cout << endl; 

    cout << "**********************************************************\n"
         << "\tAmortization Table\n"
         << "**********************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // Variables required to calculate
    int currentMonth = 0; 
    double rate = monthInterest * 100;
    double interestAmount;
    double principle; 
    double totalInterest;
    
    // Repeats until loan is all payed off
    while (loan > 0) { 

        // Calculates interest, principle, months it takes to pay off
        if(currentMonth > 0) {
            interestAmount = loan * monthInterest;
            principle = monthlyPay - interestAmount; 
            loan -= principle; 
            totalInterest += interestAmount; 

            // If loan is less than monthly pay
            if (loan < 0) {
                principle += loan;
                monthlyPay = principle + interestAmount;
                loan = 0;
            }

            cout << currentMonth << "\t$" << loan 
                 << "\t\t$" << monthlyPay << "\t" << rate
                 << "\t$" << interestAmount << "\t\t$" << principle;
            cout << endl; 
        }

        else if (currentMonth == 0) { 
            cout << currentMonth << "\t$" << loan 
                 << "\t" << "\tN/A\tN/A\tN/A\t\tN/A\n";
        }

        currentMonth++; 
    }
    
    cout << "**********************************************************\n\n"
         << "It takes " << --currentMonth << " months to pay off the loan.\n"
         << "Total interest paid is: $" << totalInterest
         << endl;

    return 0; 

}