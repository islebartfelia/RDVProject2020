#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

 
std::vector< std::vector<float> > read(std::string Filename , std::string w){ 

	std:: ifstream file(Filename.c_str());	
	std::vector< std::vector<float> > coord; 
	std::vector<float> p;   
	std:: string line;  
	
	
	if(file){ 
	
	    while(file >> line) { 
	    
		      while(line == w){ 
		      
		     	  file >> line; 
		       	  p.push_back(atof(line.c_str())); 
		          file>> line; 
			   	  p.push_back( atof(line.c_str())); 
		          file >> line; 
				  file>> line; 
			   	  coord.push_back(p); 
		
		      } 
		     
		    } 
		    
	  } 
	else{ 
	   std:: cout << "File not found " << std::endl;  
	} 
	  return coord; 
}

int main() {
	
	std::vector< std::vector<float> > coord = read("diablo3_pose.obj" , "v");
}

