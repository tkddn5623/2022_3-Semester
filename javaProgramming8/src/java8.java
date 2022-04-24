import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class java8 {
	public static void main(String[] args) {
		int count = 0;
		String data;
		String[] lineArr = new String[256];
		try {
			InputStream fis = new FileInputStream ("input.txt");
			InputStreamReader isr = new InputStreamReader (fis);
			BufferedReader br = new BufferedReader(isr);
			
			while((data = br.readLine()) != null) {
				lineArr[count++] = data;
			}
			br.close();isr.close();fis.close();
			} catch (IOException e) {e.printStackTrace();}
	

		try {
			FileOutputStream fos = new FileOutputStream("output.txt");
			OutputStreamWriter osw = new OutputStreamWriter(fos);
			BufferedWriter bw = new BufferedWriter (osw);
			
			for(int i = count - 1; i >= 0; i--) {
				bw.write(lineArr[i]);
				if(i != 0) bw.newLine();
			}
			bw.flush();
			bw.close();fos.close();osw.close();
			} catch (IOException e) {e.printStackTrace();}
		
	}
	
}


