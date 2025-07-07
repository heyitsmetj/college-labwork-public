#include <iostream>
#include <string>

using namespace std;

class String
{
    string string1;
    string string2;
    
    public:
        String(string str1, string str2)
        {
            string1 = str1;
            string2 = str2;
        }
        
        void strlength()
        {
            int length = 0;
            
            cout << "\nLength of String:" << endl;
            
            for(char ch : string1)
            {
                length++;
            }
            
            cout << "\nLength of string(manual): " << length;
            cout << "\nLength of string(built-in): " << string1.length() << endl;
        }
        
        void concatenate()
        {
            cout << "\nString Concatenation:" << endl;
            
            cout << "\nString 1: " << string1 << endl;
            cout << "String 2: " << string2 << endl;
            cout << "Concatenated string: " << string1 + string2 << endl;
        }
        
        void reversestr()
        {
                cout << "\nReversing a String:" << endl;
                
                cout << "\nString: " << string1 << endl;
                cout << "Reversed String: ";
                for(int i = string1.length(); i >= 0; --i)
                {
                cout << string1[i];
                }
                
                cout << endl;
        }
        
        void strcomp()
        {
            cout << "\nString Comparison:" << endl;
            
            cout << "\nString 1: " << string1 << endl;
            cout << "String 2: " << string2 << endl;
            
            if(string1.compare(string2) == 0)
            {
                cout << "Strings " << string1 << " and " << string2 << " are Equal." << endl;        
            }
            else
            {
                cout << "Strings " << string1 << " and " << string2 << " are NOT Equal." << endl;  
            }
        }
    
};

int main() 
{
    string str1, str2;
    
    cout << "\nEnter string 1: ";
    cin >> str1;
    
    cout << "\nEnter string 2: ";
    cin >> str2;
    
    String s1(str1, str2);
    
    s1.strlength();
    s1.concatenate();
    s1.reversestr();
    s1.strcomp();
    
    
    return 0;
}