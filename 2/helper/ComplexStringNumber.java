package helper;

public class ComplexStringNumber extends StringNumber
{
	private String sourceRealPart;
	private boolean iSign;
	private String iWholePart, iFractionalPart;
	
	public ComplexStringNumber(String source)
	{
		initFrom((this.sourceRealPart = getRealPart(source)));
		
		source = source.substring(this.sourceRealPart.length());
		
		
		if(source == null || source.length() == 0)
		{
			throw new IllegalArgumentException("Source string imaginary part cannot be empty.");
		}
		
		if(source.charAt(source.length() - 1) != 'i')
		{
			throw new IllegalArgumentException("Source string must end in 'i'");
		}
		
		source = source.substring(0, source.length() - 1);
		
		if(source == null || source.length() == 0)
		{
			throw new IllegalArgumentException("Source string imaginary part cannot be empty.");
		}
		
		int start = 0;
		this.iSign = true; // by default it is positive, overridden later if not
		if(source.charAt(0) == '+' || source.charAt(0) == '-')
		{
			if(source.length() == 1)
			{
				throw new IllegalArgumentException("Source string needs to contain a number, not just a sign.");
			}
			this.iSign = source.charAt(0) == '+';
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
					this.iWholePart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
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
			this.iWholePart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
			this.iFractionalPart = "0";
		}
		else
			this.iFractionalPart = (buildHelper.length() == 0 ? "0" : buildHelper.toString());
	}
	
	private String getRealPart(String source)
	{
		int splitIndex = source.charAt(0) == '+' || source.charAt(0) == '-' ? 1 : 0;
		String res = ((splitIndex == 1 ? String.valueOf(source.charAt(0)) : "") + source.split("[+-]")[splitIndex]);
		return res;
	}
	
	@Override
	public boolean isGreaterThan(StringNumber other)
	{
		throw new UnsupportedOperationException("complex numbers don't have this property");
	}
	
	@Override
	public boolean isLessThan(StringNumber other)
	{
		throw new UnsupportedOperationException("complex numbers don't have this property");
	}
	
	@Override
	public boolean isEqualTo(StringNumber other)
	{
		if(!(other instanceof ComplexStringNumber))
		{
			return false;
		}
		ComplexStringNumber cOther = (ComplexStringNumber) other;
		return super.isEqualTo(other) && this.iSign == cOther.iSign && this.iWholePart.equals(cOther.iWholePart) && this.iFractionalPart.equals(cOther.iFractionalPart);
	}
	
	@Override
	public String toString()
	{
		return super.toString() + (iSign ? "+" : "-") + iWholePart + (iFractionalPart.equals("0") ? "" : ("." + iFractionalPart)) + "i";
	}
}