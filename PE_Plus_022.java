import java.io.*;
import java.util.*;

public class PE_Plus_022 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        PE_Plus_22 sol = new PE_Plus_22();
        sol.run();
    }

    private void run(){
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        Node[] nameNodes = new Node[n];
        Node current;
        Node next;
        int compVal = 0;

        for(int i = 0; i < n; i++)
            nameNodes[i] = new Node(s.next());

        for(int i = 1; i < n; i++){
            current = nameNodes[0];
            do{
                compVal = (current.str).compareTo(nameNodes[i].str);
                if(compVal < 0) next = current.right;
                else next = current.left;
                if(next != null) current = next;
            }while(next != null);
            if(compVal < 0) current.right = nameNodes[i];
            else current.left = nameNodes[i];
        }

        traverse(nameNodes[0], 0);

        int q = s.nextInt();
        String term = "";
        int score = 0;

        while(q-- > 0)
            System.out.println(search(s.next(), nameNodes[0]));
    }

    private int search(String s, Node currNode){
        int compVal = 0;
        do{
            compVal = s.compareTo(currNode.str);
            if(compVal < 0) currNode = currNode.left;
            if(compVal > 0) currNode = currNode.right;
        }while(compVal != 0);
        return currNode.score;
    }

    private int traverse(Node currNode, int mult){
        if(currNode.left != null) mult = traverse(currNode.left, mult);
        currNode.score *= ++mult;
        if(currNode.right != null) mult = traverse(currNode.right, mult);
        return mult;
    }
}

class Node{
    public Node(String s){
        str = s;
        score = scoreString(s);
    }

    String str;
    int score;
    Node left = null;
    Node right = null;

    private static int scoreString(String s){
        int score = 0;
        for(int i = 0; i < s.length(); i++)
            score += s.charAt(i) - 'A' + 1;
        return score;
    }
}
