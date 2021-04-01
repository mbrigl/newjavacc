
package javacc;

import org.simple.ExpressionTokenManager;
import org.simple.JavaCharStream;
import org.simple.StringProvider;
import org.simple.Token;

public class TokenizerTest {

  public static void main(String[] args) throws Exception {
    StringProvider provider = new StringProvider("ns.attr IS .56");
    ExpressionTokenManager tokenizer = new ExpressionTokenManager(new JavaCharStream(provider));
    Token t = null;
    while ((t = tokenizer.getNextToken()).kind != 0) {
      System.out.printf("%s(%s) ", t.image, t.kind);
    }
  }
}
