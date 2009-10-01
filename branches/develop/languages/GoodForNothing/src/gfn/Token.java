package gfn;

public class Token
{
	private String value;
	
	public Token(String value)
	{
		this.value = value;
	}
	
	public String getValue()
	{
		return value;
	}

	@Override
	public boolean equals(Object obj)
	{
		if (!(obj instanceof Token))
		{
			return false;
		}
		
		return value.equals(((Token) obj).value);
	}

	@Override
	public String toString()
	{
		return value;
	}
}
