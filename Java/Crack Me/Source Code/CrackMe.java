import java.util.Scanner;

public class CrackMe {
	public static void main(String args[]){
		Hidden obj = new Hidden();

		Scanner scn = new Scanner(System.in);
		System.out.print("Type the magic phrase : ");
		String in = scn.nextLine();
		System.out.println();

		while(!obj.secret(in)){
			System.out.println("Failed, Try again! (-_-)");
			System.out.print("Type the magic phrase : ");			
			in = scn.nextLine();
			System.out.println();
		}
		System.out.println("You have cracked me!! \\(^_^)/");
	}	
}