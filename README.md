This is the classic example of the Knight's Tour problem. This implementation uses the recursive backtracking method.
Output: every line has a list of 25 integers separated by commas representing the positions on the board. 

Useful functions:
	CalculatePaths(int x, int y) is the recursive function of the entire project. 
		It checks for visited and out of bounds squares before visiting squares.
	Visit() and UnVisit() are what help keep track of the order that the squares have been visited.
