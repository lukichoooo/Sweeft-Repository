import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solutions {

    // --------------------1------------------------
    static String palindromeAfterLetterDeletion(String s) {

        if (s.length() <= 2)
            return "YES";

        int L = 0, R = s.length() - 1;

        boolean canForgive = true;

        while (L < R) {
            if (s.charAt(L++) == s.charAt(R--)) {
                continue;
            } else {
                if (canForgive) {
                    canForgive = false;
                    L--;
                    R++;

                    if (L + 1 >= R)
                        return "YES";

                    if (s.charAt(L + 1) == s.charAt(R))
                        L++;
                    else if (s.charAt(R - 1) == s.charAt(L))
                        R--;
                    else
                        return "NO";
                } else {
                    return "NO";
                }
            }
        }
        return "YES";
    }

    // --------------------2------------------------
    static class Path {
        public int idx;
        public String s;
        public int bal = 0; // how much more is '(' in nuber than ')'
        // if bal < 0 path is NOT VALID

        Path(int idx, String s, int bal) {
            this.bal = bal;
            this.idx = idx;
            this.s = new String(s);
        }
    };

    static void printAllValidParanthesis(int n) {
        Queue<Path> q = new LinkedList<>();
        q.add(new Path(0, "", 0));
        final int end = 2 * n;

        while (!q.isEmpty()) {
            Path curr = q.poll();

            if (curr.idx == end) {
                if (curr.bal == 0) {
                    System.out.println(curr.s);
                }
                continue;
            }

            if (curr.bal < 0)
                continue;

            curr.idx++;

            // pick '('
            Path opening = new Path(curr.idx, curr.s, curr.bal);
            opening.s += '(';
            opening.bal++;
            if (opening.bal <= end - opening.idx) // we should be able to make bal = 0 at the end
            {
                q.add(opening);
            }

            // pick ')'
            Path closing = new Path(curr.idx, curr.s, curr.bal);
            closing.s += ')';
            closing.bal--;
            if (closing.bal >= 0) {
                q.add(closing);
            }
        }
    }

    // --------------------3-----------------------
    static List<Integer> merge(List<Integer> A, List<Integer> B) {
        final int n = A.size(), m = B.size();
        List<Integer> C = new ArrayList<>(n + m);
        int a = 0, b = 0;
        while (a < n && b < m)
            C.add((A.get(a) < B.get(b) ? A.get(a++) : B.get(b++)));
        while (a < n)
            C.add(A.get(a++));
        while (b < m)
            C.add(B.get(b++));
        return C;
    }

    // --------------------4------------------------
    static List<Integer> addOne(List<Integer> list) {
        if (list.size() == 0)
            return List.of(1);

        List<Integer> A = new ArrayList<>(list);

        final int n = A.size();

        final int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int sum = A.get(i) + carry;

            if (sum <= 9) {
                A.set(i, sum);
                return A;
            } else {
                A.set(i, 0);
            }
        }
        A.add(0, 1);
        return A;
    }

    // --------------------5------------------------
    static int maxContainer(List<Integer> heights) {
        final int n = heights.size();

        int maxContainer = 0;

        int L = 0, R = n - 1;
        while (L < R) {
            final int len = R - L;
            final int height = Math.min(heights.get(L), heights.get(R));
            maxContainer = Math.max(maxContainer, height * len);

            if (heights.get(L) < heights.get(R)) {
                L++;
            } else {
                R--;
            }
        }

        return maxContainer;
    }

    public static void main(String[] args) {
        // 1
        System.out.println(palindromeAfterLetterDeletion("afga"));

        // 2
        printAllValidParanthesis(2);

        // 3
        List<Integer> res = merge(
                new ArrayList<>(Arrays.asList(1, 2, 4)),
                new ArrayList<>(Arrays.asList(1, 3, 4)));
        System.out.println(res);

        // 4
        System.out.println(addOne(Arrays.asList(1, 2, 3)));

        // 5
        System.out.println(maxContainer(Arrays.asList(1, 8, 6, 2, 5, 4, 8, 3, 7)));
    }

}
