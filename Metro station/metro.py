
class Node :
    def __init__(self ,name : str,statno : int) -> None:
        self.name=name
        self.statno=statno
        self.next=None

class PurpleLine :
    def __init__(self) -> None:
        self.head1=None 

    def createP(self):
        p1=Node("Challaghatta",1)
        p2=Node("Kengeri",2)
        p3=Node("Attiguppe",3)
        p4=Node("Vijayanagar",4)
        p5=Node("Majestic",5)
        p6=Node("Trinity",6)
        p7=Node("Indranagar",7)
        p8=Node("Hoodi",8)
        p9=Node("Hopefarm",9)
        p10=Node("Whitefield",10)
        
        self.head1=p1
        p1.next=p2
        p2.next=p3
        p3.next=p4
        p4.next=p5
        p5.next=p6
        p6.next=p7
        p7.next=p8
        p8.next=p9
        p9.next=p10

class GreenLine :
    def __init__(self) -> None:
        self.head2=None       

    def createg(self):
        g1=Node("Nagsandra",1)
        g2=Node("Goraguntepalya",2)
        g3=Node("Srirampura",3)
        g4=Node("Mantri",4)
        g5=Node("Majestic",5)
        g6=Node("Lalbhag",6)
        g7=Node("Jaynagar",7)
        g8=Node("Bhanshankri",8)
        g9=Node("Konankunte Cross",9)
        g10=Node("Silk institute",10)
        
        self.head2=g1
        g1.next=g2
        g2.next=g3
        g3.next=g4
        g4.next=g5
        g5.next=g6
        g6.next=g7
        g7.next=g8
        g8.next=g9
        g9.next=g10


class MetroSystem :
    def __init__(self) -> None:
        P=PurpleLine()
        P.createP()
        self.head1=P.head1
        G=GreenLine()
        G.createg()
        self.head2=G.head2

    def DispayMetro(self) -> None:
        print("----------------------------------------------------------------------------------------------------------------------------------------------------")
        print("|\t\t\t\t\t\t\t\t(PURPLE LINE)\t\t\t\t\t\t\t\t\t\t\t|")
        print("|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|")
        
        current_node=self.head1
        while(current_node.statno != 5) :
            print(f"|\t\t\t\t\t\t\t\t  {current_node.name}\t\t\t\t\t\t\t\t\t\t\t|")
            print("|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|")
            current_node=current_node.next
        print("")
        print("|(GREEN LINE)--",end="")

        current_node1=self.head2
        while(current_node1 != None) :
            print(current_node1.name + "-->",end="")
            current_node1=current_node1.next
        print("|")
        print("|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|")
        current_node=current_node.next
        while(current_node != None) :
            print(f"|\t\t\t\t\t\t\t\t  {current_node.name}\t\t\t\t\t\t\t\t\t\t\t|")
            print("|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|")
            current_node=current_node.next
        print("\n----------------------------------------------------------------------------------------------------------------------------------------------------")
        print("")
        print("")

    def disFmid(self,stat:str)->int :
        current_node=self.head1
        while (current_node.next) :
            if current_node.name==stat :
                a=abs(current_node.statno-5)
                return a
            current_node=current_node.next

        current_node1=self.head2
        while (current_node1.next) :
            if current_node1.name==stat :
                b=abs(current_node1.statno-5)
                return b
            current_node1=current_node1.next

    def BuyTicket (self) :
        x=input("Enter Source station: ")
        y=input("Enter Destination station: ")

        if x==y :
            print("Invalid input")
            return
        
        j=self.disFmid(x)
        k=self.disFmid(y)
        
        
        TotalCost=(j+k)*10
        
        print("")
        print("**********************************************")
        print("\t\tTicket Details:")
        print("**********************************************")
        print(f"\tSource: {x}")
        print(f"\tDestination: {y}")
        print(f"\tTotal Cost: Rs.{TotalCost}")
        print("**********************************************")
        print("**********************************************")
        print("")

metro = MetroSystem()
metro.DispayMetro()
metro.BuyTicket()
    
   
        
        



