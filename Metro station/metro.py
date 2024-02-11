class Node :
    def __init__(self ,name : str,statdis : int) -> None:
        self.name=name
        self.statdis=statdis
        self.next=None

class MainNode :
    def __init__(self,dis: int,firstp,firstg) -> None:
        self.dis=dis
        self.firstp=firstp
        self.firstg=firstg

class PurpleLine :
    def __init__(self) -> None:
        self.head1=None 
        self.mid1=None

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
        self.mid1=p5
        p5.next=p6
        p6.next=p7
        p7.next=p8
        p8.next=p9
        p9.next=p10

class GreenLine :
    def __init__(self) -> None:
        self.head2=None 
        self.mid2=None      

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
        self.mid2=g5
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
        self.mid1=P.mid1

        G=GreenLine()
        G.createg()
        self.head2=G.head2
        self.mid2=G.mid2

        Main=MainNode(0,self.head1,self.head2)

    def DispayMetro(self) -> None:
        print("----------------------------------------------------------------------------------------------------------------------------------------------------")
        print("|\t\t\t\t\t\t\t\t(PURPLE LINE)\t\t\t\t\t\t\t\t\t\t\t|")
        print("|\t\t\t\t\t\t\t\t  |\t\t\t\t\t\t\t\t\t\t\t|")
        
        current_node=self.head1
        while(current_node.statdis != 5) :
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


    def CalculatePrice(self,source:str,destination:str)->int:
        ps1=0
        ps2=0
        gs1=0
        gs2=0
        a=0
        b=0
        
        #check source in purple
        temp1=self.head1
        while (temp1.next) :
            if temp1.name==source :
                ps1=temp1.statdis
                break
            temp1=temp1.next

        #check source in green line
        temp2=self.head2
        while (temp2.next) :
            if temp2.name==source :
                gs1=temp2.statdis
                break
            temp2=temp2.next

        #check destination in purple
        temp1=self.head1
        while (temp1.next) :
            if temp1.name==destination :
                ps2=temp1.statdis
                break
            temp1=temp1.next

        #check destination in green line
        temp2=self.head2
        while (temp2.next) :
            if temp2.name==destination :
                gs2=temp2.statdis
                break
            temp2=temp2.next
        
        #calucalte price
        x=self.mid1.statdis
        y=self.mid2.statdis

        #if stations on either side of majestic - purple
        if ((ps1 != 0) and (ps2 != 0) and ((ps1<x and ps2<x) or (ps1>x and ps2>x) or (ps1>x and ps2<x) or (ps1<x and ps2>x))) :
            a=abs(ps2-ps1)
            return a
        
        #if stations on either side of majestic - green
        elif (gs1 !=0 and gs2 !=0 and ((gs1<y and gs2<y) or (gs1>y and gs2>y) or (gs1>y and gs2<y) or (gs1<y and gs2>y))) :
            b=abs(gs2-gs1)
            return b
        
        #if stations on both lines 
        elif (ps1 !=0 and gs2 !=0) :
            a=abs(x-ps1)
            b=abs(y-gs2)
            return a+b
        
        elif (gs1 !=0 and ps2 !=0) :
            a=abs(x-ps2)
            b=abs(y-gs1)
            return a+b
            

    def BuyTicket (self) :
        x=input("Enter Source station: ")
        y=input("Enter Destination station: ")

        if x==y :
            print("Invalid input")
            return
        
        cost=self.CalculatePrice(x,y)
        TotalCost=(cost)*10
        
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

    
    
met=MetroSystem()
met.DispayMetro()
met.BuyTicket()

