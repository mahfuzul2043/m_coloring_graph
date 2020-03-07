```
Description:
	The purpose of this program is to solve an M Coloring Graph problem. This program will take a number of components
	and assign them with a color. Components with the same color are pairable. The user is tasked with telling the program
	what components are NOT pairable. Based off of this information, the program will decide which components ARE pairable
	and output those components as groups of colors in lexigraphical order.

	When starting up the program, the user will be presented with the console. The first line will hold 2 integer values,
	separated by a space. The first integer specifies the number of components that are to be stored in the graph. The second
	integer specifies the number of components the current component can NOT be paired with.

	Each proceeding line represents the component number. On each proceeding line, the user is to enter the previously
	specified number of components the current component cannot be paired with. Each line should end with a 0.

	The following is a sample input:
	10 3		(10 components, each component cannot be paired with 3 components)
	5 6 2 0     (Component 1 cannot be paired with component 5, 6, and 2)
	1 7 3 0		(Component 2 cannot be paired with component 1, 7, and 3
	2 8 4 0     etc..
	5 9 3 0
	4 10 1 0
	1 9 8 0
	2 10 9 0
	6 10 3 0
	4 6 7 0
	5 7 8 0

	The above input will yield the following output:
	1 3 7		(each component in this group has a color of 1)
	2 4 6 10	(each component in this group has a color of 2)
	5 8 9		(each component in this group has a color of 3)
```