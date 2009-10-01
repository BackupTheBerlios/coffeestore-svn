package gfn.test;

import org.junit.Test;
import static org.junit.Assert.*;
import gfn.Token;

public class TestToken
{
	@Test
	public void testEqualsWithDifferentType()
	{
		Token token = new Token("x");
		
		assertFalse(token.equals("x"));
	}
	
	@Test
	public void testEqualsWithDifferentValue()
	{
		Token x = new Token("x");
		Token y = new Token("y");
		
		assertFalse(x.equals(y));
	}

	@Test
	public void testEquals()
	{
		Token x1 = new Token("x");
		Token x2 = new Token("x");
		
		assertTrue(x1.equals(x2));
	}
}
