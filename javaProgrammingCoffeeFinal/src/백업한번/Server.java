import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

class Server 
{
	private ServerSocket serverSocket;
	private List <ServerThread> list;
	public Server(){
		try{
			serverSocket= new ServerSocket (9500);
			System.out.println("���� �غ� �Ϸ�");
			list = new  ArrayList<ServerThread>();
			while(true){
				Socket socket = serverSocket.accept();
				ServerThread st = new ServerThread(socket, list);
				st.start();  //������ ����- ������ ����
				list.add(st);  //the number of entries in list : num of clients
			}//while
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	class ServerThread extends Thread{
		public ServerThread() {
			
		}
	}
}