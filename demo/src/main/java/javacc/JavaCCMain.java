
package javacc;

import org.javacc.parser.Main;

/**
 * The {@link JavaCCMain} class.
 */
public class JavaCCMain {

  public static final String BASE   = System.getProperty("user.dir") + "/src/main/resources";
  public static final String TARGET = System.getProperty("user.dir") + "/src/test/java";


  public static void main(String[] args) throws Exception {
    String[] arguments =
        new String[] { "-CODE_GENERATOR=Java", "-OUTPUT_DIRECTORY=" + TARGET + "/example1", BASE + "/test.jjt" };

    // JJTree jjtree = new JJTree();
    // jjtree.main(arguments);

    arguments[2] = TARGET + "/examples" + "/Example1.jj";

    Main.mainProgram(arguments);
  }
}
