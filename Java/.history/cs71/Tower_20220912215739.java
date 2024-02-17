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
        int maxY = Math.sqrt(x)
       while(y <= Math.sqrt(x){

        while (x % y == 0){
            x /=y;
        }
        if (x==1){state=true;}
        y++;
       }
        return state;
    }
}