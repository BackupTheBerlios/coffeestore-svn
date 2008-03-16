package elezioni;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import elezioni.utils.FileReader;
import elezioni.utils.Text;

public class PartitiParser
{
	private static String _dirListe = "varie/listecandidati/src";
	private static String _cameraNumParlamentariFile = "varie/listecandidati/numparlamentaricamera.txt";
	private static String _senatoNumParlamentariFile = "varie/listecandidati/numparlamentarisenato.txt";
	private static String _cameraStr = "camera";
	
	private Pattern _patternFileName;
	private Pattern _patternNumCandidati;
	
	private Map<RegioneEnum, Regione> _regioni;
	private Map<PartitoEnum, Partito> _partiti;
	private Map<String, Integer> _cameraNumParlamentari;
	private Map<String, Integer> _senatoNumParlamentari;
	
	public PartitiParser()
	{
		_patternFileName = Pattern.compile("(\\w+?)(\\d{0,1})_(\\w+)\\.txt");
		_patternNumCandidati = Pattern.compile("(\\w+)\\s+(\\d+)");

		_regioni = new HashMap<RegioneEnum, Regione>();
		_partiti = new HashMap<PartitoEnum, Partito>();
		_cameraNumParlamentari = new HashMap<String, Integer>();
		_senatoNumParlamentari = new HashMap<String, Integer>();
	}
	
	public void parse() throws FileNotFoundException, WrongFileFormat
	{
		parseNumParlamentari();
		parseListe();
	}
	
	private void parseNumParlamentari() throws FileNotFoundException, WrongNumParlamentariFileFormat
	{
		parseNumParlamentari(_cameraNumParlamentari, _cameraNumParlamentariFile);
		parseNumParlamentari(_senatoNumParlamentari, _senatoNumParlamentariFile);
	}

	private void parseNumParlamentari(Map<String, Integer> numParlamentari, String numParlamentariFile) throws FileNotFoundException, WrongNumParlamentariFileFormat
	{
		for (String line : new FileReader(numParlamentariFile))
		{
			Matcher matcher = _patternNumCandidati.matcher(line);
			if (matcher.matches())
				numParlamentari.put(matcher.group(1), Integer.parseInt(matcher.group(2)));
			else
				throw new WrongNumParlamentariFileFormat(numParlamentariFile, line);
		}
	}

	private void parseListe() throws FileNotFoundException, WrongFileFormat
	{
		ListeParser parser = new ListeParser();
		
		File directory = new File(_dirListe);
		for (File file : directory.listFiles())
		{
			Matcher matcher = _patternFileName.matcher(file.getName());
			if (matcher.matches())
			{
				boolean isCamera = matcher.group(3).equals(_cameraStr);
				RegioneEnum regioneEnum = RegioneEnum.valueOf(Text.capitalize(matcher.group(1)));
				String circName = String.format("%s%s", matcher.group(1), matcher.group(2));
				
				parseListe(parser, file.getAbsolutePath(), isCamera, regioneEnum, circName);
			}
		}
	}

	private void parseListe(ListeParser parser, String fileName, boolean isCamera, RegioneEnum regioneEnum, String circName) throws FileNotFoundException, WrongListaFileFormat
	{
		Regione regione = getRegione(regioneEnum);
		Circoscrizione circoscrizione = new Circoscrizione(circName, getNumParlamentari(isCamera, circName));
		regione.addCircoscrizione(circoscrizione);
		Map<PartitoEnum, Lista> currentCircoscrizioni = parser.parseListeCircoscrizione(fileName);
		for (PartitoEnum partitoEnum : currentCircoscrizioni.keySet())
		{
			Partito partito = getPartito(partitoEnum);
			if (isCamera)
				partito.addToCamera(circoscrizione, currentCircoscrizioni.get(partitoEnum));
			else
				partito.addToSenato(circoscrizione, currentCircoscrizioni.get(partitoEnum));
		}
	}

	private Partito getPartito(PartitoEnum partitoEnum)
	{
		Partito partito = _partiti.get(partitoEnum);
		if (partito == null)
		{
			partito = new Partito(partitoEnum.name(), new Premier("", "")); //TODO: file premier
			_partiti.put(partitoEnum, partito);
		}
		return partito;	
	}

	private int getNumParlamentari(boolean isCamera, String circName)
	{
		return (isCamera) ? _cameraNumParlamentari.get(circName) : _senatoNumParlamentari.get(circName);
	}

	private Regione getRegione(RegioneEnum regioneEnum)
	{
		Regione regione = _regioni.get(regioneEnum);
		if (regione == null)
		{
			regione = new Regione(regioneEnum.name());
			_regioni.put(regioneEnum, regione);
		}
		return regione;
	}
	
	public Map<PartitoEnum, Partito> getPartiti()
	{
		return _partiti;
	}

	public Map<RegioneEnum, Regione> getRegioni()
	{
		return _regioni;
	}
}
