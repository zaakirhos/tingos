import java.math.*;
/**
 * Tower
 */
public class Tower {

    public static void main(String[] args) {
        System.out.println("Tower");
    }
    public boolean isTower(int x) {
        boolean state = false;
        int y = 2;
       while(y <= Math.sqrt(x){
        while (x % y == 0){
            x /=y;
        }
        if (x==1){state=true;}
        
       }
        return state;
    }
}