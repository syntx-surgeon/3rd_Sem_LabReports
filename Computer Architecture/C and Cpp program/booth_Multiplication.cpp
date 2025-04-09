#include <iostream>
using namespace std;

int a = 0, b = 0, c = 0, com[5] = {1, 0, 0, 0, 0};
int anum[5] = {0}, bnum[5] = {0}, anumcp[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, pro[5] = {0}, res[5] = {0};

void binary()
{
    a = abs(a);
    b = abs(b);
    int r, r2, i;
    for (i = 0; i < 5; i++)
    {
        r = a % 2;
        a /= 2;
        r2 = b % 2;
        b /= 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;
        if (r2 == 0)
            bcomp[i] = 1;
        if (r == 0)
            acomp[i] = 1;
    }
    c = 0;
    for (i = 0; i < 5; i++)
    {
        res[i] = com[i] + bcomp[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }
    for (i = 4; i >= 0; i--)
        bcomp[i] = res[i];
}

void add(int num[])
{
    int i, c = 0;
    for (i = 0; i < 5; i++)
    {
        res[i] = pro[i] + num[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }
    for (i = 4; i >= 0; i--)
    {
        pro[i] = res[i];
        cout << pro[i];
    }
    cout << " : ";
    for (i = 4; i >= 0; i--)
        cout << anumcp[i];
}

void arshift()
{
    int temp = pro[4], temp2 = pro[0], i;
    for (i = 1; i < 5; i++)
        pro[i - 1] = pro[i];
    pro[4] = temp;
    for (i = 1; i < 5; i++)
        anumcp[i - 1] = anumcp[i];
    anumcp[4] = temp2;
    cout << "\nAR-SHIFT: ";
    for (i = 4; i >= 0; i--)
        cout << pro[i];
    cout << " : ";
    for (i = 4; i >= 0; i--)
    {
        cout << anumcp[i];
    }
}

int main()
{
    int i, q = 0;
    cout << "\t\t******BOOTH'S MULTIPLICATION ALGORITHM******\n";
    cout << "\nEnter two numbers to multiply: ";
    cout << "\nBoth must be less than 16";
    do
    {
        cout << "\nEnter A: ";
        cin >> a;
        cout << "Enter B: ";
        cin >> b;
    } while (a >= 16 || b >= 16);
    cout << "\nExpected product = " << a * b;
    binary();
    cout << "\n\nBinary Equivalents are: ";
    cout << "\nA = ";
    for (i = 4; i >= 0; i--)
        cout << anum[i];
    cout << "\nB = ";
    for (i = 4; i >= 0; i--)
        cout << bnum[i];
    cout << "\nB'+ 1 = ";
    for (i = 4; i >= 0; i--)
        cout << bcomp[i];
    cout << "\n\n";
    for (i = 0; i < 5; i++)
    {
        if (anum[i] == q)
        {
            cout << "\n-->";
            arshift();
            q = anum[i];
        }
        else if (anum[i] == 1 && q == 0)
        {
            cout << "\n-->";
            cout << "\nSUB B: ";
            add(bcomp);
            arshift();
            q = anum[i];
        }
        else
        {
            cout << "\n-->";
            cout << "\nADD B: ";
            add(bnum);
            arshift();
            q = anum[i];
        }
    }
    cout << "\nProduct: ";
    for (i = 4; i >= 0; i--)
        cout << pro[i];
    for (i = 4; i >= 0; i--)
        cout << anumcp[i];
    return 0;
}
