package elezioni.test;

import org.junit.Test;

import elezioni.Poll;
import elezioni.PollDatabase;
import elezioni.PollParser;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;
import java.util.Map;


public class PollTest
{	
	@Test
	public void myPollTest() throws FileNotFoundException 
	{
		PollDatabase pdb = new PollDatabase();
		PollParser prs = new PollParser();
		prs.openPollsFile("varie/sondaggielettorali/sondaggi.txt", pdb);		
		pdb.updateDBMaps();
		HashMap<String,ArrayList<Poll>> author = pdb.getAuthorpolls();
		Set<Map.Entry<String,ArrayList<Poll>>> s = author.entrySet();
		for(Map.Entry<String,ArrayList<Poll>> ent: s)
		{
			System.out.println(ent.getKey());
			ArrayList<Poll> arr = ent.getValue();
			for(Poll p : arr)
			{
				System.out.println(p.getDt().toString());
			}
		}
	}
}
