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
				stringTokenizer = new StringTokenizer(line, " \t+*-/;=", true);	
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
				currentToken = new Token(token, Token.Type.ADD);
			}
			else if (token.equals("*"))
			{
				currentToken = new Token(token, Token.Type.MUL);
			}
			else if (token.equals("-"))
			{
				currentToken = new Token(token, Token.Type.SUB);
			}
			else if (token.equals("/"))
			{
				currentToken = new Token(token, Token.Type.DIV);
			}
			else if (token.equals("var"))
			{
				currentToken = new Token(token, Token.Type.VAR);
			}
			else if (token.equals("to"))
			{
				currentToken = new Token(token, Token.Type.TO);
			}
			else if (token.equals("do"))
			{
				currentToken = new Token(token, Token.Type.DO);
			}
			else if (token.equals("end"))
			{
				currentToken = new Token(token, Token.Type.END);
			}
			else if (token.equals("print"))
			{
				currentToken = new Token(token, Token.Type.PRINT);
			}
			else if (token.equals(";"))
			{
				currentToken = new Token(token, Token.Type.ENDSTATEMENT);
			}
			else if (token.equals("="))
			{
				currentToken = new Token(token, Token.Type.ASSIGNMENT);
			}
			else if (token.equals("for"))
			{
				currentToken = new Token(token, Token.Type.FOR);
			}
			else if (token.equals("if"))
			{
				currentToken = new Token(token, Token.Type.IF);
			}
			else if (token.matches("\\d+"))
			{
				currentToken = new Token(token, Token.Type.NUMBER);
			}
			else if (token.matches("\\w+"))
			{
				currentToken = new Token(token, Token.Type.IDENTIFIER);
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
