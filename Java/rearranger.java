import java.util.Scanner;
class rearranger{
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("The total input you want to give : ");
		int totin = scn.nextInt();
		int inary[] = new int[totin];
		for(int i=0;i<=totin-1;i++){	
			System.out.print("Input " + (i+1) + " is : ");
			inary[i] = scn.nextInt();
		}
		int outary[] = new int[totin];
		int pointer, outpointer, lastdig=totin-1, looper, ptr, nxptr, lopval=1;
		for(outpointer=0;outpointer<=totin-1;outpointer++){
			pointer = 0;
		for(looper=lopval;looper<=lastdig;looper++){
			if(inary[pointer]>=inary[looper])
				pointer = looper;
			outary[outpointer] = inary[pointer];
			if(looper==lastdig){
				for(ptr=pointer;ptr<=lastdig;ptr++){
					if(ptr==lastdig){
						nxptr=ptr;
						lastdig--;
					}else nxptr = ptr+1;
					inary[ptr]=inary[nxptr];
				}
			}
			if(looper<=lastdig)
				lopval = pointer+1;
			else lopval = 0;
		}
		}
		if(outpointer==totin){
			for(outpointer=0;outpointer<=totin-1;outpointer++)
				if(outpointer<totin-1)
				System.out.print(outary[outpointer] + " < ");
				else System.out.print(outary[outpointer] + "\n");
		}
	}
}