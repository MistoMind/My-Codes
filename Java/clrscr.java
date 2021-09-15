import java.util.Scanner;
class clrscr{
	public static void clrscr(){
		System.out.print("\033[H\033[2J");
		System.out.flush();
	}
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		while(!scn.next().equals("q")){
			clrscr();
			System.out.println("This is printed");
		}
		scn.close();
	}
}