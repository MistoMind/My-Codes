public class Hidden{
	public static boolean secret(String signal){
		boolean status;
		String pass = "KHUSH";
		if(signal.equals(pass))
			status = true;
		else status = false;
		return status;
	}
}