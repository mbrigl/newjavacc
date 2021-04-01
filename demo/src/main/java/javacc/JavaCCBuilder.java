
package javacc;

import org.javacc.jjtree.JJTree;
import org.javacc.parser.Main;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * The {@link JavaCCBuilder} class.
 */
public class JavaCCBuilder {

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
  public final JavaCCBuilder setCodeGenerator(Language language) {
    this.language = language;
    return this;
  }

  /**
   * Set the output directory.
   *
   * @param outputDirectory
   */
  public final JavaCCBuilder setOutputDirectory(File outputDirectory, String... pathes) {
    this.outputDirectory = toFile(outputDirectory, pathes);
    return this;
  }

  /**
   * Set the jj file.
   *
   * @param file
   */
  public final JavaCCBuilder setJJFile(File file, String... pathes) {
    this.jj = toFile(file, pathes);
    return this;
  }

  /**
   * Set the jj file.
   *
   * @param file
   */
  public final JavaCCBuilder setJJTreeFile(File file, String... pathes) {
    this.jjt = toFile(file, pathes);
    return this;
  }

  public static JavaCCBuilder of(Language language) {
    JavaCCBuilder builder = new JavaCCBuilder();
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

  public static final File USER   = new File(System.getProperty("user.dir"));
  public static final File BASE   = new File(USER, "src/main/resources");
  public static final File SOURCE = new File(USER, "src/main/java");
  public static final File TARGET = new File(USER, "src/test/java");

  /**
   * {@link #main}.
   *
   * @param args
   */
  public static void main(String[] args) {
    JavaCCBuilder builder = null;

    builder = JavaCCBuilder.of(Language.Cpp);
    builder.setOutputDirectory(TARGET, "org/parser");
    builder.setJJTreeFile(BASE, "ExpressionC++.jjt");
    builder.build();

    builder = JavaCCBuilder.of(Language.Java);
    builder.setOutputDirectory(TARGET, "org/parser");
    builder.setJJTreeFile(BASE, "Expression.jjt");
    builder.build();

    builder = JavaCCBuilder.of(Language.Cpp);
    builder.setOutputDirectory(TARGET, "org/simple");
    builder.setJJTreeFile(BASE, "ExpressionSimpleC++.jjt");
    builder.build();

    builder = JavaCCBuilder.of(Language.Java);
    builder.setOutputDirectory(TARGET, "org/simple");
    builder.setJJTreeFile(BASE, "ExpressionSimple.jjt");
    builder.build();

    // builder.setJJFile("/data/Repository/javacc7/examples/CORBA-IDL/IDL.jj");
    // builder.setJJFile("/data/Repository/javacc/examples/java/Lookahead/src/main/javacc/Example3.jj");

    // builder.setJJTreeFile(TARGET, "ToyJava.jjt");

    builder = JavaCCBuilder.of(Language.Cpp);
    builder.setOutputDirectory(SOURCE, "EG1");
    builder.setJJTreeFile(SOURCE, "EG0/eg1.jjt");
    builder.build();

    builder = JavaCCBuilder.of(Language.Cpp);
    builder.setOutputDirectory(SOURCE, "javacc8");
    builder.setJJTreeFile(BASE, "SPL.jjt");
    builder.build();

    builder = JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE);
    builder.setJJFile(BASE, "CalcInput.jj");
    builder.build();

    builder = JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE);
    builder.setJJFile(BASE, "CalcInput0.jj");
    builder.build();

    JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE, "ast").setJJTreeFile(BASE, "AST.jjt").build();
    JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE, "vst").setJJTreeFile(BASE, "VST.jjt").build();

    JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE, "test")
        .setJJFile(new File("/data/Repository/JavaCC/javacc8/examples/java/MailProcessing/src/main/javacc/Digest.jj")).build();
    JavaCCBuilder.of(Language.Java).setOutputDirectory(SOURCE, "test")
        .setJJFile(new File("/data/Repository/JavaCC/javacc8/examples/java/JavaCCGrammar/src/main/javacc/JavaCC.jj")).build();
  }
}
