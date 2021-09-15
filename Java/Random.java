import java.util.concurrent.ThreadLocalRandom;
class Random{
	public static int rand(int min, int max){
		return ThreadLocalRandom.current().nextInt(min, (max+1));
	}

	public static void main(String args[]) {
		System.out.println(rand(1,3));
	}
}