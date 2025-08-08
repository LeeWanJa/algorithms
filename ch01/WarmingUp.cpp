#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	// 문제 1. 10진수 -> 2진수
	{
		int decimal = 105;
		string binary;

		//TODO:
        int i = 0;
        string temp;
        while(decimal > 0)
        {
            temp += to_string(decimal % 2);
            decimal /= 2;
        }
        
        for(auto i = temp.end() - 1; i >= temp.begin(); i--)
            binary += *i;

		cout << binary << endl; // 1101001

        // #include <algorithm>의 reverse() 사용
        // 처음부터 binary = to_string(decimal % 2) + binary 의 로직을 사용하여 뒤집기
	}

	// 문제 2. 문자열 뒤집기
	{
		string input = "Hello, World!";

		// TODO:
        // 첫 번째 방법
        // string temp = "";
        // for(auto i = input.begin(); i != input.end(); i++)
        //     temp = *i + temp;
        // input = temp;

        // 두 번째 방법
        // reverse(input.begin(), input.end());

        // 세 번째 방법
        int left = 0;
        int right = input.size() - 1;

        while(left < right)
        {
            swap(input[left++], input[right--]);
        }

		cout << input << endl; // !dlroW ,olleH
	}

	// 문제 3. 모든 자리 다 더하기
	{
		string n = "789789";

		// TODO:
        // int result = stoi(n);

        // while(result > 10)
        // {
        //     cout << result << endl;

        //     string temp = to_string(result);
        //     result = 0;

        //     for(int i = 0; i < temp.size(); i++)
        //     {
        //         char c = temp[i];
        //         result += c - '0';
        //     }
        // }

        // cout << result << endl;


        // Answer
        while(n.size() > 1)
        {
            int sum = 0;
            while(n.size() > 0)
            {
                sum += (n[0] - '0');
                // 1번 인덱스부터 끝까지 substr(0번째 인덱스 계속 소멸)
                n = n.substr(1, n.size() - 1);
            }
            cout << sum << endl;
            n = to_string(sum);
        }
        cout << n << endl;
	}

	return 0;
}
