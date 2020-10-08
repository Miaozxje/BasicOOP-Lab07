#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MyString
{
private:
	string str = "";
public:
	MyString(string S) : str(S) {}
	MyString(const char S[1000]) : str(S) {}
	MyString operator+(MyString S)
	{
		this->str += S.str;
		return *this;
	}
	friend MyString operator+(const string S, MyString B)
	{
		MyString A(S);
		MyString Result = A + B;
		return Result;
	}
	vector<MyString> Split(vector<char> S, bool empty)
	{
		vector<MyString> Result;
		for (int i = 0; i < this->str.size(); i++)
			for (int j = 0; j < S.size(); j++)
				if (this->str[i] == S[j]) this->str[i] = ' ';
		if (empty)
		{
			for (int i = 0; i < this->str.size(); i++)
				if (this->str[i] == ' ' && this->str[i + 1] == ' ')
					this->str.erase(i--, 1);
			for (int i = this->str.size() - 1; i >= 0; i--)
				if (this->str[i] == ' ')
					this->str.erase(i++);
				else break;
		}
		MyString temp("");
		for (int i = 0; i < this->str.size(); i++)
		{
			if (this->str[i] != ' ')	temp.str += this->str[i];
			else
			{
				Result.push_back(temp);
				temp.str = "";
			}
		}
		Result.push_back(temp);
		return Result;
	}
	friend ostream& operator<<(ostream& os, const MyString& S)
	{
		os << S.str;
		return os;
	}
};
void main()
{
	MyString ms1("abcdsf");
	MyString ms2 = "____" + ms1;
	MyString ms3 = ms1 + ms2;
	cout << "ms1 = " << ms1 << endl;
	cout << "ms2 = " << ms2 << endl;
	cout << "ms3 = " << ms3 << endl << endl;
	MyString ms = "a,b,c;d.r;.,h;e,w__u,t.f;j_..";
	vector<char> arrChar;
	arrChar.push_back(',');
	arrChar.push_back('.');
	arrChar.push_back(';');
	vector<MyString> vMs = ms.Split(arrChar, false);
	cout << "Split:" << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); itMS++)
		cout << *itMS << " ";
	cout << endl << "Size = " << vMs.size() << endl << endl;
	vMs = ms.Split(arrChar, true);
	cout << "Split co loai bo empty:" << endl;
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); itMS++)
		cout << *itMS << " ";
	cout << endl << "Size = " << vMs.size() << endl << endl;
}