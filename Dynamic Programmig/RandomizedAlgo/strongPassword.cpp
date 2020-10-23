/* Input : Sanjana123
Output : Suggested Password
S(anjana12G3
Sanjan1@A23
Sanj!ana123
Sa(njan12a3


Input :sanjan1@A23
Output : Your Password is Strong
*/
#include <bits/stdc++.h>    //// CPP code to suggest strong password

using namespace std;

// adding more characters to suggest strong password
string add_more_char(string str, int need)
{
	int pos = 0;

	// all 26 letters
	string low_case = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < need; i++) {
		pos = rand() % str.length();
		str.insert(pos, 1, low_case[rand() % 26]);
	}
	return str;
}

// make powerfull string
string suggester(int l, int u, int d, int s, string str)
{

	// all digits
	string num = "0123456789";

	// all lower case, uppercase and special characters
	string low_case = "abcdefghijklmnopqrstuvwxyz";
	string up_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string spl_char = "@#$_()!";

	// position at which place a character
	int pos = 0;

	// if there is no lowercase char in input string, add it
	if (l == 0) {
		// generate random integer under string length
		pos = rand() % str.length();

		// generate random integer under 26 for indexing of a to z
		str.insert(pos, 1, low_case[rand() % 26]);
	}

	// if there is no upper case char in input string, add it
	if (u == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, up_case[rand() % 26]);
	}

	// if there is no digit in input string, add it
	if (d == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, num[rand() % 10]);
	}

	// if there is no special character in input string, add it
	if (s == 0) {
		pos = rand() % str.length();
		str.insert(pos, 1, spl_char[rand() % 7]);
	}

	return str;
}

/* make_password function :This function is used to check 
strongness and if input string is not strong, it will suggest*/
void generate_password(int n, string p)
{
	// flag for lower case, upper case, special
	// characters and need of more characters
	int l = 0, u = 0, d = 0, s = 0, need = 0;

	// password suggestions.
	string suggest;

	for (int i = 0; i < n; i++) {
		// password suggestions.
		if (p[i] >= 97 && p[i] <= 122)
			l = 1;
		else if (p[i] >= 65 && p[i] <= 90)
			u = 1;
		else if (p[i] >= 48 && p[i] <= 57)
			d = 1;
		else
			s = 1;
	}

	// Check if input string is strong that
	// means all flag are active.
	if ((l + u + d + s) == 4) {
		cout << "Your Password is Strong" << endl;
		return;
	}
	else
		cout << "Suggested passowrd " << endl;

	/*suggest 10 strong strings */
	for (int i = 0; i < 10; i++) {
		suggest = suggester(l, u, d, s, p);
		need = 8 - suggest.length();
		if (need > 0)
			suggest = add_more_char(suggest, need);
		cout << suggest << endl;
	}
}

// Driver code
int main()
{
	string input_string = "geek@2018";
	srand(time(NULL));

	// srand function set Seed for rand().
	generate_password(input_string.length(), input_string);
	return 0;
}
