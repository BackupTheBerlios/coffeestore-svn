package elezioni.utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Text
{
	public String readFile(String aFileName) throws IOException
	{
		StringBuffer buffer = new StringBuffer();
		BufferedReader reader = new BufferedReader(new FileReader(aFileName));
		
		String line = null;
		while ((line = reader.readLine()) != null)
			buffer.append(line);

		return buffer.toString();
	}
}
