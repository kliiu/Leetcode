package Hot100_Java;
import java.util.*;

class Solution49 {
        public List<List<String>> groupAnagrams(String[] strs) {
            Map<List<Character>,List<String>> map= new HashMap<>();
            for(String s:strs){
                char []chars=s.toCharArray();//这里比较繁琐，先将字符串转为字符数组再装箱
                Arrays.sort(chars);
                List<Character> characters=new ArrayList<>();
                for(char c:chars){
                    characters.add(c);
                }
                if(map.containsKey(characters)){
                    map.get(characters).add(s);
                }
                else {
                    List<String> tempList = new ArrayList<>();
                    tempList.add(s);
                    map.put(characters,tempList);
                }
            }
            Iterator<List<String>> iterator= map.values().iterator();
            List<List<String>> ans= new ArrayList<>();
            while(iterator.hasNext()){
                ans.add(iterator.next());
            }
            return ans;
        }

}

class Test{
    public static void main(String[] args) {
        Solution49 s=new Solution49();
        String[] strings={"eat","tea","tan","ate","nat","bat"};
        s.groupAnagrams(strings);
    }
}
