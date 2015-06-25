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


			calendar.add(Calendar.DAY_OF_MONTH, days);

			int year       = calendar.get(Calendar.YEAR);
			int month      = calendar.get(Calendar.MONTH);
			int dayOfMonth = calendar.get(Calendar.DAY_OF_MONTH);SS
			
			System.out.println(dayOfMonth + " " + (month+1) + " " + year);
		}
	}
}
