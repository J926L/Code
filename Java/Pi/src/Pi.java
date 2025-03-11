public class Pi {
    public static void main(String[] args) throws Exception {
        int iterations = 100000;  // 预设迭代次数
        
        double sum = 0.0;
        double sign = 1.0;
        double denominator = 1.0;

        for (int i = 0; i < iterations; i++) {
            sum += sign / denominator;
            sign *= -1;
            denominator += 2;
        }
        
        System.out.println("π 近似值: " + sum * 4);
    }
}
