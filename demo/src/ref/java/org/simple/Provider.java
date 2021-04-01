/* Generated By:JavaCC: Do not edit this line. Provider.java Version 8.0 */
/* JavaCCOptions:KEEP_LINE_COLUMN=true */
                                                 
 
package org.simple;

import java.io.IOException;

public interface Provider {
    /**
     * Reads characters into an array
     * @param buffer  Destination buffer
     * @param offset   Offset at which to start storing characters
     * @param length   The maximum possible number of characters to read
     * @return The number of characters read, or -1 if all read
     * @exception  IOException
     */
    public int read(char buffer[], int offset, int len) throws IOException;
    
    /**
     * Closes the stream and releases any system resources associated with
     * it.
     * @exception IOException
     */
     public void close() throws IOException;
    
}
/* JavaCC - OriginalChecksum=ada23a648ef18bd2b12038574d7d53c2 (do not edit this line) */
