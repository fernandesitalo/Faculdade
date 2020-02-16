#ifndef PAIR_H
#define PAIR_H

namespace my{
class pair{
public:
    int first; // linha __ Y
    int second; // coluna __ X

public:
   pair(int first, int second){
        this->first = first;
        this->second = second;
   }
   pair()
   { first = second = 0; }

   bool operator ==(pair A)
   { return (first == A.first && second == A.second); }

   bool operator >(pair A){
       if(second == A.second)
           return first > A.first;
       return second > A.second;
   }

   bool operator <(pair A){
       if(second == A.second)
           return first < A.first;
       return second < A.second;
   }
};
}
#endif // PAIR_H
