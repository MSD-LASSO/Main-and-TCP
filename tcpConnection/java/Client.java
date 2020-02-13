import java.net.*;
import java.io.*;
import java.nio.ByteBuffer;
 
public class Client {

    public static void main(String[] args) {
       
	int intSize = 4;

	int Port = 5010;
	String IpAddress = "129.21.41.75";

	byte[] send;
	byte[] send_size_bytes;
	byte[] recv = new byte[256];
 
	int dataA;
	int dataB;
	int dataC;



        try (Socket socket = new Socket(IpAddress, Port)) {
 
            OutputStream output = socket.getOutputStream();
	    //PrintWriter writer = new PrintWriter(output, true);

	    InputStream input = socket.getInputStream();
            //BufferedReader reader = new BufferedReader(new InputStreamReader(input));

	    input.read(recv, 0, 256);

	    dataA = ByteBuffer.wrap(recv).getInt(0);
	    dataB = ByteBuffer.wrap(recv).getInt(4);
	    dataC = ByteBuffer.wrap(recv).getInt(8);

	    System.out.println(String.format("0x%08X", dataA));
	    System.out.println(String.format("0x%08X", dataB));
	    System.out.println(String.format("0x%08X", dataC));

	    ByteBuffer bb = ByteBuffer.allocate(intSize);
	    bb.putInt(0x0000FF);

	    send = bb.array();
	    output.write(send, 0, send.length);
	    output.flush();

	    socket.close();
 
        } catch (UnknownHostException ex) {
 
            System.out.println("Server not found: " + ex.getMessage());
 
        } catch (IOException ex) {
 
            System.out.println("I/O error: " + ex.getMessage());
        }
    }
}
