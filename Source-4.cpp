//Name: Haque, Mahfuzul
//Last Modified: 4/19/2018

/*Description:
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
*/

#include <iostream>
#include <vector>

using namespace std;

class Backtrack {
private:
	vector<vector<bool>> groups;									  //this 2d vector will store a graph of the components and the components they cannot be paired with
	int numComponents, numSubCompanies;								

	bool isPairable(vector<int>& colors, int color, int component) {  //this function is responsible for checking whether a certain color can be assigned to a certain component
		for (int i = 0; i < numComponents; i++) {
			if (groups[component][i] && color == colors[i]) {		  //if the components cannot be paired and the colors are the same, then a color cannot be assigned
				return false;
			}
		}
		return true;
	}

	bool backtrackLogic(vector<int>& colors, int component) {		  //function responsible for assigning colors
		if (component == numComponents) {							  //base case of recursive call. IF we've reached the last component, then all components have been visited. Hence return
			return true;
		}
		for (int color = 1; color <= numSubCompanies; color++) {		
			if (isPairable(colors, color, component)) {				 //check if a color can be assigned to current component
				colors[component] = color;
				if (backtrackLogic(colors, component + 1)) {		//recursively call and check each proceeding component
					return true;									//if a valid color has been assigned, return true
				}
				colors[component] = 0;								//else reassign color to 0 to specify that a color could not be assigned
			}
		}
		return false;
	}

public:
	Backtrack(int size, int numComponents, int numSubCompanies) : numComponents(numComponents), numSubCompanies(numSubCompanies) {
		groups.resize(size, vector<bool>(size));					//resize 2d vector to store graph
	}
	void getPairableCompanies() {
		vector<int> colors(numComponents);							//this vector will hold all the colors of the components
		if (!backtrackLogic(colors, 0)) {							//if the recursive function returns false, then we know there is no solution. start from compoent 0 as specified
																	//in second parameter
			cout << "no solution";
			
		}
		else {
			for (int i = 1; i <= numSubCompanies; i++) {		   //if this loop has been reached, then we know a solution exists. Print out the colors in groups in lexicographical order
				for (int y = 0; y < numComponents; y++) {
					if (colors[y] == i) {
						cout << (y + 1) << ' ';
					}
				}
				cout << endl;
			}
		}
	}
	void addEdge(int vertex, int cantPair) {						//specificy which components cannot be paired
		groups[vertex][cantPair - 1] = true;
	}
};



int main() {

	int numComponents, subCompanies;
	cin >> numComponents >> subCompanies;

	Backtrack backtrack(numComponents, numComponents, subCompanies);

	for (int i = 0; i < numComponents; i++) {
		while (true) {
			int cantPair;
			cin >> cantPair;
			if (cantPair == 0) break;
			backtrack.addEdge(i, cantPair);
		}
	}

	backtrack.getPairableCompanies();

	return 0;
}