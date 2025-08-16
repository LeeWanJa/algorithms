#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d)
{
	vector<string> temp = arr; // 복사
    // arr의 처음부터 끝까지 공백으로 초기화
	std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의

	// TODO:
    // 아스키코드 기준 대문자 A 에서 Z 까지의 범위를 담는 count 배열
    // count[0]은 해당 자리에 아예 값이 존재하지 않는 것들을 위한 장소
    vector<int> count(k + 1); 
    // 바구니에 담기
    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i].length() >= d + 1)
            count[temp[i].at(d) - 'A' + 1]++;
        else
            count[0]++;
    }

    for(int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for(int i = temp.size() - 1; i >= 0; i--)
    {
        int idx = -1;
        if(temp[i].length() > d)
            idx = temp[i].at(d) - 'A' + 1;
        else
            idx = 0;

        arr[count[idx] - 1] = temp[i];
        count[idx]--;
    }
}

void RadixSort(vector<string>& arr)
{
	// TODO:
    // 가장 긴 문자열의 길이 저장 -> 자리수 비교의 범위
    int longest_len = 0;
    for(string str : arr)
        longest_len = longest_len < str.length() ? str.length() : longest_len;

    int k = 26;

    for(int i = longest_len - 1; i >= 0; i--)
    {
        // i는 자리수
        cout << i + 1 << "번째자리" << endl;
        Print(arr);

        CountingSort(arr, k, i);

        Print(arr);

        cout << endl;
    }
}   

int main()
{
	// CLRS 8.3-1
    /*
        CLRS 연습문제 8.3-1입니다.
        알파벳 대문자 3글자로 이뤄진 영어 단어들을 기수 정렬(radix sort)로 정렬해보세요. 
        응용 문제의 성격을 가지고 있어서 빈칸이 많습니다. 
        앞의 예제들 참고해서 완성해보세요. 
        항상 그렇지만 제 코드와 얼마나 유사한지는 전혀 중요하지 않습니다. 
        내 머리에서 떠오르는 아이디어를 구현해보는 경험이 중요합니다.
    */
	vector<string> arr = { "COW", "DOG", "SEA", "RUG",
		"ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
		"DIG", "BIG", "TEA", "NOW", "FOX" };

	Print(arr);

	RadixSort(arr);

	Print(arr);

	return 0;
}