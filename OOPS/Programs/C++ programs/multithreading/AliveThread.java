public class AliveThread extends Thread { 
    public void run() 
    { 
        System.out.println("Welcome to Sricity "); 
        try { 
            Thread.sleep(300); 
        } 
        catch (InterruptedException ie) { 
        } 
        System.out.println("Welcome to IIITs "); 
    } 
    public static void main(String[] args) 
    { 
        AliveThread c1 = new AliveThread(); 
        AliveThread c2 = new AliveThread(); 
        c1.start(); 
        c2.start(); 
        System.out.println(c1.isAlive()); 
        System.out.println(c2.isAlive()); 
    } 
}