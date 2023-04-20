import java.util.ArrayList;
import java.util.Scanner;
import java.lang.String;

public class Main {
    static int rank(Character c) {
        if (c == '(') return 3;
        if (c == '+' || c == '-') return 2;
        if (c == '*' || c == '/') return 1;
        return 0;
    }

    public static void main(String[] args) {
        ArrayList<Character> stack = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        String seq = sc.next();
        StringBuilder ans = new StringBuilder();

        for (char c : seq.toCharArray()) {
            if (c <= 'Z' && c >= 'A') {
                ans.append(c);
            } else if (c == ')') {
                while (!stack.isEmpty() && stack.get(stack.size()-1) != '(')
                    ans.append(stack.remove(stack.size()-1));
                stack.remove(stack.size()-1);
            } else if (c == '(') {
                stack.add(c);
            } else { // 높거나 같으면 당연히 먼저 출력
                while (!stack.isEmpty() && rank(c) >= rank(stack.get(stack.size() - 1)))
                    ans.append(stack.remove(stack.size() - 1));
                stack.add(c);
            }
        }

        while (!stack.isEmpty())
            ans.append(stack.remove(stack.size() - 1));

        System.out.println(ans);
    }
}