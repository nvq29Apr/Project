# Hotel's order management

## Introduction
* Assignment : The hotel order management program
* Mục đích : Apply the knowledge of data structures and algorithms to solve a problem.
    - Data structures : Linked list, Binary search tree
    - Algorithms : Sorting, Searching
* Contributor : 1
* Time complete : 1 week
* Languages and Tools : C, DevC++ IDE
## Design
* Field of each order : **code** (order code), **people** (numbers of customer), **room** (room number), **hotel** (hotel code), **date**, **kid** (numbers of child)
* Linked list ![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/9de041ce-5730-4f2a-b64a-f0b65daf7306)
* Binary Search Tree ![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/51228788-1d6a-44b5-9e4c-04c5c9cc7f5b)
## Demo
![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/98201aae-7c92-43ae-a1e6-febf1562d36f)
### Funtions
#### Read data from .txt file
* Initialize the initial orders in the booking_orders.txt file.  
* Input format: 
    - First line is n (integer) is numbers of order
    - n line next is each order : code people room hotel date kid![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/12fb4be3-c1ec-42b7-9c2e-e09b74874415)
* Then read the file and store it in a linked list. ![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/e1155e4c-e862-4ad0-8c63-f01ba3f2fe5f)

#### Print all exist order
![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/9815a650-c594-4c4e-9b96-4d39da211515)
#### Check amount of invalid order
Child cannot book hotel without adult => An valid order is number of child < numbers of customer ![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/801f3faf-625a-4bbf-90dd-e29b127fabaf)
#### Search by code
![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/a7b7f4ff-a2bb-45e3-a7a9-627c6e12eceb)
#### Modifie order
Enter order code and new information (number of people, date). Before modify, check if order is valid ![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/091c7372-8fc1-4eb8-b1ae-d6f793f84db0)
#### Cancel order
Delete node that stored the order customer want to cancel
![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/2468c01a-1603-45ff-8dc1-fc7f2973934d)
#### Save order list to .txt file
![image](https://github.com/nvq29Apr/Hotel-s-order-with-C/assets/119597631/00060f17-4dbf-4827-8cd4-f5ecb3c7a529)
#### Exit!
Exit program

#### >> Run this program on [OnlineGDB](https://onlinegdb.com/syMJXKOvW) 
