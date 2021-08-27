import java.util.HashMap;
import java.util.Map;

class temp {
    public static void main(String[] args) {
        HashMap<String, Integer> hm = new HashMap<>();
        hm.put("Rahul", 1);
        hm.put("Roop", 2);
        for (Map.Entry element : hm.entrySet()) {
            System.out.println(element.getValue());
        }
    }
}