#ifndef timer_h
#define timer_h
#define TRUE 1
/*
I googled how to make a timer in C++. Followed the example of this website.
https://www.codespeedy.com/cpp-program-to-create-a-stopwatch/
Made some adjustments to make it work for my game.
Examples of changes I made. 
1. Formulated it into a class
2. only wanted to display the count up. 
3. make it work that when I press a button the timer will begin
4. Timer will stop when last Rock was destroyed. 
*/

class Timer
{
protected:
	int HH = 0;
	int MM = 0;
	int SS = 0;
public:
	void timer();
};


#endif /* timer_h */
