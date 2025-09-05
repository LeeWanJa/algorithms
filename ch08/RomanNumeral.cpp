#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// LeetCode: Roman to Integer
// https://leetcode.com/problems/roman-to-integer/description/

int RomanToInt(string s)
{
	unordered_map<char, int> m;

	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;

	int ans = 0;

	// int tail = m[s[0]];
	// ans += tail;
	// for (int i = 1; i < s.length(); i++)
	// {
	// 	// TODO:
	// 	// 키 일치는 따로 검사 x, m의 키에 해당하는 문자 입력만 들어옴을 가정
	// 	// 수의 범위 1 ~ 3999
	// 	if(tail < m[s[i]])
	// 		ans = ans - tail + (m[s[i]] - tail);
	// 	else
	// 		ans += m[s[i]];
		
	// 	tail = m[s[i]];
	// }



    // for (int i = 0; i < s.length(); i++)
    // {
	// 	if(i == 0)
	// 	{
	// 		ans += m[s[i]];
	// 		continue;
	// 	}
			
	// 	int tail = m[s[i - 1]];
	// 	int current = m[s[i]];
	// 	if(tail < current)
	// 		ans = ans - tail + (current - tail);
	// 	else
	// 		ans += current;
	// }


	// Answer
	for(int i = 0; i < s.length(); i++)
	{
		if(i < s.length() - 1 && m[s[i]] < m[s[i + 1]])
			ans -= m[s[i]];
		else
			ans += m[s[i]];
	}

	cout << s << " = " << ans << endl;

	return ans;
}

int main()
{
	RomanToInt("II");

	RomanToInt("III");

	RomanToInt("XII");

	RomanToInt("XXVII");

	RomanToInt("IV");

	RomanToInt("IX");

	RomanToInt("XL");

	RomanToInt("XC");

	RomanToInt("CD");

	RomanToInt("CM");

	RomanToInt("LVIII");

	RomanToInt("MCMXCIV");

	return 0;
}