#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class clsString
{
	string _Value;
	static bool IsVoel(char C1)
	{
		C1 = tolower(C1);
		return((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
	}

	stack <string> _Undo;
	stack <string> _Redo;

public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
		_Undo.push(Value);
	}
	void SetString(string Value)
	{
		_Value = Value;
		_Undo.push(Value);
	}
	string GetString()
	{
		return _Value;
	}
	__declspec(property(get = GetString, put = SetString))  string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}

	static short Length(string S1)
	{
		return S1.length();
	};
	short Length()
	{
		return _Value.length();
	};

	static string  UpperFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}
	void  UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string  LowerFirstLetterOfEachWord(string S1)
	{

		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ' ? true : false);

		}

		return S1;
	}
	void  LowerFirstLetterOfEachWord()
	{


		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string AllCabitalLeter(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string AllCabitalLeter()
	{
		return AllCabitalLeter(_Value);
	}

	static string AllSmallLetter(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string AllSmallLetter()
	{
		return AllSmallLetter(_Value);
	}

	static string InvertingAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				S1[i] = tolower(S1[i]);
			else
				S1[i] = toupper(S1[i]);

		}
		return S1;

	}
	string InvertingAllString()
	{
		return InvertingAllString(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}


	static int CountCapitalLetter(string S1)
	{
		int Sum = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Sum++;
		}
		return Sum;
	}
	int CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static int CountSmallLetter(string S1)
	{
		int Sum = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Sum++;
		}
		return Sum;
	}
	int CountSmallLetter()
	{
		return CountSmallLetter(_Value);
	}

	static int CountSpecificLetter(string S1, char C1, bool MatchCase = true)
	{
		int Sum = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == C1)
					Sum++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(C1))
					Sum++;

			}
		}
		return Sum;
	}
	int CountSpecificLetter(char C1, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, C1, MatchCase);
	}

	static int CountVowel(string S1)
	{
		int Sum = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (IsVoel(S1[i]))
				Sum++;
		}
		return Sum;
	}
	int CountVowel()
	{
		return CountVowel(_Value);
	}

	static void PrintEachWordAlone(string S1)
	{
		string delim = " ";
		int Pos = 0;
		string Stword;
		while ((Pos = S1.find(delim)) != std::string::npos)
		{
			Stword = S1.substr(0, Pos);
			if (Stword != "")
			{
				cout << Stword << endl;
			}
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "")
			cout << S1 << endl;
	}
	void PrintEachWordAlone()
	{
		PrintEachWordAlone(_Value);
	}

	static short CountNumberOfWord(string S1)
	{
		string delim = " ";
		int Pos = 0;
		string Stword;
		short Sum = 0;
		while ((Pos = S1.find(delim)) != std::string::npos)
		{
			Stword = S1.substr(0, Pos);
			if (Stword != "")
			{
				Sum++;
			}
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "")
		{
			Sum++;
		}
		return Sum;
	}
	short CountNumberOfWord()
	{
		return CountNumberOfWord(_Value);
	}

	static vector <string> Split(string S1, string Delim)
	{
		vector <string>	vSplit;

		int Pos = 0;
		string Stword;
		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Stword = S1.substr(0, Pos);
			if (Stword != "")
			{
				vSplit.push_back(Stword);
			}
			S1.erase(0, Pos + Delim.length());
		}
		if (S1 != "")
			vSplit.push_back(S1);
		return vSplit;
	}
	vector <string> Split(string Delim = " ")
	{
		return Split(_Value,Delim);
	}

	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}


	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && S1[i] != '\t')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	string TrimLeft()
	{
		return TrimLeft(_Value);
	}
	
	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ' && S1[i] != '\t')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}
	
	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	string Trim()
	{
		return Trim(_Value);
	}

	static string JoinString(string Sentance, string Delmiter)
	{
		vector<string> vJoin = Split(Sentance, " ");
		string S1;
		for (string& S : vJoin)
		{
			S1 = S1 + S + Delmiter;
		}
		return S1.substr(0, S1.length() - Delmiter.length());
	}
	string JoinString(string Delmiter)
	{
		return JoinString(_Value, Delmiter);
	}

	static string ReplaceWordInstring(string FullSantance, string OldWord, string NewWord, bool MatchCase = true)
	{
		vector <string> SplitString = Split(FullSantance," ");
		string S1;
		for (string& S : SplitString)
		{
			if (MatchCase)
			{
				if (S == OldWord)
				{
					S1 += NewWord + " ";
				}
				else
				{
					S1 += S + " ";
				}
			}
			else {
				if (AllSmallLetter(S) == AllSmallLetter(OldWord))
				{
					S1 += NewWord + " ";
				}
				else
				{
					S1 += S + " ";
				}

			}
		}
		return S1.substr(0, S1.length() - 1);
	}
	string ReplaceWordInstring(string OldWord, string NewWord, bool MatchCase = true)
	{
		return ReplaceWordInstring(_Value, OldWord, NewWord, MatchCase);
	}

	static string RemovePunctuations(string S1)
	{

		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;

	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}


};




