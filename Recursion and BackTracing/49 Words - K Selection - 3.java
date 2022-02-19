//Link: https://nados.io/question/words-k-selection-3?zen=true
import java.io.*;
import java.util.*;

public class Main {

  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String str = br.readLine();
    int k = Integer.parseInt(br.readLine());

    HashMap<Character, Integer> unique = new HashMap<>();
    String ustr = "";
    for (char ch : str.toCharArray()) {
      if (unique.containsKey(ch) == false) {
        unique.put(ch, 1);
        ustr += ch;
      } else {
        unique.put(ch, unique.get(ch) + 1);
      }
    }

    fun(ustr, unique, "", 0, k);
  }

  public static void fun(String ustr, HashMap<Character, Integer> mp, String asf, int idx, int k) {
      if(k < 0) return;
      if(idx == ustr.length()) {
          if(k == 0) System.out.println(asf);
          return;
      }

      char ch = ustr.charAt(idx);
      for(int i = mp.get(ch); i >= 0; i--) {
          String s = "";
          for(int j = 0; j < i; ++j) s += ch;
          fun(ustr, mp, asf + s, idx + 1, k - i);
      }
  }

}