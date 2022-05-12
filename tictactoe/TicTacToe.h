class TicTacToe
{
	static const int Grid_rows = 3;                   ///< Default number of Rows in the 2-D Game Grid
	static const int Grid_cols = 3;                ///< Default number of Columns in the 2-D Game Grid

private:
    
    char** gameBoard;
	int m_nGridRows;                                           ///< Number of rows in Game Grid; initialized to default
	int m_nGridColumns;                                        ///< Number of columns in Game Grid; initialized to default                                        ///< Column number target boat positioned in

public:
	/// Default constructor for TicTacToe object.
	/// @details calls initializeGrid to initialize 2-dimensional game grid. Initializes member variables in
	///          initializer list.
	TicTacToe();

	/// Game Loop; plays a complete game.
	/// @return void
	/// @details positions target boat randomly, allows users to launch topedoes, reports results.
	///          Continues looping until target hit (victory) or all torpedoes expended (game over, loss).
	void play();


private:
	/// Initialize two dimensinal playing grid to contain all "wave" characters (~).
	/// @return void
	void initializeGrid();

	
	void displayGrid();

	/// Queries the user for the grid location (row,column) at which to fire a torpedo;
	/// updates the game grid with torpedo location and updates the number of torpedoes
	/// remaining.

  // bool checkUserInput();
    
    std::tuple<int, int> cpuPlay();
    std::tuple<int, int> promptForGridCoord();
    int getUserRow();
    
    int getUserColumn();
    
    bool checkForWinner();
    bool checkForDraw();
    
};

