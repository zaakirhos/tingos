import java.math.*;

/**
 * Tower
 */
public class Tower {

    public static void main(String[] args) {
        System.out.println(tower(241));
    }
public static int towerCounts(int n){
    int towerCount = 0;
    for (int i = n-1; i > 0; i--){
        if (isTower(i)){
            towerCount++;
        }
    }   
    return towerCount;
}
    public static boolean isTower(int n) {
        int y = 2;
        int maxY = (int)(Math.sqrt(n));
        while (y <= maxY) {
            int x = n;
            while (x % y == 0) {
                x /= y;
            }
            if (x == 1) {
                return true;
            } else {
                y++;
            }
        }
        return false;
    }
}