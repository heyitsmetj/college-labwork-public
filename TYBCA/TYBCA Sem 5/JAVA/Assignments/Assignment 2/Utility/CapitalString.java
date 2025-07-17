package Utility;

public class CapitalString 
{
    public String convert(String mystr)
    {
		String newstr = "";
		newstr = mystr.substring(0,1).toUpperCase() + mystr.substring(1); 
		return newstr;
    }
}
