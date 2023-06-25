import java.util.*;

public class ServeAndProtect {
    // array to keep track of the people who need protection
    private List<String> protectedPeople = new ArrayList<String>();
    
    // map to store the list of people who need protection and the reason
    private Map<String,String> protectReasons = new HashMap<String,String>();
    
    // Constructor
    public ServeAndProtect(){
    }
    
    // Function to add people to the list of those needing protection
    public void addProtection(String name, String reason){
        protectedPeople.add(name);
        protectReasons.put(name,reason);
    }
    
    // Function to remove a person from the list of those needing protection
    public void removeProtection(String name){
        protectedPeople.remove(name);
        protectReasons.remove(name);
    }
    
    // Function to update the reason for a person needing protection
    public void updateProtection(String name,String newReason){
        protectReasons.replace(name,newReason);
    }
    
    // Function to check if a person needs protection
    public boolean needsProtection(String name){
        return protectedPeople.contains(name);
    }
    
    // Function to check the reason for a person needing protection
    public String getProtectionReason(String name){
        return protectReasons.get(name);
    }
    
    // Function to check to see if the list of protected people is empty
    public boolean isListEmpty(){
        return protectedPeople.isEmpty();
    }
    
    // Function to print out the list of people needing protection
    public void printProtectionList(){
        System.out.println("List of People needing protection:");
        for(int i=0; i<protectedPeople.size(); i++){
            System.out.println(protectedPeople.get(i) + " (" + protectReasons.get(protectedPeople.get(i)) + ")");
        }
    }
    
    // Function to return an array of all people who need protection
    public String[] getProtectedPeople(){
        String[] people = new String[protectedPeople.size()];
        for (int i=0; i<protectedPeople.size(); i++){
            people[i] = protectedPeople.get(i);
        }
        return people;
    }
    
    public static void main(String[] args) {
        ServeAndProtect sap = new ServeAndProtect();
        sap.addProtection("John","Threats from the mafia");
        sap.addProtection("Jane","Witness in a court case");
        sap.addProtection("Jim","Domestic violence");
        sap.printProtectionList();
    }
}