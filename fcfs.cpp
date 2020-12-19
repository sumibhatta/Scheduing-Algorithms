#include <iostream>
#include <stack>
using namespace std;

int n;
char pname[20][20], c[20][20];

int *At = new int(n);  //Dynamically Allocated Arrival time
int *But = new int(n); //BUrst time
int tBT = 0;           //Total Burst Time
int *CT = new int(n);  //Temporary Completion time
int *aCT = new int(n); //Actual Completion Time
int *TAT = new int(n); //Turn Around Time
int *WT = new int(n);  //Waiting Time
stack<int> rCT;        //Stack for completion time later stored in aCT

/*Functions initilization*/
void GetData();
void sortData();
void valueofCT();
void calculateWT();
void calculateTAT();

/*Get Data From User*/
void GetData()
{

    int i;
    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Process name: ");
        scanf("%s", &pname[i]);
        printf("Arrival Time for Process %s = ", pname[i]);
        scanf("%d", &At[i]);
        printf("BurstTime for Process %s = ", pname[i]);
        scanf("%d", &But[i]);
    }
}

/*Sort the data using Insertion Sort*/
void sortData()
{

    int i, key, key1, j;
    for (i = 1; i < n; i++)
    {
        key = At[i];
        key1 = But[i];
        j = i - 1;

        while (j >= 0 && At[j] > key)
        {
            At[j + 1] = At[j];
            But[j + 1] = But[j];
            j = j - 1;
        }
        At[j + 1] = key;
        But[j + 1] = key1;
    }
}

/*Calculate value of CT*/
void valueofCT()
{
    /*Calculate total BT*/
    for (int i = 0; i < n; i++)
    {
        tBT = tBT + But[i];
    }
    tBT = tBT + 1;

    /*Calculate CT*/
    int y = 0;
    CT[0] = 0;
    do
    {
        if (CT[y] < At[y])
        {

            do
            {
                CT[y] += 1;
            } while (CT[y] < At[y]);
            CT[y + 1] = CT[y] + But[y];
            rCT.push(CT[y + 1]);
        }
        else
        {
            CT[y + 1] = CT[y] + But[y];
            rCT.push(CT[y + 1]);
        }
        y++;
    } while (CT[y] < tBT);

    int z = n - 1;

    while (!rCT.empty())
    {
        aCT[z] = rCT.top();
        rCT.pop();
        z--;
    }
}

/*Calculate TAT and avg TAT*/
void calculateTAT()
{
    float tTAT = 0.00;
    for (int i = 0; i < n; i++)
    {
        TAT[i] = aCT[i] - At[i];
        tTAT = tTAT + TAT[i];
    }
    cout << endl<< "Total TAT = " << tTAT / n;
}

/*Calculate WT and avg WT*/
void calculateWT()
{
    float tWT = 0.00;
    for (int i = 0; i < n; i++)
    {
        WT[i] = TAT[i] - But[i];
        tWT = tWT + WT[i];
    }
    cout << endl << "Total WT = " << tWT / n << endl;
}

/*Main Function*/
int main()
{
    GetData();
    sortData();
    valueofCT();
    calculateTAT();
    calculateWT();
    return 0;
}
