import java.util.Hashtable;


public class LCS {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 int[] array = {100, 2, 1, 3, 10, 90, 4, 7, 9, 8, 5, 6, 99, 2, 4};
		 
		 int l = find(array);
		 
		 System.out.println(l);
	}
	
	public static int find(int[] array)
	{
		int max = 1;
		for(int n=0;n<array.length;n++)
		{
			int i = array[n];
			boolean cs = hl.containsKey(i);
			if(cs) continue;
			
			boolean cl = hl.containsKey(i-1);
			boolean cr = hl.containsKey(i+1);
			
			if(!cl && !cr)
			{
				hl.put(i, 1);
				hs.put(i, i);
			}
			else if(cl && !cr)
			{
				int start = hs.get(i-1);
				int len = hl.get(i-1);
				
				hl.put(i, len+1);
				hs.put(i, start);
				hl.put(start, len+1);				
			}
			else if(!cl && cr)
			{
				int len = hl.get(i+1);
				
				hl.put(i, len+1);
				hs.put(i, i);
				hl.put(i+len, len+1);
				hs.put(i+len, i);			
			}
			else
			{
				int lm = hs.get(i-1);
				int rm = i + hl.get(i+1);
				int len = rm-lm+1;
				
				hl.put(lm, len);
				hl.put(rm, len);
				hs.put(rm, lm);
			}				
		}
		
		for(int v:hl.values())
			if(v>max) max = v;
		
		return max;
	}
	
	private static Hashtable<Integer, Integer> hl = new Hashtable<Integer, Integer>();
	private static Hashtable<Integer, Integer> hs = new Hashtable<Integer, Integer>();

}

