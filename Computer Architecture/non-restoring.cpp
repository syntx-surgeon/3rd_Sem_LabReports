// Non-Restoring Division Algorithm in C++

#include <iostream>
#include <cmath>
using namespace std;

const int SIZE = 5; // Number of bits

int dividend, divisor;
int rem[SIZE] = {0};      // Remainder
int quotient[SIZE] = {0}; // Quotient
int divisorBin[SIZE] = {0}; // Divisor binary
int divisorComp[SIZE] = {0}; // Two's complement of divisor

// Function to convert a number to binary (5-bit)
void toBinary(int num, int bin[])
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        bin[i] = num % 2;
        num /= 2;
    }
}

// Function to compute two's complement
void twosComplement(int num[], int comp[])
{
    int carry = 1;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        comp[i] = num[i] ^ 1; // Flip bits (1's complement)
        // Add 1 to get 2's complement
        if (carry)
        {
            if (comp[i] == 1)
                comp[i] = 0;
            else
            {
                comp[i] = 1;
                carry = 0;
            }
        }
    }
}

// Function to shift left
void shiftLeft()
{
    for (int i = 0; i < SIZE - 1; i++)
        rem[i] = rem[i + 1];

    rem[SIZE - 1] = quotient[0]; // Bring down first quotient bit

    for (int i = 0; i < SIZE - 1; i++)
        quotient[i] = quotient[i + 1];

    quotient[SIZE - 1] = 0; // Clear last quotient bit
}

// Function to add two binary numbers
void addBinary(int bin1[], int bin2[])
{
    int carry = 0;
    for (int i = SIZE - 1; i >= 0; i--)
    {
        int sum = bin1[i] + bin2[i] + carry;
        bin1[i] = sum % 2;
        carry = sum / 2;
    }
}

// Function to perform non-restoring division
void nonRestoringDivision()
{
    cout << "\nStepwise Execution:\n";
    for (int i = 0; i < SIZE; i++)
    {
        shiftLeft(); // Shift left
        cout << "Shift Left: ";
        for (int j = 0; j < SIZE; j++)
            cout << rem[j];
        cout << " | ";
        for (int j = 0; j < SIZE; j++)
            cout << quotient[j];
        cout << endl;

        if (rem[0] == 0) // If remainder is positive
        {
            addBinary(rem, divisorComp); // Subtract divisor
            cout << "Subtract B: ";
        }
        else // If remainder is negative
        {
            addBinary(rem, divisorBin); // Add divisor
            cout << "Add B: ";
        }
        
        for (int j = 0; j < SIZE; j++)
            cout << rem[j];
        cout << endl;

        // Set quotient bit based on remainder's sign
        quotient[SIZE - 1] = (rem[0] == 0) ? 1 : 0;
        
        cout << "Quotient Updated: ";
        for (int j = 0; j < SIZE; j++)
            cout << rem[j];
        cout << " | ";
        for (int j = 0; j < SIZE; j++)
            cout << quotient[j];
        cout << endl;
    }

    // Final adjustment if remainder is negative
    if (rem[0] == 1)
    {
        addBinary(rem, divisorBin);
        cout << "Final Adjustment (Add B): ";
        for (int j = 0; j < SIZE; j++)
            cout << rem[j];
        cout << endl;
    }
}

int main()
{
    cout << "\t***** Non-Restoring Division Algorithm *****\n";
    cout << "Enter dividend (0-31): ";
    cin >> dividend;
    cout << "Enter divisor (1-15): ";
    cin >> divisor;

    if (dividend >= 32 || divisor >= 16 || divisor == 0)
    {
        cout << "Invalid input! Numbers should be within range.\n";
        return 1;
    }

    toBinary(dividend, quotient);
    toBinary(divisor, divisorBin);
    twosComplement(divisorBin, divisorComp); // Get 2's complement of divisor

    cout << "\nBinary Representation:\n";
    cout << "Dividend: ";
    for (int i = 0; i < SIZE; i++)
        cout << quotient[i];
    cout << "\nDivisor: ";
    for (int i = 0; i < SIZE; i++)
        cout << divisorBin[i];
    cout << "\n2's Complement of Divisor: ";
    for (int i = 0; i < SIZE; i++)
        cout << divisorComp[i];
    cout << endl;

    nonRestoringDivision();

    cout << "\nFinal Results:\n";
    cout << "Quotient: ";
    for (int i = 0; i < SIZE; i++)
        cout << quotient[i];

    cout << "\nRemainder: ";
    for (int i = 0; i < SIZE; i++)
        cout << rem[i];
    cout << endl;

    cout << "\nExpected Quotient: " << dividend / divisor;
    cout << "\nExpected Remainder: " << dividend % divisor << endl;

    return 0;
}

