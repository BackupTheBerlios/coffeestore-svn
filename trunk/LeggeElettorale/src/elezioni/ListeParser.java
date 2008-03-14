package elezioni;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ListeParser
{
	private Pattern _patternCandidato;
	private Pattern _patternCandidatoBis;
	
	public ListeParser()
	{
		_patternCandidato = Pattern.compile("\\s*\\d+\\)?\\s*(.*)\\s+(.*)");
		_patternCandidatoBis = Pattern.compile("\\s*\\d+\\.?\\s*(.*)\\s+(.*)");
	}

	public Map<String, Lista> parseRegione(String fileName) throws IOException
	{
		Map<String, Lista> liste = new HashMap<String, Lista>();
		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		
		String line = null;
		Lista lista = null;
		while ((line = reader.readLine()) != null)
		{
			if (!line.isEmpty())
			{
				Matcher matcher = _patternCandidato.matcher(line);
				Matcher matcherBis = _patternCandidatoBis.matcher(line);
				boolean matched = matcher.matches() || matcherBis.matches(); 
				if (matched)
				{
					if (matcherBis.matches())
						matcher = matcherBis;

					String nome = matcher.group(1);
					String cognome = matcher.group(2);
					
					if (lista == null)
					{
						System.out.println(line);
						throw new WrongListaFileFormat("Nome partito non trovato " + fileName);
					}
					
					lista.add(new Parlamentare(nome, cognome));
				}
				else
				{
					if (lista != null && lista.isEmpty())
					{
						System.out.println(line);
						throw new WrongListaFileFormat("Lista vuota " + fileName);
					}
					
					lista = new Lista();
					liste.put(line, lista);
				}
			}
		}
		return liste;
	}

}
