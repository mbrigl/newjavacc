package special.special8;

import java.io.StringReader;

public class Main {

	public static void main(String[] args) throws ParseException {
		StringReader reader = new StringReader("DD -- ccc\n");
		SpecialTokenTokenManager scanner = new SpecialTokenTokenManager(new SimpleCharStream(reader));
		SpecialToken parser = new SpecialToken(scanner);
		parser.Input();
	}
}
