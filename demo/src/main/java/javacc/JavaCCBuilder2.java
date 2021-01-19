
package javacc;

import java.io.File;

import javacc.JavaCCBuilder.Language;

/**
 * The {@link JavaCCBuilder2} class.
 */
public class JavaCCBuilder2 {

	public static final File USER = new File(System.getProperty("user.dir"));
	public static final File BASE = new File(USER, "src/main/resources");
	public static final File SOURCE = new File(USER, "src/main/java");
	public static final File TARGET = new File(USER, "src/test/java");

	/**
	 * {@link #main}.
	 *
	 * @param args
	 */
	public static void main(String[] args) {
		File baseCPP = new File("/data/Repository/JavaCC/javacc8/demo/src/test/java/special");
		JavaCCBuilder builder = null;

		builder = JavaCCBuilder.of(Language.Cpp);
		builder.setOutputDirectory(baseCPP, "special8");
		builder.setJJFile(baseCPP, "SpecialToken.jj");
		builder.build();
	}
}
