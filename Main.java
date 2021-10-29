class Parent {
	void parentMethod(){
	System.out.println("This is parent class");
	
	}
}
	class Child extends Parent{
	void childMethod(){
	System.out.println("This is child  class");
	}
	
	
}
public class Main 
{public static void main(String[] args) {
		Parent p= new Parent();
		Child c= new Child(); 
		p.parentMethod(); //method of parent by object of parent
	      
		c.childMethod();//method of child class by object of child class
		c.parentMethod();//method of parent class by object of child class
	}
}