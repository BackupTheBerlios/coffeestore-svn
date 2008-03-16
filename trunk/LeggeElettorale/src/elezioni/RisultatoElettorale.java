package elezioni;

public class RisultatoElettorale
{
	private PartitoEnum _partito;
	private float _perc;
	private String _note;
	
	public RisultatoElettorale(PartitoEnum _partito, float _perc, String _note)
	{
		super();
		this._partito = _partito;
		this._perc = _perc;
		this._note = _note;
	}

	public PartitoEnum get_partito()
	{
		return _partito;
	}

	public void set_partito(PartitoEnum _partito)
	{
		this._partito = _partito;
	}

	public float get_perc()
	{
		return _perc;
	}

	public void set_perc(float _perc)
	{
		this._perc = _perc;
	}

	public String get_note()
	{
		return _note;
	}

	public void set_note(String _note)
	{
		this._note = _note;
	}
	
	
}
