# Stage_2

Project Ideas:
Table management system
Good restaurants usually run a system to manage the occupancy, reservation, and billing of their tables. In this idea, we are going to build a small table managemnet system to manage few tables of different sizes in a hot-pot restaurant.


User Menu:


Part 1 -> setting up

System first asks user to input the set up of its restaurant including,
- Table size and corresponding number of tables
- Price per head for adult and child separately
- Time allowance for each table in minutes 
Also, this system is default that 10% service charge is required. Food and drinks are either self-served or order through staff and free of charge.

Concerning the table number, all table number will be integers while the first number indicates the table size of that table. Staff can indicate the location of tables in restaurant by the table size and the numbers remained. 


Part 2 -> Operation

This system support functions of
1: Add new table for customers
2: Release a table and get the bill for customers
3: Search information of a particular table
4: Reset the setting of the restaurant 
9: Quit system
To operate any function above, users input the corresponding number of the function. 

1) Add new table for customers
System will ask for number of customers, find the most suitble table and output the corresponding table number for staff to bring customer to.
At the same time, the system will store the information of that table such as number of customers and start counting time. 

2) Release a table and get the bill for customers
The system will print a receipt showing the number of adult and child customers, toal amount before service charge, and total amount to pay.
Then, the system will set the table information to default value and get ready for next table of cutomers.

3) Search information of a particular table
The system will ask for table number to be search. Table information includind,
- Number of adult and child customers
- Time remaining for that table
will be shown.

4) Reset the setting of the restaurant 
Reset the information including,
- Table size and corresponding number of tables
- Price per head for adult and child separately
- Time allowance for each table in minutes 
IMPORTANT: all the table information will also be reset to default value. 

9) Quit system
To close down the system and have to restart again from Part1 next time.




# Stage_1

Project Ideas:
Table management system

Good restaurants usually run a system to manage the occupancy, reservation, and billing of their tables. In this idea, we are going to build a small table managemnet system to manage few tables of different sizes in a hot-pot restaurant. The default setting of this restaurant,
4 tables of 2
4 tables of 4
2 tables of 6
2 tables of 8
1 table of 12
$180 per head
10% service charge is needed
time allowed per table is 2.5 hours
food and drinks are self-served and free of charge

The system shall include basic features of a table managment system,
1. availability of a table
2. occupy a table
3. release a table
4. suggest the most suitable table according to the given number of customers
5. time of occupying a table
6. notification for waiters of table occupied for more than 2.5 hours
7. allow changes of price, table number and size of tables
8. able to print the order list of a table for checking and billing
