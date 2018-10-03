import java.io.*;
import java.util.HashMap;

class L334
{
	private static HashMap<String, String> leetMap = new HashMap<String, String>();
	private static HashMap<String, String> wordMap = new HashMap<String, String>();
	
	private static void fillMap()
	{
		leetMap.put("e", "3");
		leetMap.put("E", "3");
		leetMap.put("a", "4");
		leetMap.put("A", "4");
		leetMap.put("b", "8");
		leetMap.put("c", "(");
		leetMap.put("C", "(");
		leetMap.put("g", "6");
		leetMap.put("G", "6");
		leetMap.put("i", "!");
		leetMap.put("I", "!");
		leetMap.put("l", "1");
		leetMap.put("L", "1");
		leetMap.put("t", "7");
		leetMap.put("T", "7");
		leetMap.put("z", "2");
		leetMap.put("Z", "2");
		leetMap.put("s", "5");
		leetMap.put("S", "5");
		leetMap.put("o", "0");
		leetMap.put("O", "0");
		leetMap.put("x", "%");
		leetMap.put("X", "%");
		
		wordMap.put("and", "nd");
		wordMap.put("dude", "d00d");
		wordMap.put("girl", "grill");
		wordMap.put("h4x", "hacks");
		wordMap.put("hackers", "h4x0rz");
		wordMap.put("hacker", "h4x0r");
		wordMap.put("hi", "hai");
		wordMap.put("mate", "m8");
		wordMap.put("like", "liek");
		wordMap.put("pawn", "pwn");
		wordMap.put("pawned", "pwnd");
		wordMap.put("please", "pl0x");
		wordMap.put("the ", "teh");
		wordMap.put("you", "u");
		wordMap.put("are", "r");
		wordMap.put("why", "y");
		wordMap.put("elite", "1337");
		wordMap.put("really", "RLY");
		wordMap.put("strong", "stronk");
	}
	
	public static void main(String[] args)
	{
		fillMap();
		System.out.println(convertToLeet(args[0]));
	}
	
	private static String convertToLeet(String input)
	{
		StringBuffer result = new StringBuffer();
		String[] words = input.split("\\s+"); // regex for one or more whitespace
		for(int word = 0; word < words.length; ++ word) // this for loop is for converting whole words
		{
			String curWord = wordMap.get(words[word]);
			if(curWord == null)
			{
				for(int i = 0; i < words[word].length(); ++ i) // this for loop is for converting letter by letter, it is only entered if there is no match in the word dictionary
				{
					String part = leetMap.get(words[word].substring(i, i + 1));
					if(part == null)
						result.append(words[word].substring(i, i + 1));
					else
						result.append(part);
				}
				result.append(" ");
			}
			else
			{
				result.append(curWord);
				result.append(" ");
			}
		}
		return result.toString();
	}
}
