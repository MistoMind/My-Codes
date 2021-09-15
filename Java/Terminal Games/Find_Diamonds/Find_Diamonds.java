import java.util.concurrent.ThreadLocalRandom;
import java.util.Scanner;

class Start{
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		System.out.print("Number of Rows & Columns: ");
		int r = scn.nextInt();
		while(r<=3){
			System.out.println("Can't be so small");
			System.out.print("Try a bigger number(Bigger than 3): ");
			r=scn.nextInt();
			System.out.println();
		}
		Platform obj = new Platform(r,r);
		Dialouge speak = new Dialouge();
	
		speak.welcome();
		speak.how2play();
		obj.show_postion();
		while(!obj.win()){
		System.out.print("Move: ");
		String move=scn.next();
		obj.move(move);
		}
	}
}

class Platform{
	char platform[][];
	int toty,totx,diax,diay,herox,heroy;

	Platform(int tr, int tc){
		platform = new char[tr][tc];
		toty = tr;
		totx = tc;
		place_objects();
	}
		
	void clrscr(){
		System.out.print("cls");
		System.out.flush();
	}

	void wait(int ms){
		try{
			Thread.sleep(ms);
		}
		catch(InterruptedException ex){
			Thread.currentThread().interrupt();
		}
	}

	int rand(int min, int max){
		return ThreadLocalRandom.current().nextInt(min, (max+1));
	}

	void place_objects(){
		diax = rand(0,totx-1);
		diay = rand(0, toty-1);
		herox = rand(0,totx-1);
		heroy = rand(0, toty-1);
		while(diax==herox && diay==heroy) place_objects();
		while(heroy==0 || herox==0 || heroy==toty-1 || herox==totx-1) place_objects();
		while(diay==0 || diax==0 || diay==toty-1 || diax==totx-1) place_objects();
		int row, column;
		for(row=0;row<toty;row++)
		for(column=0;column<totx;column++){
			platform[row][column] = ' ';
			if(row==0 || column==0 || row==toty-1 || column==totx-1)
			platform[row][column]='-';
		}
		platform[heroy][herox] = 'H';
		platform[diay][diax] = '#';
	}

	boolean win(){
		if(herox==diax && heroy==diay){
			platform[diay][diax] = '$';
			clrscr();
			show_postion();
			System.out.println("\t\t\t\t\t\t\"You have won the Game\"");
			return true;
		}return false;
	}

	void show_postion(){
		for(int y=0;y<toty;y++){
			System.out.println();
		for(int x=0;x<totx;x++)
			System.out.print(platform[y][x] + " ");
		}
		System.out.println();
	}

	void move(String move){
		switch(move){
			case "w":
				clrscr();
				move_up();
				show_postion();
				break;
			case "a":
				clrscr();
				move_left();
				show_postion();
				break;
			case "s":
				clrscr();
				move_down();
				show_postion();
				break;
			case "d":
				clrscr();
				move_rigth();
				show_postion();
				break;
			case "AI":
				ai_move();
		}
	}

	void move_up(){
		if(heroy-1>0){
		platform[heroy][herox]=' ';
		platform[--heroy][herox]='H';	
		}else System.out.println("Wall, can't move");
	}

	void move_down(){
		if(heroy+1<totx-1){
		platform[heroy][herox]=' ';
		platform[++heroy][herox]='H';	
		}else System.out.println("Wall, can't move");
	}

	void move_left(){
		if(herox-1>0){
		platform[heroy][herox]=' ';
		platform[heroy][--herox]='H';
		}else System.out.println("Wall!, can't move");
	}

	void move_rigth(){
		if(herox+1<toty-1){
		platform[heroy][herox]=' ';
		platform[heroy][++herox]='H';	
		}else System.out.println("Wall, can't move");
	}

	void ai_move(){
	while(heroy<diay){
		clrscr();
		move_down();
		System.out.println("Moving DOWN");
		show_postion();
		wait(500);
	}
	while(heroy>diay){
		clrscr();
		move_up();
		System.out.println("Moving UP");
		show_postion();
		wait(500);
	}
	while(herox<diax){
		clrscr();
		move_rigth();
		System.out.println("Moving RIGTH");
		show_postion();
		wait(500);
	}
	while(herox>diax){
		clrscr();
		move_left();
		System.out.println("Moving LEFT");
		show_postion();
		wait(500);
	}
	}
}

class Dialouge{
	void welcome(){
		System.out.println("\n\n\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		System.out.println("\t\t\t\t\t\t| \"Welcome to the Find the Box Game!\" |");
		System.out.println("\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		System.out.println("\t\t\t\t\t\t\t\t-By Khush Seervi");
	}
	void how2play(){
		System.out.println("\n\nHow to Play:-");
		System.out.println("Use w, s, a and d to move H(Hero) UP, DOWN, LEFT and RIGTH repectively");
		System.out.println("To win the game make H go to #(Box) to get RICH!!!!");
	}
}
