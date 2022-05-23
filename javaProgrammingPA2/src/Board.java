import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

public class Board {
	static final String ANSI_RESET = "\033[0m";
	static final String ANSI_FG_BLACK = "\033[30m";
	static final String ANSI_FG_WHITE = "\033[37m";
	static final String ANSI_BG_BLACK = "\033[40m";
	static final String ANSI_BG_WHITE = "\033[47m";
	private HashMap<Integer, mygameObject> map;
	private HashSet<Integer> set;
	private King bKing;
	private King wKing;
	private Queen bQueen;
	private Queen wQueen;
	private Rook bRook1;
	private Rook bRook2;
	private Rook wRook1;
	private Rook wRook2;
	private Bishop bBishop1;
	private Bishop bBishop2;
	private Bishop wBishop1;
	private Bishop wBishop2;
	private Knight bKnight1;
	private Knight bKnight2;
	private Knight wKnight1;
	private Knight wKnight2;
	private Pawn bPawn1;
	private Pawn bPawn2;
	private Pawn bPawn3;
	private Pawn bPawn4;
	private Pawn bPawn5;
	private Pawn bPawn6;
	private Pawn bPawn7;
	private Pawn bPawn8;
	private Pawn wPawn1;
	private Pawn wPawn2;
	private Pawn wPawn3;
	private Pawn wPawn4;
	private Pawn wPawn5;
	private Pawn wPawn6;
	private Pawn wPawn7;
	private Pawn wPawn8;
	Board(boolean withFile) {
		/* Your code */
		map = new HashMap<Integer, mygameObject>(); //For display
		set = new HashSet<Integer>();               //For valid destination
		Declare();
		if(withFile == false) {
			
		}
		else {
			try {
				InputStream fis = new FileInputStream ("input.txt");
				InputStreamReader isr = new InputStreamReader (fis);
				BufferedReader br = new BufferedReader(isr);
				
				while((data = br.readLine()) != null) {
					lineArr[count++] = data;
				}
				br.close();isr.close();fis.close();
				} catch (IOException e) {e.printStackTrace();}
		
		}
	}

	public boolean isFinish(boolean withFile) {
		/* Your code */
		return false;
	}
	
	public void selectObject(boolean withFile) {
		/* Your code */
		System.out.print("Select piece: ");
		
	}
	
	public void moveObject(boolean withFile) {
		/* Your code */
	}
	
	public void printBoard(boolean withFile) {
		/* Your code */
		boolean odd = true;
		System.out.println("   a  b  c  d  e  f  g  h ");
		for(int y = 8; y >= 1; y--) {
			System.out.print(y + " ");
			for (int x = 1; x <= 8; x++) {
				if(odd) {
					// Black background, white character
					System.out.print(ANSI_BG_BLACK + ANSI_FG_WHITE
							+ (map.get(XY(x, y)) != null? map.get(XY(x, y)).Name() : "   ")
							+ ANSI_RESET + ANSI_RESET);
				} else {
					System.out.print(ANSI_BG_WHITE + ANSI_FG_BLACK
							+ (map.get(XY(x, y)) != null? map.get(XY(x, y)).Name() : "   ")
							+ ANSI_RESET + ANSI_RESET);
					/// White background, black character
					/*System.outPrint(ANSI_BG_WHITE + ANSI_FG_BLACK
							+ Piece Color
							+ Piece Type
							+ Possible Move Position
							+ ANSI_RESET + ANSI_RESET);*/
				}
				odd = !odd;
			}
			odd = !odd;
			System.out.print("\n");
		}
		
	}
	private void Declare() {
		bKing = new King(5, 8, 'K', 'b', ' ');
		wKing = new King(5, 1, 'K', 'w', ' ');
		bQueen = new Queen(4, 8, 'Q', 'b', ' ');
		wQueen = new Queen(4, 1, 'Q', 'w', ' ');
		bBishop1 = new Bishop(3, 8, 'B', 'b', ' ');
		bBishop2 = new Bishop(6, 8, 'B', 'b', ' ');
		wBishop1 = new Bishop(3, 1, 'B', 'w', ' ');
		wBishop2 = new Bishop(6, 1, 'B', 'w', ' ');
		bKnight1 = new Knight(2, 8, 'N', 'b', ' ');
		bKnight2 = new Knight(7, 8, 'N', 'b', ' ');
		wKnight1 = new Knight(2, 1, 'N', 'w', ' ');
		wKnight2 = new Knight(7, 1, 'N', 'w', ' ');
		bRook1 = new Rook(1, 8, 'R', 'b', ' ');
		bRook2 = new Rook(8, 8, 'R', 'b', ' ');
		wRook1 = new Rook(1, 1, 'R', 'w', ' ');
		wRook2 = new Rook(8, 1, 'R', 'w', ' ');
		bPawn1 = new Pawn(1, 7, 'P', 'b', ' ');
		bPawn2 = new Pawn(2, 7, 'P', 'b', ' ');
		bPawn3 = new Pawn(3, 7, 'P', 'b', ' ');
		bPawn4 = new Pawn(4, 7, 'P', 'b', ' ');
		bPawn5 = new Pawn(5, 7, 'P', 'b', ' ');
		bPawn6 = new Pawn(6, 7, 'P', 'b', ' ');
		bPawn7 = new Pawn(7, 7, 'P', 'b', ' ');
		bPawn8 = new Pawn(8, 7, 'P', 'b', ' ');
		wPawn1 = new Pawn(1, 2, 'P', 'w', ' ');
		wPawn2 = new Pawn(2, 2, 'P', 'w', ' ');
		wPawn3 = new Pawn(3, 2, 'P', 'w', ' ');
		wPawn4 = new Pawn(4, 2, 'P', 'w', ' ');
		wPawn5 = new Pawn(5, 2, 'P', 'w', ' ');
		wPawn6 = new Pawn(6, 2, 'P', 'w', ' ');
		wPawn7 = new Pawn(7, 2, 'P', 'w', ' ');
		wPawn8 = new Pawn(8, 2, 'P', 'w', ' ');
	}
	private int XY(int x, int y) {
		return x * 10 + y;
	}
	class Dest extends mygameObject{
		public Dest() {
			super(-1, -1, ' ', ' ', '*');
		}
	}
	class King extends mygameObject{
		public King(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
	class Queen extends mygameObject{
		public Queen(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
	class Bishop extends mygameObject{
		public Bishop(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
	class Rook extends mygameObject{
		public Rook(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
	class Knight extends mygameObject{
		public Knight(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
	class Pawn extends mygameObject{
		public Pawn(int x, int y, char type, char color, char target) {
			super(x, y, type, color, target);
			map.put(XY(x, y), this);
		}
	}
}
