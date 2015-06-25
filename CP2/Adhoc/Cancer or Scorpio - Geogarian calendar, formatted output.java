import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int count=1,t;
		t = in.nextInt();

		while(count<=t){
			String date = in.next();

			int month = Integer.parseInt(date.substring(0, 2));
			int day = Integer.parseInt(date.substring(2,4));
			int year = Integer.parseInt(date.substring(4,8));
			
			/*System.out.println(month);
			System.out.println(day);
			System.out.println(year);*/

			Calendar calendar = new GregorianCalendar();

			calendar.set(Calendar.YEAR, year);
			calendar.set(Calendar.MONTH, month-1);
			calendar.set(Calendar.DAY_OF_MONTH, day);

			calendar.add(Calendar.DAY_OF_MONTH, 40*7);

			year       = calendar.get(Calendar.YEAR);
			month      = calendar.get(Calendar.MONTH);
			day 	   = calendar.get(Calendar.DAY_OF_MONTH);
			
			String zodiac;
			month = month+1;

			if( (month==1 && day>=21) || (month==2 && day<=19))
				zodiac = "aquarius";

			else if( (month==2 && day>=20) ||  (month==3 && day<=20) )
				zodiac = "pisces";

			else if( (month==3 && day>=21) ||  (month==4 && day<=20) )
				zodiac = "aries";

			else if( (month==4 && day>=21) ||  (month==5 && day<=21) )
				zodiac = "taurus";

			else if( (month==5 && day>=22) ||  (month==6 && day<=21) )
				zodiac = "gemini";

			else if( (month==6 && day>=22) ||  (month==7 && day<=22) )
				zodiac = "cancer";

			else if( (month==7 && day>=23) ||  (month==8 && day<=21) )
				zodiac = "leo";

			else if( (month==8 && day>=22) ||  (month==9 && day<=23) )
				zodiac = "virgo";

			else if( (month==9 && day>=24) ||  (month==10 && day<=23) )
				zodiac = "libra";

			else if( (month==10 && day>=24) ||  (month==11 && day<=22) )
				zodiac = "scorpio";

			else if( (month==11 && day>=23) ||  (month==3 && day<=22) )
				zodiac = "sagittarius";

			else
				zodiac = "capricorn";

			System.out.format("%d %02d/%02d/%04d %s%n",count,month,day,year,zodiac);    //  -->  "00461012"
			count++;
		}
	}
}
