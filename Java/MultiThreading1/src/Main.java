
public class Main {

	public static void main(String [] args){
	
		/*Thread 1*/
		Runnable hello = new DisplayMessage("Hello");
		Thread thread1 = new Thread(hello);
		thread1.setDaemon(true);
		thread1.setName("hello");
		System.out.println("Starting hello thread...");
		thread1.start();
		
		/*Thread 2*/
		Runnable bye = new DisplayMessage("Goodbye");
		Thread thread2 = new Thread(hello);
		thread2.setPriority(Thread.MIN_PRIORITY);
		thread2.setDaemon(true);
		System.out.println("Starting goodbye thread...");
		thread2.start();
		
		/*Thread 3*/
		System.out.println("Starting thread3...");
		Thread thread3 = new GuessANumber(27);
		thread3.start();
		
		try{
			thread3.join();			/*Allowing thread 3 to terminate halting main thread*/
		}catch(InterruptedException e){
			System.out.println("Thread interrupted.");
		}
		
		/*Thread 4*/
		System.out.println("Starting thread4...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11");
		Thread thread4 = new GuessANumber(75);
		thread4.start();
		System.out.println("main() is ending...");
	}

}
