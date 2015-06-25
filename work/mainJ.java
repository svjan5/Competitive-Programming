import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		while(true){
			int days = in.nextInt();
			int date_day = in.nextInt();
			int date_month = in.nextInt()-1;
			int date_year = in.nextInt();
			
			if(days == 0 && date_day==0 && date_month==-1 && date_year==0)
				break;
			
			Calendar calendar = new GregorianCalendar();

			calendar.set(Calendar.YEAR, date_year);
			calendar.set(Calendar.MONTH, date_month);
			calendar.set(Calendar.DAY_OF_MONTH, date_day);

			//add one day
			calendar.add(Calendar.DAY_OF_MONTH, days);

			//date is now jan. 1st 2010
			int year       = calendar.get(Calendar.YEAR);  // now 2010
			int month      = calendar.get(Calendar.MONTH); // now 0 (Jan = 0)
			int dayOfMonth = calendar.get(Calendar.DAY_OF_MONTH); // now 1
			
			System.out.println(dayOfMonth + " " + (month+1) + " " + year);
		}
	}
}
