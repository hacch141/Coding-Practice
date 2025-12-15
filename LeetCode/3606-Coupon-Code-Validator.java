// 3606. Coupon Code Validator

class Solution {
    public Set<String> business = new HashSet<>(Arrays.asList("electronics", "grocery", "pharmacy", "restaurant"));

    boolean isValidCode(String s) {
        for (char ch : s.toCharArray()) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_') {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
        int n = code.length;
        List<List<String>> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (isActive[i] == true && business.contains(businessLine[i]) && code[i].length() > 0) {
                list.add(new ArrayList<>(Arrays.asList(code[i], businessLine[i])));
            }
        }
        Comparator<List<String>> cmp = (a, b) -> {
            if (a.get(1).equals(b.get(1))) {
                return a.get(0).compareTo(b.get(0));
            }
            return a.get(1).compareTo(b.get(1));
        };
        list.sort(cmp);
        
        List<String> ans = new ArrayList<>();
        for (List<String> l : list) {
            if (isValidCode(l.get(0))) {
                ans.add(l.get(0));
            }
        }
        return ans;
    }
}
