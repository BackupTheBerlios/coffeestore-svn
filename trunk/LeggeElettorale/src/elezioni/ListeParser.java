package elezioni;

import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import elezioni.utils.FileReader;

public class ListeParser
{
	private Pattern _patternCandidato;
	private Map<PartitoEnum, String[]> _mapping;
	
	public ListeParser()
	{
		_patternCandidato = Pattern.compile("\\s*\\d+[).]?\\s*(.*)\\s+(.*)");
		_mapping = createMapping();
	}

	private Map<PartitoEnum, String[]> createMapping()
	{
		String[] socStrings = { "partito socialista", "ps" };
		String[] dxStrings = { "destra" };
		String[] legaStrings = { "lega nord" };
		String[] udcStrings = { "udc", "democratici cristiani" };
		String[] itvStrings = { "italia dei", "l\'italia dei", "idv", "italia del valori"};
		String[] saStrings = { "arcobaleno", "acrobaleno" };
		String[] pdlStrings = { "pdl", "partito delle lib", "partito della lib", "popolo dell", "il popolo"};
		String[] pdStrings = { "pd", "partito democratico" };
		String[] mpaStrings = { "mpa", "movimento per l", "autonomia alleanza per il sud" };
		String[] naStrings = {};

		HashMap<PartitoEnum, String[]> mapping = new HashMap<PartitoEnum, String[]>();
		mapping.put(PartitoEnum.SOC, socStrings);
		mapping.put(PartitoEnum.DX, dxStrings);
		mapping.put(PartitoEnum.LN, legaStrings);
		mapping.put(PartitoEnum.UDC, udcStrings);
		mapping.put(PartitoEnum.ITV, itvStrings);
		mapping.put(PartitoEnum.PDL, pdlStrings);
		mapping.put(PartitoEnum.PD, pdStrings);
		mapping.put(PartitoEnum.MPA, mpaStrings);
		mapping.put(PartitoEnum.SA, saStrings);
		mapping.put(PartitoEnum.NA, naStrings);
		
		return mapping;
	}

	public Map<PartitoEnum, Lista> parseCollegio(String fileName) throws WrongListaFileFormat
	{
		Map<PartitoEnum, Lista> liste = new HashMap<PartitoEnum, Lista>();

		Lista lista = null;
		for (String line : new FileReader(fileName))
		{
			if (!line.isEmpty())
			{
				Matcher matcher = _patternCandidato.matcher(line);
				if (matcher.matches())
				{
					String nome = matcher.group(1).trim();
					String cognome = matcher.group(2).trim();
					
					if (lista == null)
						throw new WrongListaFileFormat("Nome partito non trovato", fileName, line);
					
					lista.add(new Parlamentare(nome, cognome));
				}
				else
				{
					if (lista != null && lista.isEmpty())
						throw new WrongListaFileFormat("Lista vuota", fileName, line);
					
					lista = new Lista();
					PartitoEnum partito = getPartitoEnum(line);
					if (partito != PartitoEnum.NA)
						liste.put(partito, lista);
				}
			}
		}
		return liste;
	}

	private PartitoEnum getPartitoEnum(String line)
	{
		for (PartitoEnum partito : PartitoEnum.values())
		{
			PartitoEnum partitoFound = getPartitoEnum(partito, _mapping.get(partito), line);
			if (partitoFound != null)
				return partitoFound;
		}
		return PartitoEnum.NA;
	}

	private PartitoEnum getPartitoEnum(PartitoEnum partito, String[] strings, String line)
	{
		String lowerLine = line.toLowerCase();
		for (String str : strings)
			if (lowerLine.contains(str)) return partito;
		return null;
	}
}
