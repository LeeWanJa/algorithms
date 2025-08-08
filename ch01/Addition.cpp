#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// My Answer
// string Add(string str1, string str2)
// {
// 	// TODO
// 	// 오직 문자열만 사용
// 	reverse(str1.begin(), str1.end());
// 	reverse(str2.begin(), str2.end());

// 	int idx1 = 0;
// 	int idx2 = 0;

// 	string result;
// 	char carry = '0';
// 	while(idx1 < str1.size() && idx2 < str2.size())
// 	{
// 		int temp = (str1[idx1++] - '0') + (str2[idx2++] - '0') + (carry - '0');

// 		result += to_string(temp % 10);

// 		carry = (temp / 10) + '0';
// 	}
	
// 	while(idx1 < str1.size())
// 	{
// 		int temp = (str1[idx1++] - '0') + (carry - '0');

// 		result += to_string(temp % 10);

// 		carry = (temp / 10) + '0';
// 	}

// 	while(idx2 < str2.size())
// 	{
// 		int temp = (str2[idx2++] - '0') + (carry - '0');

// 		result += to_string(temp % 10);

// 		carry = (temp / 10) + '0';		
// 	}

// 	if(carry != '0') 
// 		result += carry;

// 	reverse(result.begin(), result.end());	
// 	reverse(str1.begin(), str1.end());
// 	reverse(str2.begin(), str2.end());

// 	return result;
// }


// Answer
string Add(string str1, string str2)
{
    // An edge case (별도로 처리해야 하는 특별한 경우)
    // [안내] 코테 연습에서는 edge case도 꼼꼼하게 따져봐야 합니다.
    //        여기서는 알고리듬에 집중하기 위해 최소한으로만 고려하겠습니다.

	// 만약 str1과 str2에 저장된 문자열이 존재하지 않는다면, "0"을 반환
    if (!str1.size() && !str2.size())
        return "0"; // '0'은 char, "0"은 string

    // 구현을 편하게 하기 위해서 두 숫자의 자리수를 맞춰줍니다.
    // 더 짧은 쪽의 높은 자리에 0으로 채워줍니다.
    // str1 = "1234", str2 = "56"인 경우 str2를 "0056"으로 변경
    int N = max(str1.size(), str2.size());        
	// std::string의 함수 insert()
	// insert(size_t 위치, const string& 삽입할_문자열)
	// insert(size_t 위치, const string& 원본_문자열, size_t 시작_인덱스, size_t 개수)
	// insert(size_t 위치, size_t 반복_횟수, char 삽입할_문자)
	// insert(size_t 위치, const char* 삽입할_문자배열)
    str1.insert(0, string(N - str1.size(), '0'));
    str2.insert(0, string(N - str2.size(), '0'));    
    
    string result(N, '0'); // 정답을 만들어서 저장해나갈 공간

    int carry = 0; // 더한 결과가 10보다 클 경우 다음 자리로 넘겨줄 숫자
    for (int i = N - 1; i >= 0; i--) // 역순 주의
    {
        int n1 = str1[i] - '0'; // 문자를 정수로 변환
        int n2 = str2[i] - '0';

        int sum = n1 + n2 + carry;
        carry = sum / 10; // 다음 자리로 넘길 숫자 업데이트 

        result[i] = char(sum % 10 + '0'); // 결과 저장        
        // 디버깅용 출력
        cout << n1 << " " << n2 << " " << carry << " " << result << endl; 
    }

    // 모든 자리를 다 더한 후에는 carry만 가장 높은 자리에 추가
    if (carry > 0)
        result.insert(0, string(1, carry + '0')); 

    return result;
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
