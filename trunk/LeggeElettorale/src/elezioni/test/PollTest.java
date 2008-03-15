package elezioni.test;

import org.junit.Test;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class PollTest
{
	public static ArrayList<String> scanSinglePollLine(String line)
	{
//		String line = "GIPIEFFE_SPA;14-03-2008;PD:33.3;IDV:2.3;SA:6.8;PDL:40.6;LEGA:5.3;MPA:0.1;UDC:7.4;DX:1.9;SOC:0.9;";
		Pattern patternInfo = Pattern.compile("(\\w+);(\\d+)-(\\d+)-(\\d+);(.*)");
		Pattern patternVoti = Pattern.compile("(\\w+):(.*?);");
		Matcher matcher = patternInfo.matcher(line);
		ArrayList<String> list = new ArrayList<String>();
		if (matcher.matches())
		{
			
			list.add(matcher.group(1));
			list.add(matcher.group(2));
			list.add(matcher.group(3));
			list.add(matcher.group(4));
			Matcher matchVoti = patternVoti.matcher(matcher.group(5));
			while (matchVoti.find())
			{
				list.add(matchVoti.group(1));
				list.add(matchVoti.group(2));
			}
		}
		return list;
	}
	
	@Test
	public void myPollTest() throws IOException
	{
		BufferedReader bf = new BufferedReader(new FileReader("varie/sondaggielettorali/sondaggi.txt"));
		String line = bf.readLine();
		while(line != null)
		{
			ArrayList<String> st = scanSinglePollLine(line);
			line = bf.readLine();
		}
	}
}
