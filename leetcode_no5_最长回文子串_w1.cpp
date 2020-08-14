/*--------------------------------------------------------------------------------------|
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。							|
																						|
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。				|
																						|
你可以假设 nums1 和 nums2 不会同时为空。												|
																						|
示例 1:																					|
																						|
nums1 = [1, 3]																			|
nums2 = [2]																				|
																						|
则中位数是 2.0																			|
示例 2:																					|
																						|
nums1 = [1, 2]																			|
nums2 = [3, 4]																			|
																						|
则中位数是 (2 + 3)/2 = 2.5																|
																						|
来源：力扣（LeetCode）																	|
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays						|
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。					|
---------------------------------------------------------------------------------------*/

/*	
*	执行用时：56 ms, 在所有 C++ 提交中击败了87.35%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了85.17%的用户
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> expandBorder(string &s, int i, int j)
{
	while (i >= 0 && j < s.size() && (s[i] == s[j]))
	{
		i--;
		j++;
	}

	return{ i + 1,j - 1 };
}

string longestPalindrome(string s) 
{
	int start = 0, end = 0;

	for (int i = 0; i < s.size(); i++)
	{
		pair<int, int> odd = expandBorder(s, i, i);
		pair<int, int> duo = expandBorder(s, i, i + 1);

		if (odd.second - odd.first > end - start)
		{
			start = odd.first;
			end = odd.second;
		}

		if (duo.second - duo.first > end - start)
		{
			start = duo.first;
			end = duo.second;
		}
	}

	return s.substr(start, end - start + 1);							/*	从start开始，截取end-start-1长度的字符串	*/
}

int main()
{
	string s1 = "babad";
	string s2 = "cbbd";

	string result1, result2;

	result1 = longestPalindrome(s1);
	result2 = longestPalindrome(s2);

	cout << result1 << endl << result2 << endl;
}