
package javacc;

import org.javacc.parser.Main;

/**
 * The {@link JavaCCMain} class.
 */
public class JavaCCMain {

  public static final String BASE   = "/data/smartIO/develop/parser/parser/src/main/resources/it/smartio/text/parser";
  public static final String TARGET = "/data/smartIO/develop/parser/parser/src/main/resources/it/smartio/text/oql";


  public static void main(String[] args) throws Exception {
    String[] arguments = new String[] { "-CODE_GENERATOR=Java", "-OUTPUT_DIRECTORY=" + TARGET, BASE + "/Expression.jjt" };

    // JJTree jjtree = new JJTree();
    // jjtree.main(arguments);

//    arguments[2] = TARGET + "/examples" + "/Example1.jj";

    Main.mainProgram(arguments);
  }
}
