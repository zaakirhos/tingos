import java.math.*;

/**
 * Tower
 */
public class Tower {

    public static void main(String[] args) {
        System.out.println("Tower");
    }
public int towerCounts(int n){
    int towerCount = 0;
    for (int i = 0; i < n; i++){
        if (is)
    }   
}
    public static boolean isTower(int x) {
        boolean state = false;
        int y = 2;
        int maxY = (int)(Math.sqrt(x));
        while (y <= maxY) {

            while (x % y == 0) {
                x /= y;
            }
            if (x == 1) {
                state = true;
            } else {
                y++;
            }
        }
        return state;
    }
}