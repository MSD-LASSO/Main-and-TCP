import java.nio.ByteBuffer;

public class HelloWorld {

    public static void main(String[] args) {
        // Prints "Hello, World" to the terminal window.
        System.out.println("Hello, World");
	byte b = 127;
	System.out.println("Value: 0x" + String.format("%02X", b));
	byte[] arr = ByteBuffer.allocate(4).putInt(100).array();
	// notes for tomorrow: make an array, then put with index & test
	System.out.println("arr[0]: 0x" + String.format("%02X", arr[0]));
	System.out.println("arr[1]: 0x" + String.format("%02X", arr[1]));
	System.out.println("arr[2]: 0x" + String.format("%02X", arr[2]));
	System.out.println("arr[3]: 0x" + String.format("%02X", arr[3]));

	int myInt = ByteBuffer.wrap(arr).getInt();
	System.out.println("int: " + myInt);

    }

}
