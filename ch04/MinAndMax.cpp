#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Merge(vector<int>& arr, int lo, int mid, int hi)
{
    vector<int> aux;
    aux.resize(arr.size());

    int i = lo;
    int j = mid + 1;

    // 이미 정렬됐을테니..
    if(arr[mid] <= arr[j])
        return;

    // 값 옮기기
    for(int q = lo; q <= hi; q++)
    {
        aux[q] = arr[q];
    }

    for(int k = lo; k <= hi; k++)
    {
        if(i > mid)
            arr[k] = aux[j++];
        else if(j > hi)
            arr[k] = aux[i++];
        else if(aux[i] > aux[j])
            arr[k] = aux[j++];
        else
            arr[k] = aux[i++];
    }
}

int main()
{
	vector<int> arr = { 8, 2, 3, 5, 9, 1, 9, 4, 3, 7, 6, 7 };

	// TODO:
    // // Bottom Up 방법
    // int N = arr.size();

    // for (int sz = 1; sz < N; sz = sz + sz)
    //     for (int lo = 0; lo < N - sz; lo += sz + sz)
    //         Merge(arr, lo, lo + sz - 1, std::min(lo + sz + sz - 1, N - 1));

    // swap(arr[1], arr[N - 1]);


    // 다른 방법
    // 힌트: 처음에 아이디어를 내는 것이 간단하지는 않습니다. 짝수라는 가정이 힌트입니다.
    if(arr[0] > arr[1])
        swap(arr[0], arr[1]);

    // [0] = 최소, [1] = 최대
    int min_idx = 0;
    int max_idx = 1;
    for(int i = 2; i < arr.size(); i += 2)
    {
        int min_temp = arr[i] < arr[i + 1] ? i : i + 1;
        int max_temp = arr[i] > arr[i + 1] ? i : i + 1;

        if(arr[min_idx] > arr[min_temp])
            min_idx = min_temp;

        if(arr[max_idx] < arr[max_temp])
            max_idx = max_temp;
    }

    swap(arr[0], arr[min_idx]);
    swap(arr[1], arr[max_idx]);

	cout << "Min value = " << arr[0] << ", Max value = " << arr[1] << endl; // Min value = 1, Max value = 9
}