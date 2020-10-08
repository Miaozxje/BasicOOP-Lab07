#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class MyString
{
private:
	string str;
public:
	MyString() : str() {}
	vector<MyString> Convert(string ss, vector<char> S)
	{
		vector<MyString> Result;
		this->str = ss;
		for (int i = 0; i < this->str.size(); i++)
			for (int j = 0; j < S.size(); j++)
				if (this->str[i] == S[j]) this->str[i] = ' ';
		for (int i = 0; i < this->str.size(); i++)
			if (this->str[i] == ' ' && this->str[i + 1] == ' ')
				this->str.erase(i--, 1);
		for (int i = this->str.size() - 1; i >= 0; i--)
			if (this->str[i] == ' ')
				this->str.erase(i++);
			else break;
		MyString temp;
		for (int i = 0; i < this->str.size(); i++)
			if (this->str[i] != ' ')	temp.str += this->str[i];
			else
			{
				Result.push_back(temp);
				temp.str.clear();
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
void Content(vector<char>& S)
{
	S.push_back(33); S.push_back(34); S.push_back(37); S.push_back(38); S.push_back(46); S.push_back(47); S.push_back(96);
	for (int i = 40; i <= 44; i++)	S.push_back(i);
	for (int i = 58; i <= 63; i++)	S.push_back(i);
	for (int i = 91; i <= 94; i++)	S.push_back(i);
}
void main()
{
	string temp;
	cout << "Enter input file (with extension): ";
	cin >> temp;
	ifstream MyFile(temp);
	if (MyFile.fail())
	{
		cout << "Can't find input data !!!\n";
		return;
	}
	string Input((istreambuf_iterator<char>(MyFile)), (istreambuf_iterator<char>()));
	vector<char> S;
	Content(S);
	MyString mS;
	vector<MyString> vMs = mS.Convert(Input, S);
	cout << "\nSource:\n";
	for (vector<MyString>::iterator itMS = vMs.begin(); itMS != vMs.end(); itMS++)
		cout << *itMS << " ";
	cout <<"\n\nNumber of words = " << vMs.size() << endl;
}