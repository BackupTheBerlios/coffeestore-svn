package gfn.test;

import org.junit.Test;
import static org.junit.Assert.*;
import gfn.Token;

public class TestToken
{
	@Test
	public void testEqualsWithDifferentType()
	{
		Token token = new Token("x", Token.Type.IDENTIFIER);
		
		assertFalse(token.equals("x"));
	}
	
	@Test
	public void testEqualsWithDifferentValue()
	{
		Token x = new Token("x", Token.Type.IDENTIFIER);
		Token y = new Token("y", Token.Type.IDENTIFIER);
		
		assertFalse(x.equals(y));
	}

	@Test
	public void testEquals()
	{
		Token x1 = new Token("x", Token.Type.IDENTIFIER);
		Token x2 = new Token("x", Token.Type.IDENTIFIER);
		
		assertTrue(x1.equals(x2));
	}
	
	@Test
	public void testIntegerAndStringTokenAreNotEqual()
	{
		Token x1 = new Token("12", Token.Type.IDENTIFIER);
		Token x2 = new Token("12", Token.Type.STRING);
		
		assertFalse(x1.equals(x2));
	}
}
