import java.util.LinkedList;

public class LinkedListDemo {

    public static void main(String[] args) {
        
        LinkedList<String> list = new LinkedList<>(); // create a new empty linkedList

        //adding element for node in list
        list.add("1");
        list.add("9");
        list.add("A");
        list.addLast("C");
        list.addFirst("D");
        list.add(2, "E");
        

        //print list
        System.out.println(list);

        //remove 

        list.remove("B"); // remove node have the value is "B"
        list.removeFirst(); // remove first node;
        list.removeLast(); // remove last node;
        list.remove(0); //remove node at index 0


        System.out.println(list);


    }
}