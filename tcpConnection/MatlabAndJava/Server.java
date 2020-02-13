import java.io.*;
import java.net.*;
import java.util.Date;
import java.nio.ByteBuffer; 

public class Server {

    public static void main(String[] args) {
	int port = 5010;

	int sizeInt = 8; // 4 bytes er int

	int numInts = 3;
	double dataA=5.56453675768;
	double dataB=7.56453675768;
	double dataC=-9.56453675768;
//	int dataA = 0x0000FFFF;
//	int dataB = 0x00000001;
//	int dataC = 0xFFFFFFFF;

	byte[] sendMsgBytes;

	int recvSizeInt = 20;
	byte[] recv = new byte[recvSizeInt];
	
	int recvMsg;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
 
            //while (true) {
                Socket socket = serverSocket.accept();

		InputStream input = socket.getInputStream();
		//BufferedReader reader = new BufferedReader(new InputStreamReader(input));
                OutputStream output = socket.getOutputStream();

		ByteBuffer bb = ByteBuffer.allocate(numInts*sizeInt);
		bb.putDouble(dataA);
		bb.putDouble(dataB);
		bb.putDouble(dataC);

		sendMsgBytes = bb.array();

		output.write(sendMsgBytes);
	
		input.read(recv, 0, recvSizeInt);
		recvMsg = ByteBuffer.wrap(recv).getInt();
		System.out.println(String.format("0x%08X", recvMsg));

		// use if reading string
		//String recv_str = new String(recv, "UTF-8");
		//System.out.println("CLIENT: " + recv_str);

		socket.close();
            //}
 
        } catch (IOException ex) {
            System.out.println("Server exception: " + ex.getMessage());
            ex.printStackTrace();
        }
    }
}
