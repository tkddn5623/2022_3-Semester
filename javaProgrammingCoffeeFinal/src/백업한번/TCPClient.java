import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * 1 �� 1 ���� ��� Ŭ���̾�Ʈ ����
 */
public class TCPClient {

    private Socket mSocket;

    private BufferedReader mIn;
    private PrintWriter mOut;
    String r = "";
    
    public TCPClient() {}

    public String tcp(String str) {
        try {
            // ������ ��û ������
        	String ip = "localhost";
        	int port = 5000;
            mSocket = new Socket(ip, port);
            System.out.println(ip + " �����");

            // ��� �ձ�
            mIn = new BufferedReader(
                    new InputStreamReader(mSocket.getInputStream()));
            mOut = new PrintWriter(mSocket.getOutputStream());

            // �޼��� ����
            mOut.println(str);
            mOut.flush();

            // ���� ���
            r = mIn.readLine();

        } catch (IOException e) {
            System.out.println(e.getMessage());
        } finally {
            // ���� �ݱ� (���� ����)
            try {
                mSocket.close();
            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
        return r;
    }
}