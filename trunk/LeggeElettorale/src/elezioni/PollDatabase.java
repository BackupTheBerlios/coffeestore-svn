package elezioni;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.GregorianCalendar;
import elezioni.PartitoEnum;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

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
			
			ArrayList<Poll> arr = _authorpolls.get(aut);
			arr.add(p);
			_authorpolls.put(aut, arr);					
		}
	}
	
	private void updateDatePolls()
	{
		for(Poll p: _polls)
		{
			GregorianCalendar cal = p.getDt();
			if (!_datepolls.containsKey(cal))
				_datepolls.put(cal,new ArrayList<Poll>());
			ArrayList<Poll> arr = _datepolls.get(cal);
			arr.add(p);
			_datepolls.put(cal, arr);	
		}
	}
	
	private void updatePartitoPolls()
	{
		for(PartitoEnum part: PartitoEnum.values())
			_partitopolls.put(part, new ArrayList<Poll>());
		
		for(Poll p: _polls)
		{
			HashMap<PartitoEnum,Float> mp = p.getPercentages();
			Set<Map.Entry<PartitoEnum,Float>> myset = mp.entrySet();
			for(Map.Entry<PartitoEnum,Float> ent: myset)
			{
				PartitoEnum pt = ent.getKey();
				ArrayList<Poll> arr = _partitopolls.get(pt);
				arr.add(p);
				_partitopolls.put(pt, arr);
			}
		}
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

	public HashMap<GregorianCalendar, ArrayList<Poll>> getDatepolls()
	{
		return _datepolls;
	}

	public HashMap<PartitoEnum, ArrayList<Poll>> getPartitopolls()
	{
		return _partitopolls;
	}

	public HashMap<String, ArrayList<Poll>> getAuthorpolls()
	{
		return _authorpolls;
	}
	
}
