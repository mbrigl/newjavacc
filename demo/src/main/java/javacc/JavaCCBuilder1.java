
package javacc;

import org.javacc.jjtree.JJTree;
import org.javacc.parser.Main;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * The {@link JavaCCBuilder1} class.
 */
public class JavaCCBuilder1 {

  public static enum Language {

    Java("Java"),
    Cpp("C++"),
    CSharp("C#");

    public final String name;

    private Language(String name) {
      this.name = name;
    }

  }

  private Language language;
  private File     outputDirectory;

  private File     jj;
  private File     jjt;

  /**
   * Set the code generator.
   *
   * @param language
   */
  public final JavaCCBuilder1 setCodeGenerator(Language language) {
    this.language = language;
    return this;
  }

  /**
   * Set the output directory.
   *
   * @param outputDirectory
   */
  public final JavaCCBuilder1 setOutputDirectory(File outputDirectory, String... pathes) {
    this.outputDirectory = toFile(outputDirectory, pathes);
    return this;
  }

  /**
   * Set the jj file.
   *
   * @param file
   */
  public final JavaCCBuilder1 setJJFile(File file, String... pathes) {
    this.jj = toFile(file, pathes);
    return this;
  }

  /**
   * Set the jj file.
   *
   * @param file
   */
  public final JavaCCBuilder1 setJJTreeFile(File file, String... pathes) {
    this.jjt = toFile(file, pathes);
    return this;
  }

  public static JavaCCBuilder1 of(Language language) {
    JavaCCBuilder1 builder = new JavaCCBuilder1();
    builder.setCodeGenerator(language);
    return builder;
  }

  /**
   * Run the parser generator.
   */
  public final void build() {
    try {
      List<String> arguments = new ArrayList<String>();
      arguments.add("-CODE_GENERATOR=" + language.name);
      arguments.add("-OUTPUT_DIRECTORY=" + outputDirectory.getAbsolutePath());
      arguments.add("-JJTREE_OUTPUT_DIRECTORY=" + outputDirectory.getAbsolutePath());
      if (jjt != null) {
        arguments.add(jjt.getAbsolutePath());
        String path = jjt.getAbsolutePath();

        JJTree jjtree = new JJTree();
        jjtree.main(arguments.toArray(new String[arguments.size()]));

        int offset = path.lastIndexOf("/");
        int length = path.lastIndexOf(".");
        arguments.set(arguments.size() - 1, outputDirectory + path.substring(offset, length) + ".jj");
      } else {
        arguments.add(jj.getAbsolutePath());
      }

      Main.mainProgram(arguments.toArray(new String[arguments.size()]));
    } catch (Throwable e) {
      e.printStackTrace();
    }
  }

  private static File toFile(File file, String... pathes) {
    return (pathes.length == 0) ? file : new File(file, String.join(File.separator, pathes));
  }

  public static final File USER = new File(System.getProperty("user.dir"));
  public static final File BASE = new File("/data/smartIO/develop/parser/parser/src/main/resources/it/smartio/text");

  /**
   * {@link #main}.
   *
   * @param args
   */
  public static void main(String[] args) {
    JavaCCBuilder1 builder = JavaCCBuilder1.of(Language.Java);
    builder.setOutputDirectory(BASE, "oql");
    builder.setJJTreeFile(BASE, "parser/OQL.jjt");
    builder.build();
  }
}
