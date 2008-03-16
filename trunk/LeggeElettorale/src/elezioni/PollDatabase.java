package elezioni;

import java.sql.Date;
import java.util.ArrayList;
import java.util.HashMap;

public class PollDatabase
{
	private HashMap<String,Poll> _authorpolls;
	private HashMap<Date,Poll> _datepolls;
	private HashMap<Partito,Poll> _partitopolls;
	
	private ArrayList<Poll> _polls;
	
	public PollDatabase()
	{
		super();
		_authorpolls = new HashMap<String,Poll>();
		_datepolls = new HashMap<Date,Poll>();
		_partitopolls = new HashMap<Partito,Poll>();
		_polls = new ArrayList<Poll>();
	}
	
	public ArrayList<Poll> getPolls()
	{
		return _polls;
	}
}
