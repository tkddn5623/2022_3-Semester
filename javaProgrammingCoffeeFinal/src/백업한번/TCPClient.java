import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * 1 대 1 소켓 통신 클라이언트 예제
 */
public class TCPClient {

    private Socket mSocket;

    private BufferedReader mIn;
    private PrintWriter mOut;
    String r = "";
    
    public TCPClient() {}

    public String tcp(String str) {
        try {
            // 서버에 요청 보내기
        	String ip = "localhost";
        	int port = 5000;
            mSocket = new Socket(ip, port);
            System.out.println(ip + " 연결됨");

            // 통로 뚫기
            mIn = new BufferedReader(
                    new InputStreamReader(mSocket.getInputStream()));
            mOut = new PrintWriter(mSocket.getOutputStream());

            // 메세지 전달
            mOut.println(str);
            mOut.flush();

            // 응답 출력
            r = mIn.readLine();

        } catch (IOException e) {
            System.out.println(e.getMessage());
        } finally {
            // 소켓 닫기 (연결 끊기)
            try {
                mSocket.close();
            } catch (IOException e) {
                System.out.println(e.getMessage());
            }
        }
        return r;
    }
}