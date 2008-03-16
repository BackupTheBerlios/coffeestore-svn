package elezioni.test;

import org.junit.Test;

import elezioni.Poll;
import elezioni.PollDatabase;
import elezioni.PollParser;
import java.io.FileNotFoundException;
import java.util.ArrayList;


public class PollTest
{	
	@Test
	public void myPollTest() throws FileNotFoundException 
	{
		PollDatabase pdb = new PollDatabase();
		PollParser prs = new PollParser();
		prs.openPollsFile("varie/sondaggielettorali/sondaggi.txt", pdb);		
		ArrayList<Poll> arr = pdb.getPolls();
		for(Poll p: arr)
		{
			System.out.println(p.getAuthor());
		}
		pdb.updateDBMaps();
	}
}
