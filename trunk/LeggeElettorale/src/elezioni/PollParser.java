package elezioni;

import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import elezioni.utils.FileReader;
import elezioni.Poll;
import java.util.GregorianCalendar;

public class PollParser
{	
	private String _patternvoti;
	private String _patterninfo;
	
	public PollParser()
	{
		_patterninfo = "(\\w+);(\\d+)-(\\d+)-(\\d+);(.*)";
		_patternvoti = "(\\w+):(.*?);";
	}

	public void openPollsFile(String filename,PollDatabase pdb) throws FileNotFoundException
	{
		for(String line : new FileReader(filename))
		{
			Poll p = scanSinglePoll(line);
			pdb.getPolls().add(p);
		}
	}
	
	private Poll scanSinglePoll(String line)
	{
//		String line = "GIPIEFFE_SPA;14-03-2008;PD:33.3;IDV:2.3;SA:6.8;PDL:40.6;LEGA:5.3;MPA:0.1;UDC:7.4;DX:1.9;SOC:0.9;";
		Pattern patternInfo = Pattern.compile(_patterninfo);
		Pattern patternVoti = Pattern.compile(_patternvoti);
		Matcher matcher = patternInfo.matcher(line);
		Poll mypoll = new Poll();
		if (matcher.matches())
		{
			
			mypoll.setAuthor(matcher.group(1));
			mypoll.setDt(new GregorianCalendar(Integer.getInteger(matcher.group(4)),Integer.getInteger(matcher.group(3)),Integer.getInteger(matcher.group(2))));
			
			Matcher matchVoti = patternVoti.matcher(matcher.group(5));
			while (matchVoti.find())
			{
				HashMap<PartitoEnum,Float> map = mypoll.getPercentages();
				map.put(PartitoEnum.valueOf(matchVoti.group(1)),Float.valueOf(matchVoti.group(2)));
			}
		}
		return mypoll;
	}
}
