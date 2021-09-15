import java.util.Scanner;

class Brute_Force{
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		System.out.print("Total number of Characters = ");
		int total_digits = scn.nextInt();
		System.out.print("Enter the minimum character: ");
		char min = (char)scn.nextInt();
		System.out.print("Enter the maximum character: ");
		char max = (char)scn.nextInt();
		scn.close();
		Initializer obj = new Initializer(total_digits, max, min);

		while(obj.array[obj.array.length-1]<obj.max_range){
			if(obj.checkGuess()){
				System.out.println("Guess is : " + obj.buildgetGuess() + " \"Cracked!!\"");
				break;
			}

			obj.algo(0);
			System.out.println("Trying : " + obj.buildgetGuess());
		}
	}
}

class Initializer{
	char array[];
	String guess;
	char temp_char;
	char max_range;
	char min_range;
	int pos;

	Hidden hobj = new Hidden();

	Initializer(int size, char max_range, char min_range){
		array = new char[size];
		guess = "";
		temp_char = 'A';
		this.max_range = max_range;
		this.min_range = min_range;
		pos = 0;
		reset(size);
	}

	void increase(int position){
		temp_char = array[position];
		temp_char++;
		array[position] = temp_char;
	}

	String buildgetGuess(){
		guess="";
		for(char x: array)
			guess+=x;
		return guess;
	}

	boolean checkGuess(){
		if(hobj.secret(guess))
			return true;
		else return false;
	}

	void reset(int till){
		for(int x=0;x<till;x++)
			array[x] = min_range;
		array[0] = (char)(min_range-1);
	}

	void algo(int position){
		if(array[position]==max_range){
			algo(position+1);
		}else{
			increase(position);
			if(position>0)
			reset(position);
		}
	}
}