package elezioni;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.GregorianCalendar;
import elezioni.PartitoEnum;

public class PollDatabase
{
	private HashMap<String,ArrayList<Poll>> _authorpolls;
	private HashMap<GregorianCalendar,ArrayList<Poll>> _datepolls;
	private HashMap<PartitoEnum,ArrayList<Poll>> _partitopolls;
	
	private ArrayList<Poll> _polls;
	
	public PollDatabase()
	{
		super();
		_authorpolls = new HashMap< String,ArrayList<Poll> >();
		_datepolls = new HashMap<GregorianCalendar,ArrayList<Poll>>();
		_partitopolls = new HashMap<PartitoEnum,ArrayList<Poll>>();
		_polls = new ArrayList<Poll>();
	}
	
	private void updateAuthorPolls()
	{	
		for(Poll p: _polls)
		{
			String aut = p.getAuthor();
			if (!_authorpolls.containsKey(aut))
				_authorpolls.put(aut,new ArrayList<Poll>());
			else
			{
				ArrayList<Poll> arr = _authorpolls.get(aut);
				arr.add(p);
				_authorpolls.put(aut, arr);
			}					
		}
	}
	
	private void updateDatePolls()
	{
		for(Poll p: _polls)
		{
			GregorianCalendar cal = p.getDt();
			if (!_datepolls.containsKey(cal))
				_datepolls.put(cal,new ArrayList<Poll>());
			else
			{
				ArrayList<Poll> arr = _datepolls.get(cal);
				arr.add(p);
				_datepolls.put(cal, arr);
			}					
		}
	}
	
	private void updatePartitoPolls()
	{
//		
//		for()
//		{
//			
//		}
//		for(Poll p: _polls)
//		{
//			
//		}
	}
	
	public void updateDBMaps()
	{
		updateAuthorPolls();
		updateDatePolls();
		updatePartitoPolls();
	}
	
	public ArrayList<Poll> getPolls()
	{
		return _polls;
	}
}
