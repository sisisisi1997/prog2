package helper;

import java.lang.IllegalArgumentException;
import java.lang.Math;
import java.lang.StringBuffer;

/* This class implements some aspects(1) of working with numbers represented as strings.
 * One purpose for one might do this is to acquire precision greater than that of default types, in fact practically infinite precision, only limited by memory space.
 * This approach is really slow, doesn't work in a work setting, but a good example for the task.
 *
 * (1): comparing "greater than", "less than", "equal to". A whole implementation is not part if the task at hand.
 */
public class StringNumber
{
	protected boolean sign;
	protected String wholePart, fractionalPart;
	
	// TODO: strip leading zeroes in the whole part and trailing zeroes in the fractional part
	public StringNumber(String source)
	{
		if(source == null || source.length() == 0)
		{
			throw new IllegalArgumentException("Source string cannot be empty.");
		}
		
		int start = 0;
		this.sign = true; // by default it is positive, overridden later if not
		if(source.charAt(0) == '+' || source.charAt(0) == '-')
		{
			if(source.length() == 1)
			{
				throw new IllegalArgumentException("Source string needs to contain a number, not just a sign.");
			}
			this.sign = source.charAt(0) == '+';
			++ start;
		}
		
		StringBuffer buildHelper = new StringBuffer();
		boolean reachedFractional = false;
		for(int i = start; i < source.length(); ++ i)
		{
			char current = source.charAt(i);
			if(current == '.' || current == ',')
			{
				if(reachedFractional)
				{
					throw new IllegalArgumentException("Source string cannot contain more than one dot or comma.");
				}
				else
				{
					this.wholePart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
					buildHelper.delete(0, buildHelper.length());
					reachedFractional = true;
				}
			}
			else
			{
				if(current >= '0' && current <= '9')
				{
					buildHelper.append(current);
				}
				else
				{
					throw new IllegalArgumentException("Source string cannot contain non-numeric characters other than the sign, and one dot or comma.");
				}
			}
		}
		if(!reachedFractional)
		{
			this.wholePart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
			this.fractionalPart = "0";
		}
		else
			fractionalPart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
	}
	
	public StringNumber(boolean positiveSign, String wholePart, String fractionalPart)
	{
		if(StringNumber.isNumericHelper(wholePart) || !StringNumber.isNumericHelper(fractionalPart))
		{
			throw new IllegalArgumentException("Wrong input, sign must not be null and the whole and frictional parts must only contain digits.");
		}
		
		this.sign = positiveSign;
		this.wholePart = wholePart.length() == 0 ? "0" : wholePart;
		this.fractionalPart = fractionalPart.length() == 0 ? "0" : fractionalPart;
	}
	
	public boolean isGreaterThan(StringNumber other)
	{
		if(this.sign != other.sign)
		{
			return this.sign;
		}
		
		// we only reach this code if the two signs are equal
		if(this.wholePart.length() == other.wholePart.length())
		{
			for(int i = 0; i < this.wholePart.length(); ++ i)
			{
				if(this.wholePart.charAt(i) == other.wholePart.charAt(i))
					continue;
				return (this.wholePart.charAt(i) > other.wholePart.charAt(i)) ^ !this.sign;
			}
			
			// we only reach this code if the whole parts are equal
			int length = Math.min(this.fractionalPart.length(), other.fractionalPart.length());
			for(int i = 0; i < length; ++ i)
			{
				if(this.fractionalPart.charAt(i) == other.fractionalPart.charAt(i))
					continue;
				return (this.fractionalPart.charAt(i) > other.fractionalPart.charAt(i)) ^ !this.sign;
			}
			
			// we only reach this code if the fractional parts are equal up to the length of the shorter one
			return (this.fractionalPart.length() > other.fractionalPart.length()) ^ !this.sign;
		}
		else
		{
			return (this.wholePart.length() > other.wholePart.length()) ^ !this.sign;
		}
	}
	
	public boolean isLessThan(StringNumber other)
	{
		return !(this.isGreaterThan(other) || this.isEqualTo(other));
	}
	
	public boolean isEqualTo(StringNumber other)
	{
		return this.wholePart.equals(other.wholePart) && this.fractionalPart.equals(other.fractionalPart);
	}
	
	public String toString()
	{
		return (this.sign ? '+' : '-') + wholePart + (fractionalPart == "0" ? "" : "." + fractionalPart);
	}
	
	private static boolean isNumericHelper(String input)
	{
		for(int i = 0; i < input.length(); ++ i)
		{
			if(!(input.charAt(i) >= '0' && input.charAt(i) <= '9'))
			{
				return false;
			}
		}
		return true;
	}
}