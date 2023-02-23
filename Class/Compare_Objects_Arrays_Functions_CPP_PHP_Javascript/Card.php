<?php
/*
 * Author:      Dr. Mark E. Lehr
 * Date  :      September 4th, 2019
 * Purpose:     Card Class specification comparison
 * 
 */

define('MAXCRDS',52);
define('MINCRDS',0);

class Card{
    
        private $number;
        private $faceVal;
        private $suit;
        private $name;
        private $picture;
        
        private function setFace(){
            $num=$this->number%13+1;
            if($num>10){$num=10;}
            else if($num==1){$num=11;}
            if($num>=2&&$num<=11){$this->faceVal=$num;}
            else{$this->faceVal=-2;}
        }
        
        private function setSuit(){
            if($this->number<13)     {$this->suit="Spades";}
            else if($this->number<26){$this->suit="Diamonds";}
            else if($this->number<39){$this->suit="Clubs";}
            else if($this->number<52){$this->suit="Hearts";}
            else                     {$this->suit="Bad Value";}
        }
        
        private function setName(){
            switch($this->number%13){
                case 0:  $this->name="Ace";  break;
                case 1:  $this->name="Two";  break;
                case 2:  $this->name="Three";break;
                case 3:  $this->name="Four"; break;
                case 4:  $this->name="Five"; break;
                case 5:  $this->name="Six";  break;
                case 6:  $this->name="Seven";break;
                case 7:  $this->name="Eight";break;
                case 8:  $this->name="Nine"; break;
                case 9:  $this->name="Ten";  break;
                case 10: $this->name="Jack"; break;
                case 11: $this->name="Queen";break;
                case 12: $this->name="King"; break;
                default: $this->name="Bad Value";
            }
        }
        
        private function setPict(){
            $this->picture="Cards/".$this->name.$this->suit.".jpg";
        }

        public function Card($number){
            if($number>=MINCRDS&&$number<MAXCRDS){
                $this->number=$number;
                $this->setFace();
                $this->setSuit();
                $this->setName();
                $this->setPict();
            }else{
                $this->number=-1;
                $this->faceVal=-1;
                $this->suit="none";
                $this->name="none";
                $this->picture="none";
            }
        }
        
        public function getNumr(){return $this->number;}
        public function getFace(){return $this->faceVal;}
        public function getSuit(){return $this->suit;}
        public function getName(){return $this->name;}
        public function getPict(){return $this->picture;}
        
        public function toString(){
            echo "<img src=".$this->picture." />";
            echo "<br/>Number = ".$this->number;
            echo "<br/>Name = ".$this->name;
            echo "<br/>Suit = ".$this->suit;
            echo "<br/>Face Value = ".$this->faceVal;
            echo "<br/><br/>";
        }
}
?>