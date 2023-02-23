/*
 * Author:      Dr. Mark E. Lehr
 * Date  :      September 4th, 2020
 * Purpose:     Card Class specification comparison
 * 
 */

#ifndef CARD_H
#define CARD_H

    #include <string>
    using namespace std;

    class Card{
        private:
            static const int MAXCRDS=52;
            static const int MINCRDS=0;
            int    number;
            int    faceVal;
            string suit;
            string name;
            string picture;
            void   setFace();
            void   setSuit();
            void   setName();
            void   setPict();
        public:
            Card(int);
            int    getNumr(){return number;}
            int    getFace(){return faceVal;}
            string getSuit(){return suit;}
            string getName(){return name;}
            string getPict(){return picture;}
            string toString();
    };

#endif /* CARD_H */

