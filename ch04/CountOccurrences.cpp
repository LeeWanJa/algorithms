#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int Count1(const vector<int>& arr, int x)
{
	//TODO: O(n)
	// 정해진 배열을 무조건 한 번씩 순회
	// int result = 0;
	// for(int i = 0; i < arr.size(); i++)
	// 	if(arr[i] == x)
	// 		result++;

	// return result;


	// Answer
	int c = 0;
	for(const auto& v : arr)
		if(v == x) c += 1;
	return c;
}

// int Count2(const vector<int>& arr, int x)
// {
// 	//TODO : O(log(n) + count)
// 	int low = 0;
// 	int high = arr.size() - 1;
// 	int mid = (low + high) / 2;

// 	// 이진 탐색 시작
// 	// while(true){
// 	// 	if(high - low < 3 && arr[mid] != x)
// 	// 		return 0;

// 	// 	if(arr[mid] > x){
// 	// 		high = mid;
// 	// 		mid = (low + high) / 2 - (low + high) % 2;
// 	// 		cout << low << " < " << mid << " < " << high << endl;
// 	// 	} else if(arr[mid] < x){
// 	// 		low = mid;
// 	// 		mid = (low + high) / 2 + (low + high) % 2;
// 	// 		cout << low << " < " << mid << " < " << high << endl;
// 	// 	} else{ // 발견시W
// 	// 		break;
// 	// 	}
// 	// }

// 	while(low <= high){
// 		if(arr[mid] > x){
// 			high = mid - 1;
// 			mid = (low + high) / 2;
// 		} else if(arr[mid] < x){
// 			low = mid + 1;
// 			mid = (low + high) / 2;
// 		} else{
// 			break;
// 		}
// 	}

// 	int result = 0;

// 	for(int i = mid + 1; i < arr.size() && arr[i] == x; i++)
// 		result++;

// 	for(int j = mid; j >= 0 && arr[j] == x; j--)
// 		result++;

// 	return result;
// }

// int Count3(const vector<int>& arr, int x)
// {
// 	//TODO: O(log(n))
// 	// x인 인덱스의 처음 부분과 마지막 부분 구하기
	
// 	int left = -1;
// 	int low = 0;
// 	int high = arr.size() - 1;
// 	int mid;
// 	// 가장작은 index 탐색
// 	while(low <= high){
// 		mid = (low + high) / 2;

// 		if(arr[mid] == x)
// 		{
// 			left = mid;

// 			// 왼쪽에 x와 동일한 값의 index가 더 있을 수 있음
// 			high = mid - 1;
// 		}
// 		else if(x > arr[mid])
// 			low = mid + 1;
// 		else
// 			high = mid - 1;
// 	}

// 	// 가장 큰 index 탐색
// 	low = 0;
// 	high = arr.size() - 1;
// 	int right = -1;
// 	while(low <= high){
// 		mid = (low + high) / 2;

// 		if(arr[mid] == x)
// 		{
// 			right = mid;

// 			// 오른쪽에 x와 동일한 값의 index가 더 있을 수 있음
// 			low = mid + 1;
// 		}
// 		else if(x > arr[mid])
// 			low = mid + 1;
// 		else
// 			high = mid - 1;
// 	}

// 	if(left == -1 && right == -1)
// 		return 0;

// 	return right - left + 1;
// }


