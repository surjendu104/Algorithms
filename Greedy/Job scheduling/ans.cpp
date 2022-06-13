#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define N 100

using namespace std;

typedef struct job
{
    char job_id[N];
    int deadline;
    int profit;
} job;
int minValue(int x, int y)
{
    return (x < y) ? x : y;
}

void jobSequenceWithDeadline(job a[], int n)
{
    int k;
    int countJobs = 0, jobProfit = 0;
    job temp;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j + 1].profit > a[j].profit)
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i].profit<<'\t';
    // }

    int maxDeadline = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i].deadline > maxDeadline)
        {
            maxDeadline = a[i].deadline;
        }
    }
    cout << "Maximum Deadline: " << maxDeadline << endl;

    int ans[N];
    for (int i = 1; i <= maxDeadline; i++)
    {
        ans[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        k = minValue(maxDeadline, a[i - 1].deadline);
        while (k >= 1)
        {
            if (ans[k] == -1)
            {
                ans[k] = i - 1;
                countJobs++;
                break;
            }
            k--;
        }
        if (countJobs == maxDeadline)
        {
            break;
        }
    }
    // for (int i = 0; i < maxDeadline; i++)
    // {
    //     cout<<ans[i]<<'\t';
    // }

    cout << "Required jobs:" << countJobs << endl;
    for (int i = 1; i <= maxDeadline; i++)
    {
        cout << a[ans[i]].job_id;
        if (i < maxDeadline)
        {
            cout << "-->";
        }
    }
    cout << '\n';

    for (int i = 1; i <= maxDeadline; i++)
    {
        jobProfit = jobProfit + a[ans[i]].profit;
    }

    cout << "Maximum Profit: " << jobProfit << endl;
}

int main()
{
    /*Your code goes here*/
    int n = 7;
    job a[7] = {
        {"j1", 4, 70},
        {"j2", 2, 60},
        {"j3", 4, 50},
        {"j4", 3, 40},
        {"j5", 1, 30},
        {"j6", 4, 20},
        {"j7", 6, 10},
    };

    jobSequenceWithDeadline(a, n);

    return 0;
}