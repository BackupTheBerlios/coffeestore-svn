package gfn;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Tokenizer implements Iterator<Token>
{
	BufferedReader bufferedReader;
	StringTokenizer stringTokenizer;
	Token currentToken;
	
	public Tokenizer(Reader reader)
	{
		bufferedReader = new BufferedReader(reader);
		eatLine();
	}

	private void eatLine()
	{
		try
		{
			String line = bufferedReader.readLine();
			if (line != null)
			{
				stringTokenizer = new StringTokenizer(line, "+*-/", true);	
				eatToken();
			}
		}
		catch (IOException exception) {}
	}

	private void eatToken()
	{	
		currentToken = null;
		while (currentToken == null && stringTokenizer.hasMoreElements())
		{
			String token = stringTokenizer.nextToken();
			
			if (token.equals("+"))
			{
				currentToken = ArithOpToken.add;
			}
			else if (token.equals("*"))
			{
				currentToken = ArithOpToken.mul;
			}
			else if (token.equals("-"))
			{
				currentToken = ArithOpToken.sub;
			}
			else if (token.equals("/"))
			{
				currentToken = ArithOpToken.div;
			}
		}
		
		if (currentToken == null && !stringTokenizer.hasMoreElements())
		{
			eatLine();
		}
	}

	@Override
	public boolean hasNext()
	{
		return currentToken != null;
	}

	@Override
	public Token next()
	{
		Token result = currentToken;
		eatToken();
		return result;
	}

	@Override
	public void remove()
	{

	}
}
