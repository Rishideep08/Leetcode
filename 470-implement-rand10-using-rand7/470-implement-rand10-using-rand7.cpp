// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int func(){
        int x= (rand7()-1)%7+(rand7());
        if(x<=40){
            return (x-1) % 10 + 1;
        }
        return func();
    }
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
        // return func();
    }
};