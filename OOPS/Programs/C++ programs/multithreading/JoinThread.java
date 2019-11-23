public class JoinThread extends Thread { 
    public void run() 
    { 
        System.out.println("Welcome to sricity "); 
        try { 
            Thread.sleep(300); 
        } 
        catch (InterruptedException ie) { 
        } 
        System.out.println("welcome to IIIT "); 
    } 
    public static void main(String[] args) 
    { 
        JoinThread c1 = new JoinThread(); 
        JoinThread c2 = new JoinThread(); 
        c1.start(); 
  
        /*try { 
            c1.join(); // Waiting for c1 to finish 
        } 
        catch (InterruptedException ie) { 
        } */
  
        c2.start(); 
    } 
}