// Answer
int BinarySearch(const vector<int>& arr, int lo, int hi, int x){
	int mid = (lo + hi) / 2;
	int result = 0;

	// // 재귀 이용
	// if(lo > hi)
	// 	return 0;

	// if(arr[mid] == x)
	// 	return mid;
	// else if(arr[mid] > x)
	// 	result = BinarySearch(arr, lo, mid - 1, x);
	// else
	// 	result = BinarySearch(arr, mid + 1, hi, x);

	
	// Loop 이용
	while(lo <= hi)
	{
		// 오버플로우의 위험성(큰수 + 큰수 -> 오버플로우 가능)
		// mid = (lo + hi) / 2;

		// 선생님의 경우
		mid = lo + (hi - lo) / 2;
		// (큰수 - 작은수) / 2 -> 더 작은 수에서 연산하기 때문에 오버플로우의 위험에서 비교적 안전

		if(arr[mid] == x)
			return mid;
		else if(arr[mid] > x)
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	return -1;
}

int Count2(const vector<int>& arr, int x)
{
	const int n = arr.size();
	int i = BinarySearch(arr, 0, n - 1, x); // 아무거나 하나 이진탐색으로 찾기, O(log n)

	if(i == -1) 
		return 0;	// 하나도 없다면 0개 반환

	// 정렬된 상태임을 이용
	int result = 0;
	for(int j = i - 1; j >= 0 && arr[j] == x; j--)
		result++;
	
	for(int k = i; k < n && arr[k] == x; k++)
		result++;

	return result;
}

int FindFirst(const vector<int>& arr, int lo, int hi, int x)
{
	int mid = lo + (hi - lo) / 2;
	int result = -1;

	if(lo > hi)
		return -1;

	if(arr[mid] == x)
	{
		result = mid;

		int temp = FindFirst(arr, lo, mid - 1, x);
		if(temp != -1)
			result = temp;
	}
	else if(arr[mid] > x)
		result = FindFirst(arr, lo, mid - 1, x);
	else
		result = FindFirst(arr, mid + 1, hi, x);

	return result;
}

int FindLast(const vector<int>& arr, int lo, int hi, int x)
{
	int mid = lo + (hi - lo) / 2;
	int result = -1;

	if(lo > hi)
		return -1;

	if(arr[mid] == x)
	{
		result = mid;

		int temp = FindLast(arr, mid + 1, hi, x);
		if(temp != -1)
			result = temp;
	}
	else if(arr[mid] > x)
		result = FindLast(arr, lo, mid - 1, x);
	else
		result = FindLast(arr, mid + 1, hi, x);

	return result;
}

int Count3(const vector<int>& arr, int x)
{
	int lo = 0;
	int hi = arr.size() - 1;
	int mid = lo + (hi - lo) / 2;

	// 왼쪽 탐색
	int left = FindFirst(arr, lo, hi, x);

	// 오른쪽 탐색
	int right = FindLast(arr, lo, hi, x);

	if(left == -1 && right == -1)
		return 0;

	return right - left + 1;
}

int main()
{
	random_device rd; // 진짜 난수 생성
	mt19937 gen(rd()); // 잔짜 난수를 씨앗값으로 전달, gen 이라는 이름의 가짜 난수 생성기 초기화

    // 크기 20의 백터 셍성
	const int n = 20;
	vector<int> my_vector(n);

	int x = 6; // target to find

	for (int r = 0; r < 100; r++)
	{
		// 임의의 숫자로 채워진 정렬된 벡터 만들기

		// 1부터 10까지의 정수를 모두 동일한 확률로 뽑아내는 규칙을 가진 규칙 객체 생성
		uniform_int_distribution<int> value_distribution(1, 10);
		// 규칙에 따라 벡터 채우기 -> generate 함수는 my_vector의 처음부터 끝까지 모든 칸을 채우는 역할
		// 각 칸을 채울 때마다, 세 번째 인자로 전달된 람다 함수를 한 번씩 호출하고, 그 반환값으로 해당 칸을 채움
		// 즉 value_distribution을 mt19937 엔진(gen)을 이용해 한 버 굴리고, 그 결과를 반환하라는 의미
		// 결론적으로 my_vector는 인덱스 0부터 19까지 각각 1 ~ 10의 랜덤한 값이 대입됨
		generate(my_vector.begin(), my_vector.end(), [&]() { return value_distribution(gen); });
		// 벡터정렬 -> my_vector의 처음부터 끝까지의 모든 요소를 오름차순으로 정렬
		sort(my_vector.begin(), my_vector.end());

		Print(my_vector);

		const int expected_count = std::count(my_vector.begin(), my_vector.end(), x);

		cout << "Expected count = " << expected_count << endl;

		// 1. O(n) brute force
		if (Count1(my_vector, x) != expected_count)
		{
			cout << "Wrong count1: " << Count1(my_vector, x) << endl;
			exit(-1);
		}

		// 2. O(log(n) + count)
		if (Count2(my_vector, x) != expected_count)
		{
			cout << "Wrong count2: " << Count2(my_vector, x) << endl;
			exit(-1);
		}

		// 3. O(log(n))
		if (Count3(my_vector, x) != expected_count)
		{
			cout << "Wrong count3: " << Count3(my_vector, x) << endl;
			exit(-1);
		}
	}

	cout << "Good!" << endl;

	return 0;
}
