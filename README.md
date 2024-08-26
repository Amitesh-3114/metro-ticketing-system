# metro-ticketing-system
This is my second year Data Structures and Algorithms Project where we implement one of the data structure and their operations . This is a completely menu Driven application written entirely in C language

#ABSTRACT

Bangalore's transportation backbone, the "Namma Metro", operates with a distinct ticketing system, setting it apart from other modes of transport. Rather than conventional fare structures, passengers can purchase tokens or recharge cards, simplifying travel payments. The fare calculation is straightforward: it begins with a base price and factors in the number of stations traversed, adding a predetermined fare for each station to determine the total bill. This streamlined approach contrasts with the often-complex pricing of other transportation options like autos.

Inspired by the efficiency of the metro system, we developed a mini-project called the "Metro Ticketing Platform." Its primary features include ticket purchase by selecting the origin and destination stations. Additionally, there's an administrative interface allowing authorized users to manage stations by adding or deleting them. This platform leverages singly linked lists, a data structure that facilitates connections from one node to the next, ensuring the preservation of node addresses.

#INTRODUCTION

In the metro ticketing system, the main node serves as a central hub for accessing essential data, including distance information between stations. When users engage with the platform to purchase tickets, the "buyTickets" function utilizes this distance data by calculating the distance from the head node to each station involved in the journey. By computing these distances, the function accurately determines the fare, taking into account factors such as distance traveled or zones crossed.

Moreover, the platform offers a valuable feature called "displayMap," which visually represents the metro network layout. This map is designed to present stations in a systematic and easy-to-understand manner. Users and administrators can visualize the spatial arrangement of stations, aiding in journey planning, station management, and overall navigation within the metro system. By providing a clear overview of station placement and connectivity, the display map enhances the user experience and facilitates efficient use of the metro network.

This ticketing platform serves as a demonstration of its capabilities, yet its features can be expanded to enhance functionality. For instance, the addition of more stations would broaden the network's reach and utility. Furthermore, implementing a password system for administrators would bolster security and access control, ensuring only authorized personnel can make changes to station data or perform administrative tasks. Additionally, incorporating user account numbers could offer added convenience and personalized services, enabling features such as loyalty programs or user-specific discounts. These enhancements would elevate the platform's effectiveness and cater to evolving user needs and expectations.

In summary, the Metro Ticketing Platform mini-project draws inspiration from the efficient ticketing system of the Namma Metro in Bangalore. It aims to replicate and enhance this efficiency, incorporating features such as station management and ticket purchase. The choice of singly linked lists as a data structure underscores the importance of efficient data organization and traversal in simulating the connections between metro stations.
