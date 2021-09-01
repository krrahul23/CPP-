#include <bits/stdc++.h>
using namespace std;
#define pi (3.141592653589)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int MAX_N = 1e5 + 1;
const double eps = 1e-9;
//#define int long long
#define endl "\n"
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define tr(it, a) for (auto it = a.begin(); i != a.end(); it++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// void bubbleSort(int arr[], int n)
// {
//     int swapped = 1;
//     for (int i = 0; i < n && swapped; i++)
//     {
//         swapped = 0;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//                 swap(arr[j], arr[j + 1]), swapped = 1;
//         }
//     }
// }

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int mn = i;
        for (int j = i + 1; j < n; j++)
            if (arr[mn] > arr[j])
                mn = j;
        swap(arr[i], arr[mn]);
    }
}

void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = arr[i];
        int j = i;
        while (j >= 1 && arr[j - 1] > v)
            arr[j] = arr[j - 1], j--;
        arr[j] = v;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++)
        a1[i] = arr[i + l];
    for (int i = 0; i < n2; i++)
        a2[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a1[i] <= a2[j])
            arr[k++] = a1[i++];
        else
            arr[k++] = a2[j++];
    }
    while (i < n1)
        arr[k++] = a1[i++];
    while (j < n2)
        arr[k++] = a2[j++];
}
void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

void solve()
{
    int arr[] = {-1, 3, -1, -2, 5, 6};
    quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i : arr)
        cout << i << " ";
}
int32_t main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}
