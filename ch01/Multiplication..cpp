#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

// Answer
string Add(string str1, string str2)
{
    if (!str1.size() && !str2.size())
        return "0"; // '0'은 char, "0"은 string

    int N = max(str1.size(), str2.size());        
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

    if (carry > 0)
        result.insert(0, string(1, carry + '0')); 

    return result;
}

// string Multiply(string str1, string str2)
// {
// 	// TODO:
// 	// string result(str1.length() + str2.length(), '0');

// 	// int carry = 0;
// 	// int idx = (str1.length() + str2.length());
// 	// for(int i = str1.length() - 1; i >= 0; i--)
// 	// {
// 	// 	int tmp1 = str1[i] - '0';

// 	// 	idx--;
// 	// 	int idx_tmp = idx;
// 	// 	for(int j = str2.length() - 1; j >= 0; j--)
// 	// 	{
// 	// 		int current = result[idx_tmp] - '0'; // 값이 들어갈 자리의 값
// 	// 		int tmp2 = str2[j] - '0';

// 	// 		int mul = tmp1 * tmp2 + current + carry;
// 	// 		result[idx_tmp] = (mul % 10) + '0';
// 	// 		carry = mul / 10;
			
// 	// 		idx_tmp--;
// 	// 	}

// 	// 	result[idx_tmp] = carry + '0';
// 	// 	carry = 0;
// 	// }

// 	// // 0제거
// 	// int i = 0;
// 	// for(; i < result.length(); i++)
// 	// 	if(result[i] != '0') break;
	
// 	// result = result.substr(i, result.length());

// 	// return result;


// 	// 부분 곱 + 부분 합
// 	// 부분 곱의 각 결과를 string 배열에 저장 -> 이후 중첩하여 result에 Add() 함수를 이용해 값 저장
	
// 	// An edge case (일반적이지 않을 경우)
// 	if(!str1.size() || !str2.size())
// 		return "0";

// 	vector<string> strArr;

// 	for(int i = str1.length() - 1; i >= 0; i--)
// 	{
// 		int int1 = str1[i] - '0';

// 		int carry = 0;
// 		string temp = "";
// 		for(int j = str2.length() - 1; j >= 0; j--)
// 		{
// 			int int2 = str2[j] - '0';

// 			int mul = int1 * int2 + carry;
// 			char c = mul % 10 + '0';
// 			carry = mul / 10;

// 			temp = c + temp;
// 		}
		
// 		if(carry != 0)
// 		{
// 			char c = carry + '0';
// 			temp = c + temp;
// 		}

// 		for(int j = 0; j < str1.length() - i - 1; j++)
// 			temp += '0';

// 		strArr.push_back(temp);
// 	}

// 	string result(str1.length() + str2.length(), '0');

// 	int i = 0;
// 	for(; i < str1.length(); i++)
// 		result = Add(result, strArr[i]);

// 	i = 0;
// 	while(result[i] == '0') i++;
// 	result = result.substr(i, result.length());

// 	return result;
// }

// Answer
string Multiply(string str1, string str2)
{
    // An edge case (일반적이지 않은 경우)
    if (!str1.size() || !str2.size())
        return "0";

    int N = max(str1.size(), str2.size());
    str1 = string(N - str1.size(), '0') + str1;
    str2 = string(N - str2.size(), '0') + str2;

    string result(2 * N, '0');

    for (int i = N - 1; i >= 0; i--) // 역순
    {
        int carry = 0;
        int n1 = str1[i] - '0';
        int k = N + i; // 결과를 저장할 위치의 인덱스
        for (int j = N - 1; j >= 0; j--) // 역순
        {
            // TODO:
			int n2 = str2[j] - '0';
			int sum = n1 * n2 + int(result[k] - '0') + carry;
			carry = sum / 10;
			result[k] = char(sum % 10 + '0'); 
            k -= 1; // <- k가 하나씩 감소

            // Trace (변수에 저장된 값들의 변화를 추적)
            cout << n1 << " " << n2 << " " << carry << " " << result << endl;
        }
        // 마지막에는 carry만
        // TODO:
		result[k] = char(carry + '0');
    }

    // 불필요한 '0' 제거
    // TODO:
	int i = 0;
	while (result[i] == '0') i += 1;
	result = result.substr(i, 2 * N - i);

    return result;
}


int main()
{
	vector<vector<string>> tests = {
		{"12", "34", std::to_string(12 * 34)},
		{"123", "45", std::to_string(123 * 45)},
		{"5555", "55", std::to_string(5555 * 55)},
		{"5555", "5555", std::to_string(5555 * 5555)},
		{"98234712354214154", "171454654654655", "16842798681791158832220782986870"}
		// , {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "16842798681791114273590624445460185389471221520083884298838480662480"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];
		const string str2 = t[1];
		const string expected = t[2];

		cout << str1 << " * " << str2 << " = " << expected << endl;

		const string result = Multiply(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK";
		else {
			cout << "Not OK";
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
