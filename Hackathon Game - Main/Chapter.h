//creating chapter class
#ifndef CHAPTER_H
#define CHAPTER_H

#include <iostream>
using namespace std;

// data structure: Chapter for storyline
class Chapter
{
  private:
    int numChapter; 	
    string introText;
    
  public:
  	//Assesor
    void setNumChapter(int chapter)
      { numChapter = chapter;}
    void setText(string text)
      { introText = text;}
    //Mutator
    int getNumChapter() const
      { return numChapter;}
    string getText() const
      { return introText;}
};


#endif
