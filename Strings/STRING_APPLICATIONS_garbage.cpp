// C++ program to demonstrate Character Array 
// and String 
#include<iostream> 
#include<string>// for string class 
using namespace std; 
int main() 
{ 
    // Size has to be predefined in character array 
    char str[80] = "GeeksforGeeks"; 
  
    // Size not predefined in string 
    string s("GeeksforGeeks"); 
  
    // Printing character array and string 
    cout << str << endl; 
    cout << s << endl; 
  
    return 0; 
} /*
Output:




GeeksforGeeks
GeeksforGeeks
Some useful String Functions

compare(string_to_compare ) :- It is used to compare two strings. It returns the difference of second string and first string in integer.
*/
// C++ program to demonstrate use of compare() 
#include<iostream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string str("GeeksforGeeks"); 
    string str1("GeeksforGeeks"); 
  
    // Comparing strings using compare() 
    if ( str.compare(str1) == 0 ) 
        cout << "Strings are equal"; 
    else 
        cout << "Strings are unequal"; 
    return 0; 
} /*
Output :

Strings are equal
find(“string”): Searches the string for the first occurrence of the substring specified in arguments. It returns the position of the first occurrence of substring.
find_first_of(“string”): Searches the string for the first character that matches any of the characters specified in its arguments. It returns the position of the first character that matches.
find_last_of(“string”): Searches the string for the last character that matches any of the characters specified in its arguments. It returns the position of the last character that matches.
rfind(“string”): Searches the string for the last occurrence of the substring specified in arguments. It returns the position of the last occurrence of substringfilter_none
*/
// C++ program to demonstrate working of find(), 
// rfind(),find_first_of() and find_last_of() 
#include<iostream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string str("The Geeks for Geeks"); 
  
    // find() returns position to first 
    // occurrence of substring "Geeks" 
    // Prints 4 
    cout << "First occurrence of \"Geeks\" starts from : "; 
    cout << str.find("Geeks") << endl; 
  
    // Prints position of first occurrence of 
    // any character of "reef" (Prints 2) 
    cout << "First occurrence of character from \"reef\" is at : "; 
    cout << str.find_first_of("reef") << endl; 
  
    // Prints position of last occurrence of 
    // any character of "reef" (Prints 16) 
    cout << "Last occurrence of character from \"reef\" is at : "; 
    cout << str.find_last_of("reef") << endl; 
  
    // rfind() returns position to last 
    // occurrence of substring "Geeks" 
    // Prints 14 
    cout << "Last occurrence of \"Geeks\" starts from : "; 
    cout << str.rfind("Geeks") << endl; 
  
    return 0; 
  
} /*
Output:

First occurrence of "Geeks" starts from : 4
First occurrence of character from "reef" is at : 2
Last occurrence of character from "reef" is at : 16
Last occurrence of "Geeks" starts from : 14
insert(pos_to_begin,string_to_insert): This function inserts the given substring in the string. It takes two arguments, first the position from which you want to insert the substring and second the substring.
*/
// C++ program to demonstrate working of insert() 
#include<iostream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string str("Geeksfor"); 
  
    // Printing the original string 
    cout << str << endl; 
  
    // Inserting "Geeks" at 8th index position 
    str.insert(8,"Geeks"); 
  
    // Printing the modified string 
    // Prints "GeeksforGeeks" 
    cout << str << endl; 
  
    return 0; 
} /*
Output:

Geeksfor
GeeksforGeeks
clear(): This function clears all the characters from the string. The string becomes empty (length becomes 0) after this operation.
empty(): Tests whether the string is empty. This function return a Boolean value.
*/
// C++ program to demonstrate working of clear() 
// and empty() 
#include<iostream> 
#include<string> 
using namespace std; 
int main() 
{ 
    string str("GeeksforGeeks"); 
  
    // clearing string 
    str.clear(); 
  
    // Checking if string is empty 
    (str.empty()==1)? 
         cout << "String is empty" << endl: 
         cout << "String is not empty" << endl; 
  
    return 0; 
  
} /*
Output:

String is empty
*/
