#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
	vector<string> str = { "apple", "banana", "key", "cat", "dog", "orange", "banana" };
	auto find_str = "banana";
	auto sd = remove_if(str.begin(), str.end(), [find_str](string n) { return n == find_str; });
	// str.erase(sd, str.end());
 
	for (auto iter = str.begin(); iter != str.end(); ++iter)
	{
		cout << "删除之后："<<*iter<<" ";
	}
	cout << endl;
	str.erase(remove_if(str.begin(), str.end(),
		[find_str](string n) { return n == find_str; }),
		str.end());
	vector<string>::iterator iter;
	for (iter = str.begin(); iter != str.end(); ++iter)
	{
		cout << "删除之后："<<*iter<<" ";
	}
	return 0;
}
