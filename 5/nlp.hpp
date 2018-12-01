#include <fstream>

class Perceptron
{
	private:
	  Perceptron ( const Perceptron & );
	  Perceptron & operator= ( const Perceptron & );
	
	  int n_layers;
	  int* n_units;
	  double **units;
	  double ***weights;
	public:
	  Perceptron ( int nof, ... );
	
	  Perceptron ( std::fstream & file );
	  
	
	
	  double sigmoid ( double x );
	
	
	  double* operator() ( double image [] );
	
	  void learning ( double image [], double q, double prev_q );
	
	  void learning ( double image [], double y[] );
	
	  ~Perceptron();
	
	  void save ( std::fstream & out );
};