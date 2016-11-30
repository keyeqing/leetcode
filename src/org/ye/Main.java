package org.ye;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

    public static List<String> findRepeatedDnaSequences(String s) {
        Map<Long, Integer> myMap = new HashMap<Long, Integer>();
        List<String> res = new ArrayList<String>();
        if (s.length() < 10) return res;
        Long sum = 0L, tmp = 1L;
        for (int i = 0; i <= 9; i++) {
            sum = sum * 4 + getV(s.charAt(i));
            tmp *= 4;
        }
        tmp=tmp/4;
        myMap.put(sum, 1);
        for (int i = 1; i < s.length() - 9; i++) {
            sum = (sum - getV(s.charAt(i - 1)) * tmp) * 4 + getV(s.charAt(i + 9));
            Integer num = myMap.get(sum);
            if(num==null) num=0;
            if (num == 1) {
                res.add(s.substring(i, i + 10));
            }
            myMap.put(sum, num + 1);
        }
        return res;

    }

    public static Long getV(char c) {
        switch (c) {
            case 'A':
                return 0L;
            case 'C':
                return 1L;
            case 'G':
                return 2L;
            case 'T':
                return 3L;
            default:
                return -1L;
        }
    }


    public static void main(String[] args) {
        // write your code here
        String s = "";
        for (int i = 0; i < 5; i++) {
            s += "A";
        }
        for (int i = 0; i < 5; i++) {
            s += "C";
        }
        for (int i = 0; i < 5; i++) {
            s += "A";
        }
        for (int i = 0; i < 5; i++) {
            s += "C";
        }
        for (int i = 0; i < 5; i++) {
            s += "A";
        }
        List<String> res = findRepeatedDnaSequences(s);
        System.out.println(res);

    }
}
