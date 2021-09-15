import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

class Main extends Initializer{
	public static int rand(int min, int max){
		return ThreadLocalRandom.current().nextInt(min, (max+1));
	}

	public static void main(String args[]){
		send.intro();
		enemy_selection();
        send.instructions();
        send.show_selection();
        int move, enemove, totmoves=1;
Fight: 	while(hero.gethp()>0 && enemy.gethp()>0){
        	if(totmoves%5==0)
        		System.out.println("\t\t\t\t\t\tSpecial Ability Available!");

        	System.out.print("\nYour move: ");
        	move = scn.nextInt();
        	
        	if(totmoves%5!=0 && move==2){
        		System.out.println("You are not allowed for Special move yet!");
        		continue Fight;
        	}

        	switch(move){
        		case 1:
        			System.out.println("You: Normal attack");
        			enemove = rand(1,3);
        			if(totmoves%5!=0 && enemove==2)
        				enemove = 1;
        			switch(enemove){
        				case 1:
        					hero.atk_enemy();
        					enemy.atk_hero();
        					System.out.println(enemy.getname() + ": Normal attack");
        					send.stats();
        					break;
        				case 2:
        					hero.atk_enemy();
        					enemy.satk_hero();
        					System.out.println(enemy.getname() + ": Special attack");
        					send.stats();
        					break;
        				case 3:
        					System.out.println(enemy.getname() + ": Doughed");
        					send.stats();
        					break;
        			}
        			break;

        		case 2:
        			System.out.println("You: Special attack");
        			enemove = rand(1,3);
        			if(totmoves%5!=0 && enemove==2)
        				enemove = 1;
        			switch(enemove){
        				case 1:
        					hero.satk_enemy();
        					enemy.atk_hero();
        					System.out.println(enemy.getname() + ": Normal attack");
        					send.stats();
        					break;
        				case 2:
        					hero.satk_enemy();
        					enemy.satk_hero();
        					System.out.println(enemy.getname() + ": Special attack");
        					send.stats();
        					break;
        				case 3:
        					System.out.println(enemy.getname() + ": Doughed");
        					send.stats();
        					break;
        			}
        			break;

        		case 3:
        			System.out.println("You: Douge");
        			enemove = rand(1,3);
        			if(totmoves%5!=0 && enemove==2)
        				enemove = 1;
        			switch(enemove){
        				case 1:
        					System.out.println(enemy.getname() + ": Normal attack");
        					send.stats();
        					break;
        				case 2:
        					System.out.println(enemy.getname() + ": Special attack");
        					send.stats();
        					break;
        				case 3:
        					System.out.println(enemy.getname() + ": Doughed");
        					send.stats();
        					break;
        			}
        			break;

        		default:
        			System.out.print("Wrong move try again: ");
        			break;
        	}
        	totmoves++;
        }

        if(hero.gethp()<=0)
        	System.out.println("\t\t\t\t\t\t\t!!You Lost the Fight!!");
        else
        	System.out.println("\t\t\t\t\t\t\t!!You Won the Fight!!");
	}
}

class Initializer{
	static Scanner scn = new Scanner(System.in);
	static Hero hero = new Hero();
	static Enemies captain_america = new Enemies(300, 15, 30, "Captain America");
	static Enemies hulk = new Enemies(800, 25, 50, "Hulk");
	static Enemies thor = new Enemies(500, 15, 70, "Thor");
	static Enemies spider_man = new Enemies(200, 10, 20, "Spider Man");
	static Enemies enemy = new Enemies(0,0,0,"null");
	static Drawing draw = new Drawing();
	static Dialouge send = new Dialouge();

	static void enemy_selection(){
		int selection = scn.nextInt();
		while(selection!=1 && selection!=2 && selection!=3 && selection!=4){
        System.out.println(selection + " is not listed!");
        System.out.print("Select again: ");
        selection = scn.nextInt();
        System.out.println();
        }

        switch(selection){
        	case 1:
        		enemy = captain_america;
        		break;
        	case 2:
        		enemy = hulk;
        		break;
        	case 3:
        		enemy = thor;
        		break;
        	case 4:
        		enemy = spider_man;
        		break;
        }
	}
}

class Hero extends Initializer{
	private float hp = 500;
	private float atk = 15;
	private float special_atk = 100;

	float gethp(){
		return hp;
	}

	void damage(float amount){
		hp-=amount;
	}

	void atk_enemy(){
		enemy.damage(atk);
	}

	void satk_enemy(){
		enemy.damage(special_atk);
	}
}

class Enemies extends Initializer{
	private float hp;
	private float atk;
	private float special_atk;
	private String name;

	Enemies(float hp, float atk, float special_atk, String name){
		this.hp = hp;
		this.atk = atk;
		this.special_atk = special_atk;
		this.name = name;
	}

	String getname(){
		return name;
	}

	float gethp(){
		return hp;
	}

	void damage(float amount){
		hp-=amount;
	}

	void atk_hero(){
		hero.damage(atk);
	}

	void satk_hero(){
		hero.damage(special_atk);
	}
}

class Drawing extends Initializer{
	void captain_america(){
		System.out.println("\n    |" + "\n O__}" + "\n/|  |" + "\n|/\\ " + "\n !!\n");
	}

	void hulk(){
		System.out.println("\n|     |" + "\n(^_O_^)" + "\n   | " + "\n   /\\" + "\n   !!\n");
	}

    void thor(){
        System.out.println("\n  [##]" + "\n_O__|" + "\n||   " + "\n /\\" + "\n !!\n");
    }

    void spider_man(){
        System.out.println("\n _O_" + "\n| | |" + "\n  /\\" + "\n | |\n");
    }
}

class Dialouge extends Initializer{
	void intro(){
		System.out.println("\nHi there, You are Welcomed to the Game.\n\n");
		System.out.println("\t-----------------");
		System.out.println("\t|\"Terminal Game\"|");
		System.out.println("\t-----------------\n\n");
		System.out.println("You are Iron Man.");
		System.out.println("To win the game defeat the Enemies!!\n");

		System.out.println("The enemies are listed below:- ");
		System.out.println("(1)Captain America");
        draw.captain_america();
		System.out.println("(2)Hulk");
        draw.hulk();
		System.out.println("(3)Thor");
        draw.thor();
		System.out.println("(4)Spider Man");
        draw.spider_man();
		System.out.print("Select your enemy: ");
	}

	void instructions(){
		System.out.println("\nThese are your possible moves:-");
        System.out.println("Normal attack = 1");
        System.out.println("Special attack = 2\n(Note:- Special attack only works after 5 attacks)");
        System.out.println("Dodge = 3\n\n");
	}

	void show_selection(){
		System.out.println("You have selected: " + enemy.getname() + ", Now Fight!");
	}

	void stats(){
		System.out.println("\t\t\t\t\t\t\t\t\t\t\t\tYour Health = " + hero.gethp());
		System.out.println("\t\t\t\t\t\t\t\t\t\t\t\t" + enemy.getname() + " Health = " + enemy.gethp());
	}
}